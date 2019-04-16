#ifndef CDRON_HPP
# define CDRON_HPP

#include <iostream>
#include <string>
#include "Projectile.hpp"
#include "Unit.hpp"

class CDron : public Unit {
public:

	CDron(void);
	CDron(int x, int y);
	CDron(const CDron &in);
	virtual ~CDron(void);
	CDron &operator=(const CDron &in);

	virtual Projectile	*shoot();
	virtual void		move();
	
};

#endif