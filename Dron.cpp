
#include "Dron.hpp"

Dron::Dron(void) : Unit(100, 100, 1, 'D', "dron") {}
Dron::Dron(int x, int y) : Unit(x, y, 1, 'D', "dron") {}
Dron::Dron(const Dron &in) : Unit(in) {
	*this = in;
}
Dron::~Dron(void) {}
Dron &Dron::operator=(const Dron &in) {
	Unit::operator=(in);
	return *this;
}

Projectile	*Dron::shoot() {
	return new Projectile(this->getX() - 1, this->getY(), 1, '-', "proj", 15);
}

void		Dron::move() {
	this->setX(this->getX() - 1);
}