
#include "Spawner.hpp"

	int	_max_x;
	int	_max_y;

Spawner::Spawner(void) : _max_x(117), _max_y(38) , _max_en(50), _en(0) {}
Spawner::Spawner(int x, int y, int en) : _max_x(x), _max_y(y), _max_en(en), _en(0) {}
Spawner::Spawner(const Spawner &in) {
	*this = in;
}
Spawner::~Spawner(void) {}

Spawner &Spawner::operator=(const Spawner &in) {
	this->_max_x = in._max_x;
	this->_max_y = in._max_y;
	return *this;
}
int		Spawner::getEn() const {
	return this->_en;
}
void	Spawner::countEn(TileHeandler *in) {
	t_tilelist *copy = in->getTile();

	if (copy) {
		int count = 0;
		while(copy) {
			if (copy->_pice->getType() != "proj" && copy->_pice->getType() != "Hproj") {
				count += 1;
			}
			copy = copy->_next;
		}
		this->_en = count;
	}
}

TilePice		*Spawner::spawnDron(int x, int y) {
	Dron *p = new Dron(x, y);
	return (TilePice*)p;
}

TilePice		*Spawner::spawnCDron(int x, int y) {
	CDron *p = new CDron(x, y);
	return (TilePice*)p;
}

TilePice		*Spawner::spawnBDron(int x, int y) {
	BDron *p = new BDron(x, y);
	return (TilePice*)p;
}

void	Spawner::spawn(TileHeandler *in) {
	countEn(in);

	TilePice *(Spawner::*ptr[])(int , int) =
	{
		&Spawner::spawnDron,
		&Spawner::spawnCDron,
		&Spawner::spawnBDron
	};
 
	if (in->getCount() == 0) {
		this->_en = 0;
	}

	for (int enq = this->_en ; enq < this->_max_en; enq++) {
		in->push((this->*ptr[rand() % 3])(this->_max_x + rand() % 20, (rand() % this->_max_y) + 1));
	}
	this->_en = this->_max_en;
}
