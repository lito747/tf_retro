
#include "TileHeandler.hpp"
#include <fstream>
#include <stdio.h>
# include <unistd.h>

TileHeandler::TileHeandler(void) : _count(0), _tile(NULL) {}


TileHeandler::TileHeandler(const TileHeandler &obj) {
	this->_count = obj._count;
	
	t_tilelist 	*copy = NULL;
	t_tilelist	*input = obj._tile;

	if (input) {
		copy = new t_tilelist;
		copy->_next = NULL;
		copy->_pice = input->_pice;
		input = input->_next;

		while(input) {
			t_tilelist *tmp = new t_tilelist;
			tmp->_pice = input->_pice;
			copy->_next = tmp;
			tmp->_next = NULL;
			copy = copy->_next;
			input = input->_next;
		}
	}
	
	this->_tile = copy;
}



void			TileHeandler::movePices(size_t i) {

	t_tilelist *copy = this->_tile;

	while(copy) {
		if ((copy->_pice->getType() == "proj")  ){
			copy->_pice->move();
		} else if ( (copy->_pice->getType() == "Hproj")) {
			((HProjectile*)copy->_pice)->move();
		} else if (i % 10 >= 2) {
			copy->_pice->move();
		}
		copy = copy->_next;
	}
}

TileHeandler::~TileHeandler(void) {
	
	while(this->_tile) {
		t_tilelist *tmp = this->_tile;
		this->_tile = this->_tile->_next;
		delete tmp->_pice;
		delete tmp;
	}
}

void    TileHeandler::del(t_tilelist *lst) {
 t_tilelist *tmp = this->_tile;
 t_tilelist *prev;

 if (lst == this->_tile) {
  	tmp = tmp->_next;
  	delete this->_tile->_pice;
  	delete this->_tile;
  	this->_tile = tmp;
  	this->_count--;
  	return ;
 }
 while (tmp && tmp != lst) {
  	prev = tmp;
  	tmp = tmp->_next;
 }
 if (tmp) {
  	tmp = tmp->_next;
  	delete prev->_next->_pice;
  	delete prev->_next;
  	prev->_next = tmp;
  	this->_count--;
 }
}


TileHeandler &TileHeandler::operator=(const TileHeandler  &r) {
	this->_count = r._count;
	
	t_tilelist *copy = NULL;
	t_tilelist *input = r._tile;

	if (input) {
		copy = new t_tilelist;
		copy->_next = NULL;

		copy->_pice = input->_pice;
		input = input->_next;

		while(input) {
			t_tilelist *tmp = new t_tilelist;
			tmp->_pice = input->_pice;

			copy->_next = tmp;
			tmp->_next = NULL;
			copy = copy->_next;
			input = input->_next;
		}
	}

	this->_tile = copy;

	return *this;
}

bool	TileHeandler::xColision(int i) const {
	if (i <= 0 || i >= 120) {
		return true;
	}
	return false;
}

bool	TileHeandler::yColision(int i) const {
	if (i >= 38 || i <= 0) {
		return true;
	}
	return false;
}

int 	TileHeandler::len() const {
	t_tilelist *copy = this->_tile;
	int counter = 0;
	while (copy) {
		counter += 1;
		copy = copy->_next;
	}
	return counter;
}

void	TileHeandler::cleanColaid() {
	t_tilelist *copy = this->getTile();

	int flag;
	while (copy) {
		flag = 0;
		t_tilelist *tmp = copy->_next;


		if ((copy->_pice->getType() == "Hproj")) {

			while (tmp) {
				if (tmp->_pice->isColaid(copy->_pice->getX(), copy->_pice->getY())) {
					flag = 1;
					t_tilelist *tmp4 = tmp->_next;
					del(tmp);
					tmp = tmp4;
				} else {
					tmp = tmp->_next;
				}
			}
		}

		if (flag == 1) {
			t_tilelist *tmp2 = copy->_next;
			del(copy);
			copy = tmp2;
		} else if (
			xColision(copy->_pice->getX()) ||
			 yColision(copy->_pice->getY())) {
			t_tilelist *tmp3 = copy->_next;
			del(copy);
			copy = tmp3;
		 } else if (copy) {
			copy = copy->_next;
		}
	}
}

int		TileHeandler::getCount() const {
	return this->_count;
}

t_tilelist		*TileHeandler::getTile() const {
	return this->_tile;
}

int		TileHeandler::push(TilePice *obj) {

	if (this->_tile == NULL) {
		this->_tile = new t_tilelist;
		this->_tile->_pice = obj;
		this->_tile->_next = NULL;

		this->_count += 1;
		return  this->_count;
	}

	t_tilelist *copy = this->_tile;
	while(copy->_next)
		copy = copy->_next;

	t_tilelist *tmp = new t_tilelist;
	copy->_next = tmp;

	copy->_next->_pice = obj;
	copy->_next->_next = NULL;
	this->_count += 1;
	return this->_count;
}
