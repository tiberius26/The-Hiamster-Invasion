#ifndef SOLDATPROPS_H
#define SOLDATPROPS_H

typedef struct SoldatProps
{
	int x;
	int y;
	bool left;
	bool alive;
	bool up;
	OBJ_ATTR * Sprite;
	u32 tid, pb;
	
}SoldatProps;
#endif