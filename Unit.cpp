
#include "Unit.hpp"

Unit::Unit(void) : TilePice(100, 100, 1, '-', "proj") {} 
Unit::Unit(int x, int y, int spead, char des, const std::string type) : TilePice(x, y, spead, des, type) {}
Unit::Unit(const Unit &in) : TilePice(in) {
	*this = in;
}
Unit::~Unit(void) {}
Unit &Unit::operator=(const Unit &in) {
	TilePice::operator=(in);
	return *this;
}