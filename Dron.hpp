#ifndef DRON_HPP
# define DRON_HPP

#include <iostream>
#include <string>
#include "Projectile.hpp"
#include "Unit.hpp"

class Dron : public Unit {
public:

	Dron(void);
	Dron(int x, int y);
	Dron(const Dron &in);
	virtual ~Dron(void);
	Dron &operator=(const Dron &in);

	virtual Projectile	*shoot();
	virtual void		move();
};

#endif