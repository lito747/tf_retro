#ifndef UNIT_HPP
# define UNIT_HPP

#include <iostream>
#include <string>
#include "Projectile.hpp"
#include "TilePice.hpp"


class Unit : public TilePice {
public:
	Unit(void);
	Unit(int x, int y, int spead, char des, const std::string type);
	Unit(const Unit &in);
	virtual ~Unit(void);
	Unit &operator=(const Unit &in);

	virtual Projectile	*shoot() = 0;
};

#endif