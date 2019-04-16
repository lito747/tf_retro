#ifndef TILEHEANDLER_HPP
# define TILEHEANDLER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include "TilePice.hpp"
#include "HProjectile.hpp"
#include "Unit.hpp"
#include "unistd.h"

typedef struct _tilelist
{
	TilePice 			*_pice;
	struct _tilelist	*_next;
}				t_tilelist;

class	TileHeandler  {

private:

	int					_count;
	struct _tilelist	*_tile;

	bool				xColision(int i) const;
	bool				yColision(int i) const;
	int					len() const;
public:

		TileHeandler(void);
		TileHeandler(const TileHeandler &obj);
		virtual ~TileHeandler(void);
		TileHeandler &operator=(const TileHeandler  &r);

		void						cleanColaid();
		int							getCount() const;
		t_tilelist					*getTile() const;
		int							push(TilePice *obj);
		void						movePices(size_t i);
		void						del(t_tilelist *lst);
};

#endif