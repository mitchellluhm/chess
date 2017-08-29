#include <stdio.h>

class Piece
{
public:
	int x, y;
	bool active;
	
	int getX()
	{
		return x;
	}
	
	int getY()
	{
		return y;
	}

	bool getActive()
	{
		return active;
	}
	
	void setX(int xn)
	{
		x = xn;
	}
	
	void setY(int yn)
	{
		y = yn;
	}

	void setActive(bool an)
	{
		active = an;
	}

	virtual bool move(int xd, int yd)
	{ 
		return false; // parent move
	} 

	Piece() { }
	
};

class Pond : public Piece
{
public:

	Pond(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}
	
	bool move(int xd, int yd) 
	{
		if (xd == x && yd == y + 1) return true;
		else return false;
	}
};
	
class Knight : public Piece
{
public:
	Knight(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}

	bool move(int xd, int yd)
	{
		if ((xd == x + 1 || xd == x - 1) && (yd == y + 2 || yd == y - 2))
		{
			return true;
		}
		else if ((yd == y + 1 || yd == y - 1) && (xd == x + 2 || xd == x - 2))
		{
			return true;
		}
		else 
		{
			return false;
		}

	}
};

class Bishop : public Piece
{
public:
	Bishop(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}

	bool move(int xd, int yd)
	{
		int delta_x = xd - x;
		int delta_y = yd - y;

		if (delta_x != 0 && (delta_y == delta_x || delta_y == -1 * delta_x))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Rook : public Piece
{
public:
	Rook(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}

	bool move(int xd, int yd)
	{
		int delta_x = xd - x;
		int delta_y = yd - y;
		
		if (delta_x != delta_y && (delta_x == 0 || delta_y == 0))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
};

class Queen : public Piece
{
public:
	Queen(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}

	bool move(int xd, int yd)
	{
		int delta_x = xd - x;
		int delta_y = yd - y;
		
		if ( (delta_x != delta_y && (delta_x == 0 || delta_y == 0)) || 
			(delta_x != 0 && (delta_y == delta_x || delta_y == -1 * delta_x)) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class King : public Piece
{
public:
	King(int xi, int yi)
	{
		x = xi;
		y = yi;
		active = true;
	}

	bool move(int xd, int yd)
	{
		int delta_x = xd - x;
		int delta_y = yd - y;
		
		if ((delta_x == 1 || delta_x == -1) && (delta_y == 1 || delta_y == -1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
	//Piece *pc_ptr;
 	King k(9,0);
	//pc_ptr = &k;
	/* ex of piece array working */	
	Piece* arr[2];
	arr[0] = &k;

	printf("%d", arr[0]->getX());
	/* end example */
	// make two ararys int and piece
	

	return 0;
}
