#include "BDron.hpp"

BDron::BDron(void) : Unit(100, 100, 1, 'N', "dron") {}
BDron::BDron(int x, int y) : Unit(x, y, 1, 'N', "dron") {}
BDron::BDron(const BDron &in) : Unit(in) {
	*this = in;
}
BDron::~BDron(void) {}
BDron &BDron::operator=(const BDron &in) {
	Unit::operator=(in);
	return *this;
}

Projectile	*BDron::shoot() {
	return new Projectile(this->getX() - 1, this->getY(), 1, '-', "proj", 15);
}

void		BDron::move() {

	int i = rand() % 3;
	int k = rand() % 10;
	if (i == 0) {
		this->setX(this->getX() - 1);
	} else if (i == 1) {
		this->setX(this->getX() - 1);
		this->setY(this->getY() - 1);
	} else if (k >= 7) {
		this->setX(this->getX() - 1);
		this->setY(this->getY() - 3);
	} else {
		this->setX(this->getX() - 1);
		this->setY(this->getY() + 1);
	}
}