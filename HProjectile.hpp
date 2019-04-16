#ifndef HPROJECTILE_HPP
# define HPROJECTILE_HPP

#include <iostream>
#include <string>
#include "TilePice.hpp"
#include "Projectile.hpp"

class HProjectile : public Projectile {
public:
	HProjectile(void);
	HProjectile(int x, int y, int spead, char des, const std::string type, int dmg);
	HProjectile(const HProjectile &in);
	virtual ~HProjectile(void);
	HProjectile &operator=(const HProjectile &in);

	int					getDmg();
	virtual void		move();	
};

#endif