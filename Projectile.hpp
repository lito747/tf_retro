#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include <iostream>
#include <string>
#include "TilePice.hpp"

class Projectile : public TilePice {
private:

	int _dmg;
public:
	Projectile(void);
	Projectile(int x, int y, int spead, char des, const std::string type, int dmg);
	Projectile(const Projectile &in);
	virtual ~Projectile(void);
	Projectile &operator=(const Projectile &in);

	int					getDmg();
	virtual void		move();	
};

#endif