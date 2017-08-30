#include <stdio.h>

class Piece
{
public:
	int x, y;
	bool active;
	bool side; // side reprsents black vs white pieces
	
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

	Pond(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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
	Knight(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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
	Bishop(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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
	Rook(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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
	Queen(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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
	King(int xi, int yi, bool s)
	{
		x = xi;
		y = yi;
		active = true;
		side = s;
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

void init_pboard(Piece* pb[0][8])
{
	// declare pieces for side 1/true
	Pond p_0_1(0, 1, true); Pond p_1_1(1, 1, true); Pond p_2_1(2, 1, true);
	Pond p_3_1(3, 1, true); Pond p_4_1(4, 1, true); Pond p_5_1(5, 1, true);
	Pond p_6_1(6, 1, true); Pond p_7_1(7, 1, true);
	
	Knight k_0_1(1, 0, true); Knight k_1_1(6, 0, true);

	Rook r_0_1(0, 0, true); Rook r_1_1(7, 0, true);

	Bishop b_0_1(2, 0, true); Bishop b_1_1(5, 0, true);

	Queen queen_1(3, 0, true); King king_1(4, 0, true);

	// place pieces into piece board array
	pb[0][1] = &p_0_1; pb[1][1] = &p_1_1; pb[2][1] = &p_2_1; pb[3][1] = &p_3_1;
	pb[4][1] = &p_4_1; pb[5][1] = &p_5_1; pb[6][1] = &p_6_1; pb[7][1] = &p_7_1;
	pb[1][0] = &k_0_1; pb[6][0] = &k_1_1; pb[0][0] = &r_0_1; pb[7][0] = &r_1_1;
	




}

int main()
{
	//Piece *pc_ptr;
 	//King k(9,0);
	//pc_ptr = &k;
	/* ex of piece array working */	
	//Piece* arr[2];
	//arr[0] = &k;

	//printf("%d", arr[0]->getX());
	/* end example */
	// make two ararys int and piece
	Piece* pboard[8][8];
	init_pboard(pboard);
	printf("%d", pboard[0][0]->getX());

	return 0;
}



