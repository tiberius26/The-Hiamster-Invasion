//
//! \file hello_demo.c
//!   Screen-entry text demo
//! \date 20060228 - 20080416
//! \author cearn
//
// === NOTES ===
#include "string.h"
#include <stdio.h>
#include <tonc.h>
#include <time.h>
#include <stdlib.h>
#include "Untitled.h"
#include "brin.h"
#include "Bob.h"
#include "goodBG.h"
#include "MenuBG.h"
#include "Roof.h"
#include "Lab.h"
#include "Garden.h"
#include "bullet.h"
#include "BulletProps.h"
#include "Soldat.h"
#include "Princess.h"
#include "hello.h"
#include "GameOverBG.h"


#define NUMBER_OF_H 100

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;
int Game_State;
int Menu_State;
int Pause_State;
int x, y;
int bulletNumber;
int place;
int size;
int Level;
int i;
int r; //r for all random values
int r2;
int Difficulty;
int DifficultyCooldown; //timmer
int DeletionCounter;
bool movementcounter;
int killcounter;
bool killonce;

//int EnemyCounter;
int nextsoldat;
int life;
int score;
int EnemyCooldown1;
int PrincessCounter;
bool lookLeft;
char ScoreText[50];
u32 tid, pb;
OBJ_ATTR *Bob;
OBJ_ATTR *BobL;
OBJ_ATTR *Bullet;
BulletProps bullet;
SoldatProps Soldat[NUMBER_OF_H];
PrincessProps Princess[2];


void Start();
void Level_1();
void Level_2();
void Level_3();
void Level_4();
void LoadLevel_1();
void LoadLevel_2();
void LoadLevel_3();
void LoadLevel_4();
void initializeSoldat();
void SpawnEnemy();
void Level_1();
void SpawnEnemy();
void init();
void menu();
void pause();
void reset();
void GameOver();
void SpawnPrincess();
void KillHiamsters();
void CheckKills();

int main()
{
	srand(time(NULL));
	
	memcpy(pal_bg_mem, MenuBGPal, MenuBGPalLen);
	memcpy(&tile_mem[2][0], MenuBGTiles, MenuBGTilesLen);
	memcpy(&se_mem[28][0], MenuBGMap, MenuBGMapLen);

	
	memcpy(&tile_mem[4][0], BobTiles, BobTilesLen);
	memcpy(pal_obj_mem, BobPal, BobPalLen);
	
	
	memcpy(&tile_mem[4][9], SoldatTiles, SoldatTilesLen);
	memcpy(pal_obj_mem, SoldatPal, SoldatPalLen);
	
	
	
	memcpy(&tile_mem[4][4], bulletTiles, bulletTilesLen);
	memcpy(pal_obj_mem, bulletPal, bulletPalLen);
	
	memcpy(&tile_mem[4][14], PrincessTiles, PrincessTilesLen);
	memcpy(pal_obj_mem, PrincessPal, PrincessPalLen);
	
	oam_init(obj_buffer, 128);
	
	REG_BG2CNT= BG_CBB(2) | BG_SBB(28) | BG_4BPP | BG_REG_32x32;
	
	init();
	
	while (1){
		switch(Game_State){
			case 0://menu state
				menu();
			break;
			
			case 1://game play
				//Start();
				LoadLevel_1();
				Level_1();
			break;
			case 2:
				pause();
			break;
			case 3:
				GameOver();
			break;
			case 4:
				LoadLevel_2();
				Level_2();
			break;
			case 5:
				LoadLevel_3();
				Level_3();
			break;
			case 6:
				LoadLevel_4();
				Level_4();
			break;
			
		}
	}
	return 0;
}


void init() 
	{
	x= 116;
	y= 77;
	EnemyCooldown1 = 5;
	Game_State = 0;
	Menu_State = 0;
	nextsoldat = 0;
	score = 0;
	Level = 1;
	life = 3;
	tid= 0;
	killcounter = 0;
	killonce = false;
	pb= 0;        // tile id, pal-bank
	lookLeft = false;
	DeletionCounter = 0;
    Bob= &obj_buffer[0];
	}
	
void LoadLevel_1()
{
		//spawnrate
		//spawntype
		memcpy(pal_bg_mem, goodBGPal, goodBGPalLen);
		memcpy(&tile_mem[1][0], goodBGTiles, goodBGTilesLen);
		memcpy(&se_mem[30][0], goodBGMap, goodBGMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;

}
void LoadLevel_2()
{		
		memcpy(pal_bg_mem, GardenPal, GardenPalLen);
		memcpy(&tile_mem[1][0], GardenTiles, GardenTilesLen);
		memcpy(&se_mem[30][0], GardenMap, GardenMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;

}
void LoadLevel_3()
{

		memcpy(pal_bg_mem, LabPal, LabPalLen);
		memcpy(&tile_mem[1][0], LabTiles, LabTilesLen);
		memcpy(&se_mem[30][0], LabMap, LabMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;
}
void LoadLevel_4()
{

		memcpy(pal_bg_mem, RoofPal, RoofPalLen);
		memcpy(&tile_mem[1][0], RoofTiles, RoofTilesLen);
		memcpy(&se_mem[30][0], RoofMap, RoofMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;
}

void initializeSoldat()
{
	int k;
	
	for (k = 0; k <= NUMBER_OF_H; k++)
	{
		Soldat[k].Count = 0;
		Soldat[k].tid = 9;
		Soldat[k].pb = 0;
		
		Soldat[k].Sprite= &obj_buffer[2+k];
		
		obj_set_attr(Soldat[k].Sprite, 
		ATTR0_SQUARE,                // Square, regular sprite
		ATTR1_SIZE_8,                    // 64x64p, 
		ATTR2_PALBANK(Soldat[k].pb) | Soldat[k].tid);
		
		
		Soldat[k].alive = false;
		
		Soldat[k].x= 0;
		Soldat[k].y= -8;	
		
		obj_set_pos(Soldat[k].Sprite, Soldat[k].x, Soldat[k].y);
	}
}
void SpawnEnemy()
{
	r2 = rand()%2+ Difficulty;
	if (EnemyCooldown1 < (1+r2))
	{
		if (Soldat[nextsoldat].alive == false)
		{
			if (r == 1)
			{
				
				Soldat[nextsoldat].x = 0;
				Soldat[nextsoldat].y = 0;
				Soldat[nextsoldat].alive = true;
				Soldat[nextsoldat].left = false;
				Soldat[nextsoldat].up = false;
				Soldat[nextsoldat].movementcounter = true;
				obj_set_pos(Soldat[nextsoldat].Sprite, Soldat[nextsoldat].x, Soldat[nextsoldat].y);
			
			}
			else 
			{
				Soldat[nextsoldat].x = 232;
				Soldat[nextsoldat].y = 152;
				Soldat[nextsoldat].alive = true;
				Soldat[nextsoldat].left = true;
				Soldat[nextsoldat].up = true;
				Soldat[nextsoldat].movementcounter = true;
				obj_set_pos(Soldat[nextsoldat].Sprite, Soldat[nextsoldat].x, Soldat[nextsoldat].y);
			}
			nextsoldat++;
			if (nextsoldat >= NUMBER_OF_H)
			{
				nextsoldat = 0;
			}
			
		}
		EnemyCooldown1 = 45;
		DifficultyCooldown = 1000;

	}
	else
	{
		EnemyCooldown1--;
		if (DifficultyCooldown <= 0)
		{
		Difficulty++;
		}
		else{DifficultyCooldown--;}
	}
}
void SpawnPrincess()
{
	PrincessCounter = 1;	
	int q;
	
	for (q = 0; q <= 1; q++)
	{
		Princess[q].tid = 14;
		Princess[q].pb = 0;
		
		Princess[q].Sprite= &obj_buffer[126+q];
		
		obj_set_attr(Princess[q].Sprite, 
		ATTR0_SQUARE,                // Square, regular sprite
		ATTR1_SIZE_8,                    // 64x64p, 
		ATTR2_PALBANK(Princess[q].pb) | Princess[q].tid);
		
		
		Princess[q].alive = false;
		if (PrincessCounter == 1)
		{
			Princess[q].x= 124;
			Princess[q].y= 0;	
			PrincessCounter++;
		}
		else
		{
			Princess[q].x= 108;
			Princess[q].y= 152;	
		}
		
		obj_set_pos(Princess[q].Sprite, Princess[q].x, Princess[q].y);
	}
}

void Level_1()
{	
	vid_vsync();
	key_poll();
	
	tte_write("#{P:80,64}");
	sprintf(ScoreText,"Score: %d",score);
	tte_write(ScoreText);
	//char random[50];
	if (life == 3)
	{
		r = rand()%2; //sets random to be 1 or 0
		SpawnPrincess();
	}
	else if(life == 2)
	{
		r = 1;
	}
	else if(life == 1)
	{
		r = 0;
	}
	else 
	{
		//you dead
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);

	if((key_is_down(KEY_A))){
		Bullet= &obj_buffer[1];
		obj_set_attr(Bullet, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(0) | 4);
		if(bullet.alive == false){
			bulletNumber++;
			bullet.left = lookLeft;
			bullet.alive = true;
			bullet.x = x;
			bullet.y = y + 3;
			obj_set_pos(Bullet, bullet.x, bullet.y);
		}
		if(lookLeft){
			Bullet->attr1 ^= ATTR1_HFLIP;
		}
	}
	if(bullet.alive == true) {
		

		if(bullet.left == true)
		{
			bullet.x-= 2;
			if(bullet.x < -8){
				bullet.alive = false;
			}
		}
		else//right
		{
			bullet.x+= 2;
		
			if(bullet.x > 248){
				bullet.alive = false;
			}
		}
		for(place = 0; place <= NUMBER_OF_H -1; place++) {
			if(bullet.x <= Soldat[place].x + 8 && bullet.x > Soldat[place].x && bullet.y <= Soldat[place].y + 8 && bullet.y > Soldat[place].y)
			{
				bullet.alive = false;
				bullet.x = -5;
				bullet.y = -5;
				Soldat[place].i = 0;
				Soldat[place].alive = false;
				if (Soldat[place].x == 0 || Soldat[place].x == 232)
				{
					score += 50;
				}
				else if(Soldat[place].x == 16 || Soldat[place].x == 216)
				{
					score += 45;
				}
				else if(Soldat[place].x == 32 || Soldat[place].x == 200)
				{
					score += 35;
				}
				else if(Soldat[place].x == 48 || Soldat[place].x == 184)
				{
					score += 30;
				}
				else if(Soldat[place].x == 64 || Soldat[place].x == 168)
				{
					score += 25;
				}
				else if(Soldat[place].x == 80 || Soldat[place].x == 152)
				{
					score += 20;
				}
				else
				{
					score += 5;
				}
				killcounter++;
				Soldat[place].x= 0;
				Soldat[place].y= -8;
				obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
				CheckKills();
			}
		}	
		obj_set_pos(Bullet, bullet.x, bullet.y);
	}
	for(place = 0; place <= NUMBER_OF_H -1; place++) 
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false)
		{
			if (Soldat[place].y < 152)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y++;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y > 151)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)
		{
			if(Soldat[place].y > 0)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y--;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y < 1)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				

			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		if (Soldat[place].x == 108)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 1;
				Princess[1].alive= false;
				Princess[1].x= 0;
				Princess[1].y= -8;
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
		}
		if (Soldat[place].x == 124)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 2;
				Princess[0].alive= false;
				Princess[0].x= 0;
				Princess[0].y= -8;
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);	
	}
	if (life == 2)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == true)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	else if (life == 1)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == false)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	//move left/right
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;
	}
	
	if(y<-8){
		y = 168;
	}
	if(y>168){
		y = -8;
	}

	// toggle mapping mode
	if(key_hit(KEY_START))
		REG_DISPCNT ^= DCNT_OBJ_1D;

	// Hey look, it's one of them build macros!
	Bob->attr2= ATTR2_BUILD(tid, pb, 0);
	obj_set_pos(Bob, x, y);


	//x += key_tri_horz();
	//y += key_tri_vert();

	//REG_BG1HOFS= x;
	//REG_BG1VOFS= y;
	oam_copy(oam_mem, obj_buffer, 128);    // only need to update one
}
void Level_2()
{	
	vid_vsync();
	key_poll();
	
	tte_write("#{P:80,64}");
	sprintf(ScoreText,"Score: %d",score);
	tte_write(ScoreText);
	//char random[50];
	if (life == 3)
	{
		r = rand()%2; //sets random to be 1 or 0
		SpawnPrincess();
	}
	else if(life == 2)
	{
		r = 1;
	}
	else if(life == 1)
	{
		r = 0;
	}
	else 
	{
		//you dead
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);

	if((key_is_down(KEY_A))){
		Bullet= &obj_buffer[1];
		obj_set_attr(Bullet, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(0) | 4);
		if(bullet.alive == false){
			bulletNumber++;
			bullet.left = lookLeft;
			bullet.alive = true;
			bullet.x = x;
			bullet.y = y + 3;
			obj_set_pos(Bullet, bullet.x, bullet.y);
		}
		if(lookLeft){
			Bullet->attr1 ^= ATTR1_HFLIP;
		}
	}
	if(bullet.alive == true) {
		

		if(bullet.left == true)
		{
			bullet.x-= 2;
			if(bullet.x < -8){
				bullet.alive = false;
			}
		}
		else//right
		{
			bullet.x+= 2;
		
			if(bullet.x > 248){
				bullet.alive = false;
			}
		}
		for(place = 0; place <= NUMBER_OF_H -1; place++) {
			if(bullet.x <= Soldat[place].x + 8 && bullet.x > Soldat[place].x && bullet.y <= Soldat[place].y + 8 && bullet.y > Soldat[place].y)
			{
				bullet.alive = false;
				bullet.x = -5;
				bullet.y = -5;
				Soldat[place].i = 0;
				Soldat[place].alive = false;
				if (Soldat[place].x == 0 || Soldat[place].x == 232)
				{
					score += 50;
				}
				else if(Soldat[place].x == 16 || Soldat[place].x == 216)
				{
					score += 45;
				}
				else if(Soldat[place].x == 32 || Soldat[place].x == 200)
				{
					score += 35;
				}
				else if(Soldat[place].x == 48 || Soldat[place].x == 184)
				{
					score += 30;
				}
				else if(Soldat[place].x == 64 || Soldat[place].x == 168)
				{
					score += 25;
				}
				else if(Soldat[place].x == 80 || Soldat[place].x == 152)
				{
					score += 20;
				}
				else
				{
					score += 5;
				}
				killcounter++;
				Soldat[place].x= 0;
				Soldat[place].y= -8;
				obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
				CheckKills();
			}
		}	
		obj_set_pos(Bullet, bullet.x, bullet.y);
	}
	for(place = 0; place <= NUMBER_OF_H -1; place++) 
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false)
		{
			if (Soldat[place].y < 152)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y++;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y > 151)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)
		{
			if(Soldat[place].y > 0)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y--;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y < 1)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				

			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		if (Soldat[place].x == 108)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 1;
				Princess[1].alive= false;
				Princess[1].x= 0;
				Princess[1].y= -8;
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
		}
		if (Soldat[place].x == 124)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 2;
				Princess[0].alive= false;
				Princess[0].x= 0;
				Princess[0].y= -8;
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);	
	}
	if (life == 2)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == true)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	else if (life == 1)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == false)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	//move left/right
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;
	}
	
	if(y<-8){
		y = 168;
	}
	if(y>168){
		y = -8;
	}

	// toggle mapping mode
	if(key_hit(KEY_START))
		REG_DISPCNT ^= DCNT_OBJ_1D;

	// Hey look, it's one of them build macros!
	Bob->attr2= ATTR2_BUILD(tid, pb, 0);
	obj_set_pos(Bob, x, y);


	//x += key_tri_horz();
	//y += key_tri_vert();

	//REG_BG1HOFS= x;
	//REG_BG1VOFS= y;
	oam_copy(oam_mem, obj_buffer, 128);    // only need to update one
}
void Level_3()
{	
	vid_vsync();
	key_poll();
	
	tte_write("#{P:80,64}");
	sprintf(ScoreText,"Score: %d",score);
	tte_write(ScoreText);
	//char random[50];
	if (life == 3)
	{
		r = rand()%2; //sets random to be 1 or 0
		SpawnPrincess();
	}
	else if(life == 2)
	{
		r = 1;
	}
	else if(life == 1)
	{
		r = 0;
	}
	else 
	{
		//you dead
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);

	if((key_is_down(KEY_A))){
		Bullet= &obj_buffer[1];
		obj_set_attr(Bullet, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(0) | 4);
		if(bullet.alive == false){
			bulletNumber++;
			bullet.left = lookLeft;
			bullet.alive = true;
			bullet.x = x;
			bullet.y = y + 3;
			obj_set_pos(Bullet, bullet.x, bullet.y);
		}
		if(lookLeft){
			Bullet->attr1 ^= ATTR1_HFLIP;
		}
	}
	if(bullet.alive == true) {
		

		if(bullet.left == true)
		{
			bullet.x-= 2;
			if(bullet.x < -8){
				bullet.alive = false;
			}
		}
		else//right
		{
			bullet.x+= 2;
		
			if(bullet.x > 248){
				bullet.alive = false;
			}
		}
		for(place = 0; place <= NUMBER_OF_H -1; place++) {
			if(bullet.x <= Soldat[place].x + 8 && bullet.x > Soldat[place].x && bullet.y <= Soldat[place].y + 8 && bullet.y > Soldat[place].y)
			{
				bullet.alive = false;
				bullet.x = -5;
				bullet.y = -5;
				Soldat[place].i = 0;
				Soldat[place].alive = false;
				if (Soldat[place].x == 0 || Soldat[place].x == 232)
				{
					score += 50;
				}
				else if(Soldat[place].x == 16 || Soldat[place].x == 216)
				{
					score += 45;
				}
				else if(Soldat[place].x == 32 || Soldat[place].x == 200)
				{
					score += 35;
				}
				else if(Soldat[place].x == 48 || Soldat[place].x == 184)
				{
					score += 30;
				}
				else if(Soldat[place].x == 64 || Soldat[place].x == 168)
				{
					score += 25;
				}
				else if(Soldat[place].x == 80 || Soldat[place].x == 152)
				{
					score += 20;
				}
				else
				{
					score += 5;
				}
				killcounter++;
				Soldat[place].x= 0;
				Soldat[place].y= -8;
				obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
				CheckKills();
			}
		}	
		obj_set_pos(Bullet, bullet.x, bullet.y);
	}
	for(place = 0; place <= NUMBER_OF_H -1; place++) 
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false)
		{
			if (Soldat[place].y < 152)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y++;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y > 151)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)
		{
			if(Soldat[place].y > 0)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y--;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y < 1)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				

			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		if (Soldat[place].x == 108)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 1;
				Princess[1].alive= false;
				Princess[1].x= 0;
				Princess[1].y= -8;
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
		}
		if (Soldat[place].x == 124)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 2;
				Princess[0].alive= false;
				Princess[0].x= 0;
				Princess[0].y= -8;
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);	
	}
	if (life == 2)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == true)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	else if (life == 1)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == false)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	//move left/right
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;
	}
	
	if(y<-8){
		y = 168;
	}
	if(y>168){
		y = -8;
	}

	// toggle mapping mode
	if(key_hit(KEY_START))
		REG_DISPCNT ^= DCNT_OBJ_1D;

	// Hey look, it's one of them build macros!
	Bob->attr2= ATTR2_BUILD(tid, pb, 0);
	obj_set_pos(Bob, x, y);


	//x += key_tri_horz();
	//y += key_tri_vert();

	//REG_BG1HOFS= x;
	//REG_BG1VOFS= y;
	oam_copy(oam_mem, obj_buffer, 128);    // only need to update one
}

void Level_4()
{	
	vid_vsync();
	key_poll();
	
	tte_write("#{P:80,64}");
	sprintf(ScoreText,"Score: %d",score);
	tte_write(ScoreText);
	//char random[50];
	if (life == 3)
	{
		r = rand()%2; //sets random to be 1 or 0
		SpawnPrincess();
	}
	else if(life == 2)
	{
		r = 1;
	}
	else if(life == 1)
	{
		r = 0;
	}
	else 
	{
		//you dead
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);

	if((key_is_down(KEY_A))){
		Bullet= &obj_buffer[1];
		obj_set_attr(Bullet, 
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 64x64p, 
        ATTR2_PALBANK(0) | 4);
		if(bullet.alive == false){
			bulletNumber++;
			bullet.left = lookLeft;
			bullet.alive = true;
			bullet.x = x;
			bullet.y = y + 3;
			obj_set_pos(Bullet, bullet.x, bullet.y);
		}
		if(lookLeft){
			Bullet->attr1 ^= ATTR1_HFLIP;
		}
	}
	if(bullet.alive == true) {
		

		if(bullet.left == true)
		{
			bullet.x-= 2;
			if(bullet.x < -8){
				bullet.alive = false;
			}
		}
		else//right
		{
			bullet.x+= 2;
		
			if(bullet.x > 248){
				bullet.alive = false;
			}
		}
		for(place = 0; place <= NUMBER_OF_H -1; place++) {
			if(bullet.x <= Soldat[place].x + 8 && bullet.x > Soldat[place].x && bullet.y <= Soldat[place].y + 8 && bullet.y > Soldat[place].y)
			{
				bullet.alive = false;
				bullet.x = -5;
				bullet.y = -5;
				Soldat[place].i = 0;
				Soldat[place].alive = false;
				if (Soldat[place].x == 0 || Soldat[place].x == 232)
				{
					score += 50;
				}
				else if(Soldat[place].x == 16 || Soldat[place].x == 216)
				{
					score += 45;
				}
				else if(Soldat[place].x == 32 || Soldat[place].x == 200)
				{
					score += 35;
				}
				else if(Soldat[place].x == 48 || Soldat[place].x == 184)
				{
					score += 30;
				}
				else if(Soldat[place].x == 64 || Soldat[place].x == 168)
				{
					score += 25;
				}
				else if(Soldat[place].x == 80 || Soldat[place].x == 152)
				{
					score += 20;
				}
				else
				{
					score += 5;
				}
				killcounter++;
				Soldat[place].x= 0;
				Soldat[place].y= -8;
				obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
				CheckKills();
			}
		}	
		obj_set_pos(Bullet, bullet.x, bullet.y);
	}
	for(place = 0; place <= NUMBER_OF_H -1; place++) 
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false)
		{
			if (Soldat[place].y < 152)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y++;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y > 151)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].up = true;
						Soldat[place].i=0;	
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)
		{
			if(Soldat[place].y > 0)
			{
				if (Soldat[place].movementcounter == true)
				{
					Soldat[place].y--;
					Soldat[place].movementcounter = false;
				}
				else
				{
					Soldat[place].movementcounter = true;
				}
			}
			else if (Soldat[place].y < 1)
			{
				if (Soldat[place].left == false)
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x++;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)
					{
						Soldat[place].x--;
						Soldat[place].i++;
					}
					else
					{
						Soldat[place].i=0;	
						Soldat[place].up = false;
					}
				}
				

			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
		}
		if (Soldat[place].x == 108)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 1;
				Princess[1].alive= false;
				Princess[1].x= 0;
				Princess[1].y= -8;
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
		}
		if (Soldat[place].x == 124)
		{
			Soldat[place].alive = false;
			Soldat[place].i = 0;
			if (life == 3)
			{
				life = 2;
				Princess[0].alive= false;
				Princess[0].x= 0;
				Princess[0].y= -8;
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);
			}
			else
			{
				life = 0;
				Game_State = 3;
			}
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);	
	}
	if (life == 2)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == true)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	else if (life == 1)
	{
		for (place = 0; place <= NUMBER_OF_H;place++)
		{
			if (Soldat[place].left == false)
			{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			}
		}
	}
	//move left/right
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;
	}
	
	if(y<-8){
		y = 168;
	}
	if(y>168){
		y = -8;
	}

	// toggle mapping mode
	if(key_hit(KEY_START))
		REG_DISPCNT ^= DCNT_OBJ_1D;

	// Hey look, it's one of them build macros!
	Bob->attr2= ATTR2_BUILD(tid, pb, 0);
	obj_set_pos(Bob, x, y);


	//x += key_tri_horz();
	//y += key_tri_vert();

	//REG_BG1HOFS= x;
	//REG_BG1VOFS= y;
	oam_copy(oam_mem, obj_buffer, 128);    // only need to update one
}

void CheckKills(){
	if (killcounter == 25)
	{
	killonce = true;
	KillHiamsters();
	Game_State = 4;
	}
	
	else if(killcounter ==50)
	{
	killonce = true;
	KillHiamsters();
	Game_State = 5;
	} 
	else if(killcounter == 100)
	{
	Level_4();
	killonce = true;
	KillHiamsters();
	Game_State = 6;
	} 
}
void reset() {
	x= 117;
	y= 77;
	life = 3;
	score = 0;
	killcounter = 0;
}

void KillHiamsters()
{

	for (place = 0; place <= NUMBER_OF_H;place++)
	{
		if (Soldat[place].alive == true)
		{
			Soldat[place].alive = false;
			Soldat[place].x= 0;
			Soldat[place].y= -8;
			Soldat[place].i = 0;
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);
			
		}
		killonce = false;
	}
}

void menu()
{
	switch(Menu_State) {
		case 0:
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;
			key_poll();
			tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
			tte_write("#{P:75,72}");
			tte_write("#{cx:0x3000} ->Start<-    ");
			tte_write("#{P:75,80}");
			tte_write("#{cx:0x1000}   Ending     ");
			
			if(key_hit(KEY_START)){
				Game_State = 1;
				Start();
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_DOWN)){
				Menu_State = 1;
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_UP)){
				Menu_State = 1;
				tte_write("#{es}");
			break;
		
		case 1:
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0|DCNT_BG2  ;
			key_poll();
			tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
			tte_write("#{P:75,72}");
			tte_write("#{cx:0x1000}   Start    ");
			tte_write("#{P:75,80}");
			tte_write("#{cx:0x3000} ->Ending<- ");
			
			if(key_hit(KEY_DOWN)){
				Menu_State = 0;
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_UP)){
				Menu_State = 0;
				tte_write("#{es}");//clear the screen
				break;
			}
			break;
		}
	}
}

void Start() {
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1|DCNT_OBJ | DCNT_OBJ_1D;

	Level_1();
	initializeSoldat();
	//Game();
}
void GameOver()
{
	vid_vsync();
	key_poll();
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;
	
	memcpy(pal_bg_mem, GameOverBGPal, GameOverBGPalLen);
	memcpy(&tile_mem[1][0], GameOverBGTiles, GameOverBGTilesLen);
	memcpy(&se_mem[30][0], GameOverBGMap, GameOverBGMapLen);
	
	
	REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;
	
	tte_write("#{P:56,72}");
	tte_write("#{cx:0x3000} ->Main Menu<-");
	if(key_hit(KEY_START))
		{
			reset();
			Game_State = 0;
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;
			tte_write("#{es}");//clear the screen
			Menu_State = 0;
			menu();
		}
}

void pause() {
	key_poll();
	switch(Pause_State){
	case 0:
		REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;
		tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
		tte_write("#{P:75,72}");
		tte_write("#{cx:0x3000} ->Continue<-");
		tte_write("#{P:75,80}");
		tte_write("#{cx:0x1000}   Main Menu   ");
		if(key_hit(KEY_START))
		{
			Game_State = 1;
			tte_write("#{es}");//clear the screen
		}
		if(key_hit(KEY_DOWN)){
				Pause_State = 1;
				tte_write("#{es}");//clear the screen
				break;
			}
		if(key_hit(KEY_UP)){
			Pause_State = 1;
			tte_write("#{es}");
		}
		break;
	case 1:
		REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;
		tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
		tte_write("#{P:75,72}");
		tte_write("#{cx:0x1000}   Continue      ");
		tte_write("#{P:75,80}");
		tte_write("#{cx:0x3000} ->Main Menu<-   ");
		if(key_hit(KEY_START))
		{
			reset();
			Game_State = 0;
			tte_write("#{es}");//clear the screen
		}
		if(key_hit(KEY_DOWN)){
			Pause_State = 0;
			tte_write("#{es}");//clear the screen
			break;
		}
		if(key_hit(KEY_UP)){
			Pause_State = 0;
			break;
		}
		break;
	}
}
	