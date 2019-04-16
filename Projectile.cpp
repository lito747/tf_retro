
#include "Projectile.hpp"

Projectile::Projectile(void) : TilePice(100, 100, 1, '-', "proj"), _dmg(1) {}
Projectile::Projectile(int x, int y, int spead=1, char des='-', const std::string type="proj", int dmg=10): TilePice(x, y, spead, des, type), _dmg(dmg) {}
Projectile::Projectile(const Projectile &in) : TilePice(in) {
	*this = in;
}
Projectile::~Projectile(void) {}

Projectile &Projectile::operator=(const Projectile &in) {
	TilePice::operator=(in);
	return *this;
}

void		Projectile::move() {
	this->setX(this->getX() - 1);
}