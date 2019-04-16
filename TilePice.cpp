
#include "TilePice.hpp"

TilePice::TilePice(void) : _x(100), _y(100), _spead(), _des('#'), _type("NAN") {}
TilePice::TilePice(int x, int y, int spead, char des, const std::string type) : _x(x), _y(y),_spead(spead), _des(des), _type(type) {}
TilePice::TilePice(const TilePice &in) {
	*this = in;
}
TilePice::~TilePice(void) {}
TilePice &TilePice::operator=(const TilePice &in) {
	this->_x = in._x;
	this->_y = in._y;
	this->_spead = in._spead;
	this->_des = in._des;
	this->_type = in._type;
	return *this;
}

bool				TilePice::isColaid(int x, int y) {
	if (this->_x == x && this->_y == y)
		return true;

	return false;
}

int					TilePice::getX() const {
	return this->_x;
}
int					TilePice::getY() const {
	return this->_y;
}
int					TilePice::getSpead() const {
	return this->_spead;
}
char				TilePice::getDes() const {
	return this->_des;
}
std::string	TilePice::getType() const {
	return this->_type;
}

void				TilePice::setX(int in) {
	this->_x = in;
}
void				TilePice::setY(int in) {
	this->_y = in;
}
void				TilePice::setSpead(int in) {
	this->_spead = in;
}
void				TilePice::setDes(char des) {
	this->_des = des;
}
void				TilePice::setType(const std::string &in) {
	this->_type = in;
}