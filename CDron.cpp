#include "CDron.hpp"

CDron::CDron(void) : Unit(100, 100, 1, '#', "dron") {}
CDron::CDron(int x, int y) : Unit(x, y, 1, '#', "dron") {}
CDron::CDron(const CDron &in) : Unit(in) {
	*this = in;
}
CDron::~CDron(void) {}
CDron &CDron::operator=(const CDron &in) {
	Unit::operator=(in);
	return *this;
}

Projectile	*CDron::shoot() {
	return new Projectile(this->getX() - 1, this->getY(), 1, '-', "proj", 15);
}

void		CDron::move() {
	int i = rand() % 3;
	if (i == 0) {
		this->setX(this->getX() - 1);
	} else if (i == 1) {
		this->setX(this->getX() - 1);
		this->setY(this->getY() - 1);
	} else {
		this->setX(this->getX() - 1);
		this->setY(this->getY() + 1);
	}
}