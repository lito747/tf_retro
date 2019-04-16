/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryabchu <oryabchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:11:30 by oryabchu          #+#    #+#             */
/*   Updated: 2019/04/07 17:41:11 by oryabchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_HPP
# define HERO_HPP

# include <ncurses.h>
# include <string>
# include <iostream>
# include <unistd.h>
# include "Hero.hpp"
# include "Projectile.hpp"
# include "HProjectile.hpp"
# include "Unit.hpp"
# include "TileHeandler.hpp"

class Hero : public TilePice{
    public:
        Hero(void);
    	Hero(int x, int y);
        Hero(Hero const& src);
        virtual ~Hero(void);

        Hero    &operator= (Hero const& src);

        int     getScore() const;
        int     getHp() const;
        void    setHp(int hp);

	    virtual void		move();
        virtual Projectile	*shoot();
        bool		        checkColision(TileHeandler  *tile);
        void                takeDamage(TilePice *pice);
        void                addScore(int score);
        void                setScore(int score);
    private:
        int     _score;
        int     _hp;
};

#endif