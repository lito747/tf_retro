/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:19:45 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/07 18:39:26 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <ncurses.h>
# include <string>
# include <iostream>
# include <unistd.h>
# include "Hero.hpp"
# include "TileHeandler.hpp"
# include "Spawner.hpp"
# include "CDron.hpp"

class Screen {
    public:
        Screen(void);
        Screen(Screen const& src);
        ~Screen(void);

        Screen  &operator= (Screen const& src);

        void    startGame(void);
        void    printInfo(void);
        void    initWindow(void);
        void    checkInitscr(void);
        void    initColors(void);
        void    gameOverPrint(void);
        void    handleButton(TileHeandler *tile);
        void    drawUnit(TilePice* tilePice);
    private: 
        WINDOW		            *_window;
        int			            _winMaxW;
		int			            _winMaxH;
        int                     _maxW;
        int                     _maxH;
        time_t                  _game_time;
        Hero                    *_hero;
        static      time_t      _time;
        int                     _stop;
        int                     _button;
        size_t                  _timeStamp;
        size_t                  _timeEvent;
};
#endif
