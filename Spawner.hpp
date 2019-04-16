#ifndef SPAWNER_HPP
# define SPAWNER_HPP

#include <iostream>
#include <string>

#include "TileHeandler.hpp"
#include "Dron.hpp"
#include "CDron.hpp"
#include "TilePice.hpp"
#include "BDron.hpp"

class Spawner {
private:

	int	_max_x;
	int	_max_y;
	int _max_en;
	int _en;

	void			countEn(TileHeandler *in);
	TilePice		*spawnDron(int x, int y);
	TilePice		*spawnCDron(int x, int y);
	TilePice		*spawnBDron(int x, int y);
public:
	Spawner(void);
	Spawner(int x, int y, int en);
	Spawner(const Spawner &in);
	virtual ~Spawner(void);
	Spawner &operator=(const Spawner &in);

	int		getEn() const;
	void	spawn(TileHeandler *in);

};

#endif