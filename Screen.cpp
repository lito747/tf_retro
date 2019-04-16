/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:19:57 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/07 20:51:28 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

time_t 		Screen::_time = time(0);

Screen::Screen(void) {
    this->_winMaxW = 0;
    this->_winMaxH = 0;
    this->_maxW = 120;
	this->_maxH = 40;
    this->_stop = 0;
    this->_button = -1;
    this->_hero = new Hero(2, this->_maxH / 2);
    this->initWindow();
    return ;
}

Screen::Screen(Screen const & src) {
    *this = src;
}

Screen::~Screen(void) {
    std::cout << "GAME OVER" 
        << std::endl;
    delwin(this->_window);
    endwin();
}

Screen &Screen::operator= (Screen const &rhs) {
    (void) rhs;
    return (*this);
}
void	Screen::checkInitscr(void) {
	
	if (COLS < 120 || LINES < 40) {
		endwin();
		std::cout << "Error: Too small window." << std::endl;
		exit(0);
	}
}

void		Screen::initColors(void) {
	
	int		n = 1;

	start_color();
	if (has_colors()) {
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(4, COLOR_YELLOW, COLOR_BLACK);
		init_pair(5, COLOR_WHITE, COLOR_BLACK);
		init_pair(6, COLOR_RED, COLOR_BLACK);
	}
	color_set(n, NULL);
}
void		Screen::handleButton(TileHeandler *tile) {
    this->_button = getch();
    switch ((this->_button)) {
        case 27 : 
            this->_stop = 1;
            break ;
        case KEY_UP :
            if (this->_hero->getY() > 1)
                this->_hero->setY(this->_hero->getY() - 1);
            break ;
        case KEY_DOWN : 
            if (this->_hero->getY() < this->_maxH - 2)
                this->_hero->setY(this->_hero->getY() + 1);
            break ;
        case KEY_LEFT : 
            if (this->_hero->getX() > 1)
                this->_hero->setX(this->_hero->getX() - 1);
            break ;
        case KEY_RIGHT : 
            if (this->_hero->getX() < this->_maxW - 2)
                this->_hero->setX(this->_hero->getX() + 1);
            break ;
        case 32 :
            if (tile) {
                tile->push(this->_hero->shoot());
            }
            break ;
    }
}


void    Screen::initWindow(void) {
    initscr();
	this->checkInitscr();

	int shiftx = (COLS - this->_maxW) / 2;
	int shifty = (LINES - this->_maxH) / 2;
	
	this->_window = newwin(this->_maxH, this->_maxW, shifty, shiftx);

	curs_set(0);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	timeout(50);
    this->initColors();

	wrefresh(this->_window);
}



void    Screen::startGame(void) {

    while(!this->_stop) {
            TileHeandler *tile = new TileHeandler;
            Spawner spa(this->_maxW, this->_maxH, 50);
            this->_timeEvent = clock();
            while(this->_hero->getHp() != 0 && !this->_stop){

                this->_hero->addScore(1);
                spa.spawn(tile);
                this->_timeStamp = clock();
                this->printInfo();
                werase(this->_window);
                box(this->_window, 0, 0);
                this->printInfo();
                this->drawUnit(this->_hero);

                t_tilelist *tmp = tile->getTile();

                while (tmp) {
                    this->drawUnit(tmp->_pice);
                    tmp = tmp->_next;
                }
                this->handleButton(tile);
               
                 t_tilelist *tmp2 = tile->getTile();

                if (this->_timeStamp % 100 >= 92) {
                    while(tmp2) {
                        if (tmp2->_pice->getType() != "proj" && tmp2->_pice->getType() != "Hproj")
                            tile->push(((Unit*)tmp2->_pice)->shoot());
                        tmp2 = tmp2->_next;
                    }
                }
                tile->movePices(this->_timeStamp);
                tile->cleanColaid();
                this->_hero->checkColision(tile);
                wrefresh(this->_window);
                refresh();
                usleep(500);
            }
        this->printInfo();
        this->gameOverPrint();
        wrefresh(this->_window);
        refresh();
        delete tile;
    }
}

void    Screen::drawUnit(TilePice* tilePice) {
    mvwaddch(this->_window, tilePice->getY(), tilePice->getX(), tilePice->getDes() | A_BOLD | COLOR_PAIR(2));
}

void     Screen::gameOverPrint(void) {
        wattron(this->_window, COLOR_PAIR(6));
        mvwaddstr(this->_window, 15, 55, "GAME OVER");
        wattron(this->_window, COLOR_PAIR(1));
        mvwaddstr(this->_window, 25, 10, "Press ESC to leave the game");
        wattron(this->_window, COLOR_PAIR(5));
        mvwaddstr(this->_window, 25, 58, "OR");
        wattron(this->_window, COLOR_PAIR(2));
        mvwaddstr(this->_window, 25, 90, "Press SPACE to continue");
        wattron(this->_window, COLOR_PAIR(5));

        int ch = getch();
        if (ch == 27) {
            this->_stop = 1;
        }
        if (ch == 32) {
            this->_hero->setHp(100);
            this->_hero->setX(2);
            this->_hero->setY(this->_maxH / 2);
            this->_game_time = time(0);
            this->_hero->setScore(0);
        }
        wrefresh(this->_window);
        refresh();
}
void    Screen::printInfo(void) {
	
    static struct tm	*l_time;
	time_t				t;

	t = time(0);
	t = t - this->_time;
	l_time = localtime(&t);

	this->_game_time++;
	wattron(this->_window, COLOR_PAIR(1));
	mvwprintw(this->_window, 0, 1, "Time: %d : %d;", l_time->tm_min, l_time->tm_sec);
	wattron(this->_window, COLOR_PAIR(5));
	mvwprintw(this->_window, 0, 30, "Score: %d", this->_hero->getScore());
	wattron(this->_window, COLOR_PAIR(2));
	mvwprintw(this->_window, 0, 70, "Lifes: %d", this->_hero->getHp());
	wattron(this->_window, COLOR_PAIR(4));
}