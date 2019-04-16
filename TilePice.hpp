#ifndef TILEPICE_CPP
# define TILEPICE_CPP

#include <iostream>
#include <string>

class TilePice {
private:

	int 			_x;
	int 			_y;
	int				_spead;
	char 			_des;
	std::string 	_type;
public:

	TilePice(void);
	TilePice(int x, int y, int spead, char des, const std::string type);
	TilePice(const TilePice &in);
	virtual ~TilePice(void);
	TilePice &operator=(const TilePice &in);

	bool				isColaid(int x, int y);

	int					getX() const;
	int					getY() const;
	int					getSpead() const;
	char				getDes() const;
	std::string			getType() const;

	void				setX(int in);
	void				setY(int in);
	void				setSpead(int in);
	void				setDes(char in);
	void				setType(const std::string &in);

	virtual void		move() = 0;
};

#endif