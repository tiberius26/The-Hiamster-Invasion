#ifndef HELLO_H
#define HELLO_H

typedef struct SoldatProps//Soldat struct
{
	int x;//x coordinate
	int y;//y coordinate
	int i; //counter to determine how much to move at the top and bottom of the screen
	bool left; //bool to determine movement direction (X asis)
	bool alive; //used to determine the state for the Soldat
	bool up; //used to determine Y movement
	bool movementcounter; //used to slow hiamsters down (makes them move every other frame)
	int Count; //tracks the number of Soldats
	u32 tid; //creates tile ID variable
	u32 pb;//creates pallet bank variable
	OBJ_ATTR *Sprite; //creates sprite bank variable
	
}SoldatProps;//end fo struct

typedef struct MusketeerProps //Musketeer struct
{
	int x;//x coordinate
	int y;//y coordinate
	int i;//counter to determine how much to move at the top and bottom of the screen
	bool left;//bool to determine movement direction (X asis)
	bool alive; //used to determine the state for the Muskateer
	bool up;//used to determine Y movement
	int Count;//tracks the number of Muskateers
	u32 tid;//creates tile ID variable
	u32 pb;//creates pallet bank variable
	OBJ_ATTR *Sprite;//creates sprite bank variable
	
}MusketeerProps;//end fo struct

typedef struct PrincessProps //Princess struct
{
	int x;//x coordinate
	int y;//y coordinate
	bool alive; //used to determine the state for the Princess
	u32 tid;//creates tile ID variable
	u32 pb;//creates pallet bank variable
	OBJ_ATTR *Sprite;//creates sprite bank variable
	
}PrincessProps;//end fo struct

typedef struct PowerupProps //Powerup struct
{
	int x;//x coordinate
	int y;//y coordinate
	bool alive; //used to determine the state for the Powerup
	u32 tid;//creates tile ID variable
	u32 pb;//creates pallet bank variable
	OBJ_ATTR *Sprite;//creates sprite bank variable
	
}PowerupProps;//end fo struct

#endif