#include <iostream>
#include <typeinfo>
using namespace std;

class Piece
{
public:
	int* x;
	int* y;
	bool active;
	bool side; // side reprsents black vs white pieces
	const char* ch;
	
	int getX()
	{
		return *x;
	}
	
	int getY()
	{
		return *y;
	}

	bool getActive()
	{
		return active;
	}

	const char* getCh()
	{
		return ch;
	}
	
	void setX(int xn)
	{
		x = &xn;
	}
	
	void setY(int yn)
	{
		y = &yn;
	}

	void setActive(bool an)
	{
		active = an;
	}

	/*void setCh(const char c)
	{
		ch = c;
	}*/

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
		//cout << xi << endl;
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "P";
	}

/*	
	bool move(int xd, int yd) 
	{
		if (xd == x && yd == y + 1) return true;
		else return false;
	}
*/
};
	
class Knight : public Piece
{
public:

	Knight(int xi, int yi, bool s)
	{
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "K";
	}

/*
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
*/
};

class Bishop : public Piece
{
public:
	Bishop(int xi, int yi, bool s)
	{
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "B";
	}

/*
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
*/
};

class Rook : public Piece
{
public:
	Rook(int xi, int yi, bool s)
	{
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "R";
	}

/*
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
*/
};

class Queen : public Piece
{
public:
	Queen(int xi, int yi, bool s)
	{
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "Q";
	}

/*
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
*/
};

class King : public Piece
{
public:
	King(int xi, int yi, bool s)
	{
		x = &xi;
		y = &yi;
		active = true;
		side = s;
		ch = "X";
	}

/*
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
*/
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

	//Piece* test = &k_0_1;
	//cout << b_0_1.getCh() << endl;
	// place pieces into piece board array
	pb[0][1] = &p_0_1; pb[1][1] = &p_1_1; pb[2][1] = &p_2_1; pb[3][1] = &p_3_1;
	pb[4][1] = &p_4_1; pb[5][1] = &p_5_1; pb[6][1] = &p_6_1; pb[7][1] = &p_7_1;
	pb[1][0] = &k_0_1; pb[6][0] = &k_1_1; pb[0][0] = &r_0_1; pb[7][0] = &r_1_1;
	pb[2][0] = &b_0_1; pb[5][0] = &b_1_1; 
	pb[3][0] = &queen_1; pb[4][0] = &king_1;

	/*
	// declare pieces for side 0/false
	Pond p_0_0(0, 6, true); Pond p_1_0(1, 6, true); Pond p_2_0(2, 6, true);
	Pond p_3_0(3, 6, true); Pond p_4_0(4, 6, true); Pond p_5_0(5, 6, true);
	Pond p_6_0(6, 6, true); Pond p_7_0(7, 6, true);
	Knight k_0_0(1, 7, true); Knight k_1_0(6, 7, true);
	Rook r_0_0(0, 7, true); Rook r_1_0(7, 7, true);
	Bishop b_0_0(2, 7, true); Bishop b_1_0(5, 7, true);
	Queen queen_0(3, 7, true); King king_0(4, 7, true);

	// place pieces into piece board array
	pb[0][6] = &p_0_0; pb[1][6] = &p_1_0; pb[2][6] = &p_2_0; pb[3][6] = &p_3_0;
	pb[4][6] = &p_4_0; pb[5][6] = &p_5_0; pb[6][6] = &p_6_0; pb[7][6] = &p_7_0;
	pb[1][7] = &k_0_0; pb[6][7] = &k_1_0; pb[0][7] = &r_0_0; pb[7][7] = &r_1_0;
	pb[2][7] = &b_0_0; pb[5][7] = &b_1_0; 
	pb[3][7] = &queen_0; pb[4][7] = &king_0;
	*/

	for (int i = 0; i < 8; i++)
		cout << "LOOP " << pb[i][0]->getCh() << endl;
}

void init_ploc(int pl[0][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i < 2 || i > 5) pl[i][j] = 1;
			else pl[i][j] = 0;
		}
	}
}

void print_ploc(int pl[0][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << pl[i][j] << flush;
		}
		cout << endl;
	}

}

void print_chars(Piece* pb[0][8], int pl[0][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//printf("i: %d j: %d", i, j);
			if (1 == pl[i][j]) cout << pb[i][j]->getCh() << " " << flush;
			else cout << "0 " << flush;
		}
		cout << endl;
	}
}

int main(int argc, const char* argv[])
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
	//int ploc[8][8]; // 0 indicates no piece there - 1 indicates there is piece
	//init_ploc(ploc);
	//print_ploc(ploc);

	//print_chars(pboard, ploc);
	cout << pboard[0][1]->getX() << endl;
	cout << pboard[1][1]->getX() << endl;
	cout << pboard[2][1]->getX() << endl;
	cout << pboard[3][1]->getX() << endl;
	
	/*

	Pond p_0_1(0, 1, true); Pond p_1_1(1, 1, true); Pond p_2_1(2, 1, true);
	Pond p_3_1(3, 1, true); Pond p_4_1(4, 1, true); Pond p_5_1(5, 1, true);
	Pond p_6_1(6, 1, true); Pond p_7_1(7, 1, true);
	Knight k_0_1(1, 0, true); Knight k_1_1(6, 0, true);
	Rook r_0_1(0, 0, true); Rook r_1_1(7, 0, true);
	Bishop b_0_1(2, 0, true); Bishop b_1_1(5, 0, true);
	Queen queen_1(3, 0, true); King king_1(4, 0, true);
	
	Piece* p1;
	Piece* p2;
	p1 = &k_0_1; 
	p2 = &k_1_1;

	cout << typeid(p1).name() << p2->getCh() << endl;
	
	*/	


	return 0;
}



