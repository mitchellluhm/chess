#include <stdio.h>


typedef struct piece
{
	int active;
	int x;
	int y;

} piece;

typedef struct pond
{
	int a;

	piece pc;

} pond;


int main()
{
	pond p = {9, {1, 0, 0}};
	printf("%d %d %d %d", p.a, p.pc.active, p.pc.x, p.pc.y);
	
	return 0;
}
