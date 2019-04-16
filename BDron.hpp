#ifndef BDRON_HPP
# define BDRON_HPP

#include <iostream>
#include <string>
#include "Projectile.hpp"
#include "Unit.hpp"

class BDron : public Unit {
public:

	BDron(void);
	BDron(int x, int y);
	BDron(const BDron &in);
	virtual ~BDron(void);
	BDron &operator=(const BDron &in);

	virtual Projectile	*shoot();
	virtual void		move();
	
};

#endif