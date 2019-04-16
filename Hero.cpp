/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:15:35 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/07 20:26:21 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.hpp"

Hero::Hero(void) : TilePice(50, 0, 2, 'H', "Hero"),  _hp(100) {}
Hero::Hero(int x, int y) : TilePice(x, y, 2, 'H', "Hero"), _hp(100) {}

Hero::Hero(Hero const & src) {
    *this = src;
}

Hero::~Hero(void) {
    std::cout << "Hero dead" 
        << std::endl;
}

Hero    &Hero::operator= (Hero const &rhs) {
    (void) rhs;
    return (*this);
}

int     Hero::getHp() const {
	return this->_hp;
}

int     Hero::getScore() const {
	return this->_score;
}

void     Hero::setScore(int score) {
     this->_score = score;
}

void     Hero::setHp(int hp) {
	 this->_hp = hp;
}

void     Hero::addScore(int score) {
     this->_score += score;
}

void	Hero::move() {
	this->setX(this->getX() + 1);
}

Projectile	*Hero::shoot() {
    HProjectile *tmp = new HProjectile(this->getX() + 1, this->getY(), 1, '=', "Hproj", 1000);
	return (Projectile*)tmp;
}
void    Hero::takeDamage(TilePice *pice) {
    if (!std::strcmp(pice->getType().c_str(), "proj")){
        if (this->getHp() - 20 < 0) {
            this->setHp(0);
        } else {
            this->setHp(this->getHp() - 20);
        }
    } else {
        this->setHp(0);
    }
}

bool    Hero::checkColision(TileHeandler  *tile) {
    t_tilelist *copy = tile->getTile();

	while (copy) {
		int flag = 0;
        if (copy->_pice->isColaid(this->getX(), this->getY())) {
            flag = 1;
            this->takeDamage(copy->_pice);
        } else {
            copy = copy->_next;
        }
        if (flag == 1) {
            return true;
		} else if (copy) {
			copy = copy->_next;
        }
	}
    return false;
}