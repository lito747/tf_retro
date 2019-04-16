#include "HProjectile.hpp"

HProjectile::HProjectile(void) : Projectile(100, 100, 1, '-', "Hproj", 1) {}
HProjectile::HProjectile(int x, int y, int spead=1, char des='-', const std::string type="Hproj", int dmg=10): Projectile(x, y, spead, des, type, dmg) {}
HProjectile::HProjectile(const HProjectile &in) : Projectile(in) {
	*this = in;
}
HProjectile::~HProjectile(void) {}

HProjectile &HProjectile::operator=(const HProjectile &in) {
	Projectile::operator=(in);
	return *this;
}

void		HProjectile::move() {
	this->setX(this->getX() + 1);
}