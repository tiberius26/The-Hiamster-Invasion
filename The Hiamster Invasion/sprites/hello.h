#ifndef HELLO_H
#define HELLO_H

typedef struct SoldatProps
{
	int x;
	int y;
	int i;
	bool left;
	bool alive;
	bool up;
	int Count;
	u32 tid;
	u32 pb;
	bool movementcounter;
	OBJ_ATTR *Sprite;
	
}SoldatProps;

typedef struct PrincessProps
{
	int x;
	int y;
	bool alive;
	u32 tid;
	u32 pb;
	OBJ_ATTR *Sprite;
	
}PrincessProps;

#endif