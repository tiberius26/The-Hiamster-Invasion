//
//! \file hello_demo.c
//!   Screen-entry text demo
//! \date 20060228 - 20080416
//! \author cearn
//
// === NOTES === //adding all the assets needed:
#include "string.h" //tells the game to use a specific header file
#include <stdio.h>//tells the game to use a specific header file
#include <tonc.h>//tells the game to use a specific header file
#include <time.h>//tells the game to use a specific header file
#include <stdlib.h>//tells the game to use a specific header file
#include "Untitled.h"//tells the game to use a specific header file
#include "brin.h"//tells the game to use a specific header file
#include "Bob.h"//tells the game to use a specific header file
#include "goodBG.h"//tells the game to use a specific header file
#include "MenuBG.h"//tells the game to use a specific header file
#include "Roof.h"//tells the game to use a specific header file
#include "Lab.h"//tells the game to use a specific header file
#include "Garden.h"//tells the game to use a specific header file
#include "bullet.h"//tells the game to use a specific header file
#include "BulletProps.h"//tells the game to use a specific header file
#include "Soldat.h"//tells the game to use a specific header file
#include "Princess.h"//tells the game to use a specific header file
#include "hello.h"//tells the game to use a specific header file
#include "Musketeer.h"//tells the game to use a specific header file
#include "GameOverBG.h"//tells the game to use a specific header file
#include "Mission.h"//tells the game to use a specific header file
#include "Credits.h"//tells the game to use a specific header file
#include "WinScreen.h"//tells the game to use a specific header file
#include "Nuke.h"//tells the game to use a specific header file
#include "Instructions.h"//tells the game to use a specific header file


#define NUMBER_OF_H 80 //the number of hiamster Soldats
#define NUMBER_OF_M 20 //the number of hiamster Muskateers
#define NUMBER_OF_P 1 //the number of princesses

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;
int Game_State; //different states of the game
int Menu_State; //different states of the menu
int Pause_State; //different states fo the pause menu
int x, y; //coordinates of the player
int place; //integer used to loop through the enemies
int size; //size of sprites
int cooldown; //to see if the player is iddle on the manu
int i; //used to loop through the princesses when creating them
int r; //r for all random values
int r2; //choses where to spawn hiamsters
int r3; //chance of Muskateer
int MenuSceneCooldown; //cooldown for choseIddle
int choseIddle;//Used to change the backgrounds in iddle
int Difficulty; //used to determine the spawning speed of enemies
int DifficultyCooldown; //timmer before difficulty increases
int killcounter; //tracks the number of kills
int loadder; //used to load the Iddle screen once

//int EnemyCounter;
int nextsoldat; //Soldat counter
int nextM; //Musketeer counter
int life; //determines from which side enemies come
int score; //stores your score
int Highscore; //stores the highest score
int EnemyCooldown1; //makes muskateers spawn at a slower rate
int PrincessCounter; //loops through princesses
bool lookLeft; //determines the direction of the player
char ScoreText[50]; //used to display the score
char HighScoreText[50];//used to display the highscore
char KillText[50];//used to display the number of kills
u32 tid, pb; //tileID and pallet bank for the player
OBJ_ATTR *Bob; //attribute for bob
OBJ_ATTR *BobL;//attribute for bob
OBJ_ATTR *Bullet;//attribute for the bullet
BulletProps bullet; //acesses the bullet struct
SoldatProps Soldat[NUMBER_OF_H];//acesses the soldat struct
PowerupProps Powerup[NUMBER_OF_P];//acesses the powerup struct
PrincessProps Princess[2];//acesses the princess struct
MusketeerProps Musketeer[NUMBER_OF_M];//acesses the Musketeer struct

void Start(); //starts the game
void Level_1(); //game level
void Level_2();//game level
void Level_3();//game level
void Level_4();//game level
void LoadLevel_1();//loads game level background
void LoadLevel_2();//loads game level background
void LoadLevel_3();//loads game level background
void LoadLevel_4();//loads game level background
void initializeSoldat(); //initializes the soldats
void initializeMusketeer();// initializes the Musketeers
void SpawnEnemy();//spawns the enemies
void init();//sets initial values
void menu();//the menu state
void pause(); //pauses the game
void reset(); //resets values
void GameOver(); //state
void SpawnPrincess(); //spawns the princesses
void KillHiamsters(); //clears the screen of enemies
void CheckKills(); //checks the number of kills
void LoadMission(); //laods state background
void LoadCredits();//laods state background
void LoadWinScreen();//laods state background
void Mission();//state
void Credits();//state
void WinScreen();//state
void iddle();// attract state
void Instructions();//state
void LoadInstructions();//laods state background
void EnemyMove();//makes the enemies move
void BulletCollision();//checks collision for the bullet
void shoot();// creates a bullet]
void SpawnPowerup();// spawns the powerup

int main()
{
	srand(time(NULL));
	//load initial assets:
	memcpy(pal_bg_mem, MenuBGPal, MenuBGPalLen); //menu background
	memcpy(&tile_mem[2][0], MenuBGTiles, MenuBGTilesLen);
	memcpy(&se_mem[28][0], MenuBGMap, MenuBGMapLen);

	
	memcpy(&tile_mem[4][0], BobTiles, BobTilesLen); //Bob
	memcpy(pal_obj_mem, BobPal, BobPalLen);
	
	
	memcpy(&tile_mem[4][9], SoldatTiles, SoldatTilesLen); //Hiamster Soldat
	memcpy(pal_obj_mem, SoldatPal, SoldatPalLen);
	
	memcpy(&tile_mem[4][19], MusketeerTiles, MusketeerTilesLen); //Muskateer 
	memcpy(pal_obj_mem, MusketeerPal, MusketeerPalLen);
	
	
	memcpy(&tile_mem[4][4], bulletTiles, bulletTilesLen); //Bullets
	memcpy(pal_obj_mem, bulletPal, bulletPalLen);
	
	memcpy(&tile_mem[4][12], NukeTiles, NukeTilesLen); //nuke
	memcpy(pal_obj_mem, NukePal, NukePalLen);
	
	memcpy(&tile_mem[4][14], PrincessTiles, PrincessTilesLen); //princesses
	memcpy(pal_obj_mem, PrincessPal, PrincessPalLen);
	
	oam_init(obj_buffer, 128);
	
	REG_BG2CNT= BG_CBB(2) | BG_SBB(28) | BG_4BPP | BG_REG_32x32;//tells the game what BG2 is
	
	init();
	
	while (1){
		switch(Game_State){ //loads different states
			case 0:
				menu(); //self explanatory
			break;
			
			case 1:
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
				Level_1();
			break;
			case 5:
				LoadLevel_3();
				Level_1();
			break;
			case 6:
				LoadLevel_4();
				Level_1();
			break;
			case 7:
				LoadMission();
				Mission();
			break;
			case 8:
				LoadCredits();
				Credits();
			break;
			case 9:
				LoadWinScreen();
				WinScreen();
			break;
			case 10:
				LoadInstructions();
				Instructions();
			break;
			case 11:
				LoadLevel_1();
				iddle();
			break;
		}
	}
	return 0;
}


void init() 
	{
	//sets the initial values for the game
	MenuSceneCooldown=1; //changes the background in the attract mode (iddle)
	cooldown = 1000;
	x= 116; //bob's
	y= 77; //bob's
	loadder = 1; //counter used to take actione once
	EnemyCooldown1 = 5; //Spawn cooldown
	Game_State = 0; //used to determine the state of the game
	Menu_State = 0; //used to determine the state of the menu
	nextsoldat = 0; //used to loop through the soldats
	nextM = 0;//used to loop through the muskateers
	score = 0; //score value
	Highscore = 0; //high score value
	life = 3; //life state
	tid= 0; //tile ID
	killcounter = 0; //sets the kills to 0
	pb= 0; //palletbank
	lookLeft = false;//sets the direction bob is facing
    Bob= &obj_buffer[0];
	}
	
void LoadLevel_1()//loads background
{
		
		memcpy(pal_bg_mem, goodBGPal, goodBGPalLen);
		memcpy(&tile_mem[1][0], goodBGTiles, goodBGTilesLen);
		memcpy(&se_mem[30][0], goodBGMap, goodBGMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is

}
void LoadLevel_2()//loads background
{		
		memcpy(pal_bg_mem, GardenPal, GardenPalLen);
		memcpy(&tile_mem[1][0], GardenTiles, GardenTilesLen);
		memcpy(&se_mem[30][0], GardenMap, GardenMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is

}
void LoadLevel_3()//loads background
{

		memcpy(pal_bg_mem, LabPal, LabPalLen);
		memcpy(&tile_mem[1][0], LabTiles, LabTilesLen);
		memcpy(&se_mem[30][0], LabMap, LabMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is
}
void LoadLevel_4()//loads background
{

		memcpy(pal_bg_mem, RoofPal, RoofPalLen);
		memcpy(&tile_mem[1][0], RoofTiles, RoofTilesLen);
		memcpy(&se_mem[30][0], RoofMap, RoofMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is
}
void LoadCredits()//loads background
{
		memcpy(pal_bg_mem, CreditsPal, CreditsPalLen);
		memcpy(&tile_mem[1][0], CreditsTiles, CreditsTilesLen);
		memcpy(&se_mem[30][0], CreditsMap, CreditsMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is

}
void LoadMission()//loads background
{
		memcpy(pal_bg_mem, MissionPal, MissionPalLen);
		memcpy(&tile_mem[1][0], MissionTiles, MissionTilesLen);
		memcpy(&se_mem[30][0], MissionMap, MissionMapLen);//tells the game what BG1 is
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;

}
void LoadInstructions()//loads background
{
		memcpy(pal_bg_mem, InstructionsPal, InstructionsPalLen);
		memcpy(&tile_mem[1][0], InstructionsTiles, InstructionsTilesLen);
		memcpy(&se_mem[30][0], InstructionsMap, InstructionsMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is
}
void LoadWinScreen()//loads background
{
		memcpy(pal_bg_mem, WinScreenPal, WinScreenPalLen);
		memcpy(&tile_mem[1][0], WinScreenTiles, WinScreenTilesLen);
		memcpy(&se_mem[30][0], WinScreenMap, WinScreenMapLen);
		REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is
}

void initializeSoldat()//sets the information for the soldats
{
	int k;
	for (k = 0; k < NUMBER_OF_H; k++) //loops through all Soldats
	{
		Soldat[k].Count = 0;//keeps track of the Soldat number
		Soldat[k].tid = 9; //sets tile ID
		Soldat[k].pb = 0; //sets palletbank
		
		Soldat[k].Sprite= &obj_buffer[3+k]; //sets object buffer
		
		obj_set_attr(Soldat[k].Sprite, //sets Soldat attributes
		ATTR0_SQUARE,                // Square, regular sprite
		ATTR1_SIZE_8,                    // 8x8p, 
		ATTR2_PALBANK(Soldat[k].pb) | Soldat[k].tid);
		Soldat[k].movementcounter = true;//ensures that the Soldats move every other frame
		
		Soldat[k].alive = false; //they are not alive yet as this only initiates them
		
		Soldat[k].x= 0; //sets soldat x
		Soldat[k].y= -8;	//sets soldat y
		
		obj_set_pos(Soldat[k].Sprite, Soldat[k].x, Soldat[k].y);//updates the position
	}
}
void initializeMusketeer()//sets the information for the Musketeers
{
	int L;
	for (L = 0; L < NUMBER_OF_M; L++)//loops through all Musketeer
	{
		Musketeer[L].Count = 0;//keeps track of the Muskateer number
		Musketeer[L].tid = 19;//sets tile ID
		Musketeer[L].pb = 0;//sets palletbank
		
		int sprite_no = 3+L+NUMBER_OF_H;//sets object buffer
		
		Musketeer[L].Sprite= &obj_buffer[sprite_no];//sets Muskateer attributes
		obj_set_attr(Musketeer[L].Sprite, // Square, regular sprite
		ATTR0_SQUARE,                // Square, regular sprite
		ATTR1_SIZE_8,                    // 8x8p, 
		ATTR2_PALBANK(Musketeer[L].pb) | Musketeer[L].tid);
		
		
		Musketeer[L].alive = false;//they are not alive yet as this only initiates them
		
		Musketeer[L].x= 0;	//sets Muskateer x
		Musketeer[L].y= -8;	//sets Muskateer y
		
		obj_set_pos(Musketeer[L].Sprite, Musketeer[L].x, Musketeer[L].y);//updates the position
	}
	
}
void SpawnEnemy()
{
	r2 = rand()%2+ Difficulty; //used to randomise the speed at which enemies spawn
	r3 = rand()%300; //used to randomise Muskateer spawn
	if (EnemyCooldown1 < (1+r2))
	{
		if (Soldat[nextsoldat].alive == false) //checks if the Soldat is dead
		{
			if (r == 1) //spawns it on the left
			{
				
				Soldat[nextsoldat].x = 0;//sets x
				Soldat[nextsoldat].y = 0;//sets y
				Soldat[nextsoldat].alive = true;//Sets them to be alive
				Soldat[nextsoldat].left = false;//makes it so that they move to the right
				Soldat[nextsoldat].up = false; //makes it move down
				obj_set_pos(Soldat[nextsoldat].Sprite, Soldat[nextsoldat].x, Soldat[nextsoldat].y);//updates position
			
			}
			else //spawns it on the right
			{
				Soldat[nextsoldat].x = 232;//sets x
				Soldat[nextsoldat].y = 152;//sets y
				Soldat[nextsoldat].alive = true;//Sets them to be alive
				Soldat[nextsoldat].left = true;//makes it so that they move to the left
				Soldat[nextsoldat].up = true;//makes them move up
				obj_set_pos(Soldat[nextsoldat].Sprite, Soldat[nextsoldat].x, Soldat[nextsoldat].y);//updates position
			}
			nextsoldat++;//goes to the next soldat
			if (nextsoldat >= NUMBER_OF_H) //ensures that there are no more than 80 soldats
			{
				nextsoldat = 0; //resets the counter
			}
			
		}
		
		EnemyCooldown1 = 45;//sets a cooldown
		DifficultyCooldown = 1000; //resets the cooldown before the difficulty increases
	}
	else
	{
		EnemyCooldown1--; //ticks down to when an enemy spawns
		if (DifficultyCooldown <= 0) //increases the difficulty when the timer reaches 0
		{
		Difficulty++;
		}
		else{DifficultyCooldown--;}
	}
	if (r3 == 1) //spawns Muskateer
	{
		if (Musketeer[nextM].alive == false)//checks if the Musketeer is dead
		{
			if (r == 1)//spawns it on the left
			{
				
				Musketeer[nextM].x = 0;//sets x
				Musketeer[nextM].y = 0;//sets y
				Musketeer[nextM].alive = true;//Sets them to be alive
				Musketeer[nextM].left = false;//makes it so that they move to the right
				Musketeer[nextM].up = false;//makes it move down
				obj_set_pos(Musketeer[nextM].Sprite, Musketeer[nextM].x, Musketeer[nextM].y);//updates position
			
			}
			else //spawns it on the right
			{
				Musketeer[nextM].x = 232;
				Musketeer[nextM].y = 152;
				Musketeer[nextM].alive = true;//Sets them to be alive
				Musketeer[nextM].left = true;//makes it so that they move to the left
				Musketeer[nextM].up = true;//makes it move up
				obj_set_pos(Musketeer[nextM].Sprite, Musketeer[nextM].x, Musketeer[nextM].y);//updates position
			}
			nextM++;//goes to the next muskateer
			if (nextM > NUMBER_OF_M)//ensures that there are no more than 80 muskateers
			{
				nextM = 0;
			}
		}
	}
}
void SpawnPrincess()
{
	PrincessCounter = 1;//ensures that there are only 2 princesses	
	int q;//used to loop through the two
	
	for (q = 0; q <= 1; q++)
	{
		Princess[q].tid = 14;//sets tiel ID
		Princess[q].pb = 0; //sets palletbank
		
		Princess[q].Sprite= &obj_buffer[126+q]; //sets object buffer
		
		obj_set_attr(Princess[q].Sprite,  //sets princess object attributes
		ATTR0_SQUARE,                // Square, regular sprite
		ATTR1_SIZE_8,                    // 8x8p, 
		ATTR2_PALBANK(Princess[q].pb) | Princess[q].tid);
		
		
		Princess[q].alive = false; //sets the princesses to be dead
		if (PrincessCounter == 1)//sets the coordinates for the first princess
		{
			Princess[q].x= 124;
			Princess[q].y= 0;	
			PrincessCounter++;
		}
		else//sets the coordinates for the second princess
		{
			Princess[q].x= 108;
			Princess[q].y= 152;	
		}
		
		obj_set_pos(Princess[q].Sprite, Princess[q].x, Princess[q].y); //updates princess position
	}
}

void SpawnPowerup()
{
	int p;//loops through an array
	int random;//spawns the powerup at random after a kill
	random = rand() % 30; //1 in 30 chance of spawn
	if(random == 0) 
	{
		for (p = 0; p < 1; p++)
		{
			Powerup[p].tid = 12;//sets tile ID
			Powerup[p].pb = 0; //sets palletbank
			
			Powerup[p].Sprite= &obj_buffer[11+p+NUMBER_OF_H+NUMBER_OF_M];//sets object buffer
			
			obj_set_attr(Powerup[p].Sprite, //sets powerup attributes
			ATTR0_SQUARE,                // Square, regular sprite
			ATTR1_SIZE_8,                    // 8x8p, 
			ATTR2_PALBANK(Powerup[p].pb) | Powerup[p].tid);
			
			Powerup[p].y = rand() % 152;//randomises Y position
			Powerup[p].x = 116;//sets x position
			
			if(y + 8 > Powerup[p].y && Powerup[p].y + 8 > y) {
				SpawnPowerup();// makes sure taht the powerup does not spawn on top of the player
			}
			
			
			obj_set_pos(Powerup[p].Sprite, Powerup[p].x, Powerup[p].y);//updates position
		}
	}
}

void Level_1()
{	
	vid_vsync();//syncs the video
	key_poll();//acesses the keys
	tte_write("#{P:80,5}"); //writes at this position
	sprintf(ScoreText,"Score: %d",score);//assigns text to ScoreText
	tte_write(ScoreText);//draws ScoreText
	if (life == 3)//checks if you have all your lives
	{
		r = rand()%2; //spawns hiamsters from any side
		SpawnPrincess();
	}
	else if(life == 2)//checks if you have all your lives
	{
		r = 1;//spawns hiamsters from the left only
	}
	else if(life == 1)//checks if you have all your lives
	{
		r = 0;//spawns hiamsters from the right only
	}
	else 
	{
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");//writes defeat at the position mentioned above
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, //sets bob's attributes
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 8x8p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);//updates his position

	if((key_is_down(KEY_A))){ //checks if the player wants to shoot
		shoot(); //creates a bullet
	}
	BulletCollision();//checks if the bullet is hitting an enemy
	EnemyMove();//allows the enemies to move
	//Turns Bob:
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	//move left/right:
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	//checks if you get a powerup:
	if(y + 8 > Powerup[0].y && Powerup[0].y + 8 > y) {
		KillHiamsters(); //clears hiamsters
		Powerup[0].x = -20;//resets powerup position
		Powerup[0].y = -20;//resets powerup position
		obj_set_pos(Powerup[0].Sprite, Powerup[0].x, Powerup[0].y);//updates powerup position
	}

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;//changes to pause menu
	}
	//chaecks if you are going outside of the screen and teleports you to the opposite side:
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
	vid_vsync();//syncs the video
	key_poll();//acesses the keys
	tte_write("#{P:80,5}"); //writes at this position
	sprintf(ScoreText,"Score: %d",score);//assigns text to ScoreText
	tte_write(ScoreText);//draws ScoreText
	if (life == 3)//checks if you have all your lives
	{
		r = rand()%2; //spawns hiamsters from any side
		SpawnPrincess();
	}
	else if(life == 2)//checks if you have all your lives
	{
		r = 1;//spawns hiamsters from the left only
	}
	else if(life == 1)//checks if you have all your lives
	{
		r = 0;//spawns hiamsters from the right only
	}
	else 
	{
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");//writes defeat at the position mentioned above
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, //sets bob's attributes
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 8x8p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);//updates his position

	if((key_is_down(KEY_A))){ //checks if the player wants to shoot
		shoot(); //creates a bullet
	}
	BulletCollision();//checks if the bullet is hitting an enemy
	EnemyMove();//allows the enemies to move
	//Turns Bob:
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	//move left/right:
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	//checks if you get a powerup:
	if(y + 8 > Powerup[0].y && Powerup[0].y + 8 > y) {
		KillHiamsters(); //clears hiamsters
		Powerup[0].x = -20;//resets powerup position
		Powerup[0].y = -20;//resets powerup position
		obj_set_pos(Powerup[0].Sprite, Powerup[0].x, Powerup[0].y);//updates powerup position
	}

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;//changes to pause menu
	}
	//chaecks if you are going outside of the screen and teleports you to the opposite side:
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
	vid_vsync();//syncs the video
	key_poll();//acesses the keys
	tte_write("#{P:80,5}"); //writes at this position
	sprintf(ScoreText,"Score: %d",score);//assigns text to ScoreText
	tte_write(ScoreText);//draws ScoreText
	if (life == 3)//checks if you have all your lives
	{
		r = rand()%2; //spawns hiamsters from any side
		SpawnPrincess();
	}
	else if(life == 2)//checks if you have all your lives
	{
		r = 1;//spawns hiamsters from the left only
	}
	else if(life == 1)//checks if you have all your lives
	{
		r = 0;//spawns hiamsters from the right only
	}
	else 
	{
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");//writes defeat at the position mentioned above
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, //sets bob's attributes
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 8x8p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);//updates his position

	if((key_is_down(KEY_A))){ //checks if the player wants to shoot
		shoot(); //creates a bullet
	}
	BulletCollision();//checks if the bullet is hitting an enemy
	EnemyMove();//allows the enemies to move
	//Turns Bob:
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	//move left/right:
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	//checks if you get a powerup:
	if(y + 8 > Powerup[0].y && Powerup[0].y + 8 > y) {
		KillHiamsters(); //clears hiamsters
		Powerup[0].x = -20;//resets powerup position
		Powerup[0].y = -20;//resets powerup position
		obj_set_pos(Powerup[0].Sprite, Powerup[0].x, Powerup[0].y);//updates powerup position
	}

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;//changes to pause menu
	}
	//chaecks if you are going outside of the screen and teleports you to the opposite side:
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
		vid_vsync();//syncs the video
	key_poll();//acesses the keys
	tte_write("#{P:80,5}"); //writes at this position
	sprintf(ScoreText,"Score: %d",score);//assigns text to ScoreText
	tte_write(ScoreText);//draws ScoreText
	if (life == 3)//checks if you have all your lives
	{
		r = rand()%2; //spawns hiamsters from any side
		SpawnPrincess();
	}
	else if(life == 2)//checks if you have all your lives
	{
		r = 1;//spawns hiamsters from the left only
	}
	else if(life == 1)//checks if you have all your lives
	{
		r = 0;//spawns hiamsters from the right only
	}
	else 
	{
		tte_write("#{P:50,64}");
		tte_write("#{cx:0x1000} Defeat");//writes defeat at the position mentioned above
	}
	
	SpawnEnemy();
	//sprintf(random,"Random Number: %d",r);
	//tte_write("#{P:74,86}");
	//tte_write(random);
	
    obj_set_attr(Bob, //sets bob's attributes
        ATTR0_SQUARE,                // Square, regular sprite
        ATTR1_SIZE_8,                    // 8x8p, 
        ATTR2_PALBANK(pb) | tid);        // palbank 0, tile 0

    // position sprite (redundant here; the _real_ position
    // is set further down
    obj_set_pos(Bob, x, y);//updates his position

	if((key_is_down(KEY_A))){ //checks if the player wants to shoot
		shoot(); //creates a bullet
	}
	BulletCollision();//checks if the bullet is hitting an enemy
	EnemyMove();//allows the enemies to move
	//Turns Bob:
	if((key_is_down(KEY_LEFT))&&lookLeft == false){
		lookLeft = true;
		//Bob->attr1 ^= ATTR1_HFLIP;
	}
	//move left/right:
	if((key_is_down(KEY_RIGHT))){
		lookLeft = false;
	}
	if(lookLeft == true) {
		Bob->attr1 ^= ATTR1_HFLIP;
	}
	
	// move up/down
	y += 2*key_tri_vert();

	//checks if you get a powerup:
	if(y + 8 > Powerup[0].y && Powerup[0].y + 8 > y) {
		KillHiamsters(); //clears hiamsters
		Powerup[0].x = -20;//resets powerup position
		Powerup[0].y = -20;//resets powerup position
		obj_set_pos(Powerup[0].Sprite, Powerup[0].x, Powerup[0].y);//updates powerup position
	}

	// increment/decrement starting tile with R/L
	tid += bit_tribool(key_hit(-1), KI_R, KI_L);

	// pauses the game
	if(key_hit(KEY_SELECT))
	{
		tte_write("#{es}");//clear the screen
		vid_vsync();
		Game_State = 2;//changes to pause menu
	}
	//chaecks if you are going outside of the screen and teleports you to the opposite side:
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
	if (killcounter == 25)//checks kills
	{
	KillHiamsters();//clears the screen fo hiamsters
	Game_State = 4; //loads the next level
	}
	
	else if(killcounter ==50)//checks kills
	{
	KillHiamsters();//clears the screen fo hiamsters
	Game_State = 5;//loads the next level
	} 
	else if(killcounter == 100)//checks kills
	{
	KillHiamsters();//clears the screen fo hiamsters
	Game_State = 6;//loads the next level
	} 
}
void reset() { //resets all needed values
	x= 117;
	y= 77;
	life = 3;
	score = 0;
	killcounter = 0;
	loadder = 1;
	cooldown = 1000;
	Difficulty = 0;
}

void KillHiamsters() 
{

	for (place = 0; place <= NUMBER_OF_H;place++)//loops through all Soldats
	{
		if (Soldat[place].alive == true) //which are alive
		{
			Soldat[place].alive = false; //and kills them
			Soldat[place].x= 0; //changes x
			Soldat[place].y= -8;//changes y
			Soldat[place].i = 0; //resets i counter(used to move at the bottom and top of the screen)
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y); //updates Soldat position
			
		}

	}
	for (place = 0; place <= NUMBER_OF_M;place++)//loops through all the Muskateers
	{
		if (Musketeer[place].alive == true)//which are alive
		{
			Musketeer[place].alive = false;//and kills them
			Musketeer[place].x= 0;//changes x
			Musketeer[place].y= -8;//changes y
			Musketeer[place].i = 0;//resets i counter(used to move at the bottom and top of the screen)
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
			
		}

	}
}

void menu()
{
	switch(Menu_State) 
	{
		case 0: //displays the first state fo the menu
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;//tells the game what to show
			key_poll();//listens for key inputs
			tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
			//text displayed:
			tte_write("#{P:75,72}");
			tte_write("#{cx:0x3000} ->Start<-    ");
			tte_write("#{P:75,80}");
			tte_write("#{cx:0x1000}   Credits     ");
			tte_write("#{P:72,150}");
			sprintf(HighScoreText,"HighScore: %d",Highscore);
			tte_write(HighScoreText); //displays high score
			tte_write("#{P:82,88}");
			tte_write("#{cx:0x1000}Instructions ");
			if (cooldown == 0){Game_State = 11;} //goes to iddle if the cooldown reaches 0
			else {cooldown--;} //otherwise cooldown is decreased
			if(key_hit(KEY_START)){ //checks for input
				Game_State = 7;//goes to the mission screen
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_DOWN)){//checks for input
				Menu_State = 1; //goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_UP))//checks for input
			{
				Menu_State = 2;//goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
			}
			break;
		
		case 1://displays the second state fo the menu
			if (cooldown == 0){Game_State = 11;}
			else {cooldown--;}
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0|DCNT_BG2  ;//tells the game what to show
			key_poll();//listens for key inputs
			//text displayed:
			tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
			tte_write("#{P:75,72}");
			tte_write("#{cx:0x1000}   Start    ");
			tte_write("#{P:72,150}");
			sprintf(HighScoreText,"HighScore: %d",Highscore);//displays high score
			tte_write(HighScoreText);
			tte_write("#{P:75,80}");
			tte_write("#{cx:0x3000} ->Credits<- ");
			tte_write("#{P:82,88}");
			tte_write("#{cx:0x1000}Instructions ");
			tte_write("#{P:72,150}");

			if(key_hit(KEY_START))//checks for input
			{
				Game_State = 8;//goes to the credits screen
				tte_write("#{es}");//clear the screen
				cooldown = 1000;//resets cooldown
				break;
			}
			if(key_hit(KEY_DOWN))//checks for input
			{
				Menu_State = 2;//goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_UP))//checks for input
			{
				Menu_State = 0;//goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			break;
		case 2://displays the third state fo the menu
			if (cooldown == 0){Game_State = 11;}
			else {cooldown--;}
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0|DCNT_BG2  ;//tells the game what to show
			key_poll();//listens for key inputs
			tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
			tte_write("#{P:75,72}");
			tte_write("#{cx:0x1000}   Start    ");
			tte_write("#{P:72,150}");
			sprintf(HighScoreText,"HighScore: %d",Highscore);
			tte_write(HighScoreText);
			tte_write("#{P:75,80}");
			tte_write("#{cx:0x1000}   Credits");
			tte_write("#{P:70,88}");
			tte_write("#{cx:0x3000}->Instructions<- ");

			if(key_hit(KEY_START)){
				Game_State = 10;//goes to the Instructions screen
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_DOWN)){
				Menu_State = 0;//goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			if(key_hit(KEY_UP)){
				Menu_State = 1;//goes to another menu state
				cooldown = 1000;//resets cooldown
				tte_write("#{es}");//clear the screen
				break;
			}
			break;
	}
}

void Start() {
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1|DCNT_OBJ | DCNT_OBJ_1D;//tells the video memory what to display
	if (loadder==1)
	{
		initializeSoldat();//initializes Soldats
		initializeMusketeer();//initializes Muskateers
		loadder++;//makes it so that this will not be initialized again
	}
}
void GameOver()
{
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	
	memcpy(pal_bg_mem, GameOverBGPal, GameOverBGPalLen);
	memcpy(&tile_mem[1][0], GameOverBGTiles, GameOverBGTilesLen);
	memcpy(&se_mem[30][0], GameOverBGMap, GameOverBGMapLen);
	
	
	REG_BG1CNT= BG_CBB(1) | BG_SBB(30) | BG_4BPP | BG_REG_32x32;//tells the game what BG1 is
	
	tte_write("#{P:56,72}");
	tte_write("#{cx:0x3000} ->Main Menu<-"); //shows text
	tte_write("#{P:56,92}");
	sprintf(KillText,"   Kills: %d",killcounter);//displays the number of kills
	tte_write(KillText);
	if (killcounter <= 100) //checks if you got 100 kills
	{
	tte_write("#{P:20,102}");
	tte_write("#{cx:0x3000} You did not Kill enough...");
	}
	if (Highscore < score)
	{			
		Highscore = score;//changes the high score if the current score is higher
	}
	if(key_hit(KEY_START))//checks for input
	{
		reset();//resets all needed values
		Game_State = 0;//changes state to 0 (menu)
		REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;//tells the game what to show
		tte_write("#{es}");//clear the screen
		Menu_State = 0;//goes to the first menu state
		menu();//goes to the menu
	}


}


void pause() {
	key_poll();// listens for key input
	switch(Pause_State){
	case 0://laods first pause menu
		REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;//tells the game what to show
		tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
		tte_write("#{P:75,72}"); //text:
		tte_write("#{cx:0x3000} ->Continue<-");
		tte_write("#{P:75,80}");
		tte_write("#{cx:0x1000}   Main Menu   ");
		if(key_hit(KEY_START)) //chacks for input
		{
			REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1|DCNT_OBJ | DCNT_OBJ_1D;//tells the game what to show
			if (killcounter < 25)//checks kills to determine what level to return to adn clears the screen of enemies
			{
			KillHiamsters();
			Game_State = 1;
			}
			
			else if(killcounter >= 25 && killcounter < 50)//checks kills to determine what level to return to adn clears the screen of enemies
			{

			KillHiamsters();
			Game_State = 4;
			} 
			else if(killcounter >= 50 && killcounter < 100)//checks kills to determine what level to return to adn clears the screen of enemies
			{
			KillHiamsters();
			Game_State = 5;
			} 
			else if(killcounter >= 100)//checks kills to determine what level to return to adn clears the screen of enemies
			{
			Level_4();
			KillHiamsters();
			Game_State = 6;
			} 
			tte_write("#{es}");//clear the screen
		}
		if(key_hit(KEY_DOWN)){
				Pause_State = 1;//goes to the secone pause menu
				tte_write("#{es}");//clear the screen
				break;
			}
		if(key_hit(KEY_UP)){
			Pause_State = 1;//goes to the secone pause menu
			tte_write("#{es}");//clear the screen
		}
		break;
	case 1://laods second pause menu
		REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG2 ;//tells the game what to show
		tte_init_se_default(0, BG_CBB(0)|BG_SBB(29));	
		tte_write("#{P:75,72}");//text:
		tte_write("#{cx:0x1000}   Continue      ");
		tte_write("#{P:75,80}");
		tte_write("#{cx:0x3000} ->Main Menu<-   ");
		if(key_hit(KEY_START))
		{
			reset();//resets all needed values
			Game_State = 0;//goes to the menu
			tte_write("#{es}");//clear the screen
		}
		if(key_hit(KEY_DOWN)){
			Pause_State = 0;//goes to the first pause menu
			tte_write("#{es}");//clear the screen
			break;
		}
		if(key_hit(KEY_UP)){
			Pause_State = 0;//goes to the first pause menu
			tte_write("#{es}");//clear the screen
			break;
		}
		break;
	}
}
void Mission()
{
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	tte_write("#{P:72,140}");//text:
	tte_write("#{cx:0x3000} ->Start<-    ");
	
	if(key_hit(KEY_START))//waits for input
	{
		Start();//initializes enemies
		Game_State = 1;//goes to teh first level
		tte_write("#{es}");//clear the screen
	}
}
void Instructions()
{
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	tte_write("#{P:70,140}");//text:
	tte_write("#{cx:0x3000} ->Menu<-    ");
	
	if(key_hit(KEY_START))//waits for input
	{
		reset();//resets all needed values
		Game_State = 0;//goes to the menu
		tte_write("#{es}");//clear the screen
	}
}
void WinScreen()
{
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	tte_write("#{P:72,140}");//text:
	tte_write("#{cx:0x3000} ->Start<-    ");
	
	if(key_hit(KEY_START))//waits for input
	{
		Game_State = 3;//goes to the game over screen
		tte_write("#{es}");//clear the screen
	}
}

void Credits() {
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	tte_write("#{P:70,140}");//text:
	tte_write("#{cx:0x3000} ->Menu<-    ");
	
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 |DCNT_BG1 ;//tells the game what to show
	if(key_hit(KEY_START))//waits for input
	{
		tte_write("#{es}");//clear the screen
		Game_State = 0;//goes to the menu
	}
}
void EnemyMove()
{
	for(place = 0; place <= NUMBER_OF_H -1; place++) //loops through Soldats
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false) //checks if they are alive and direction
		{
			if (Soldat[place].y < 152) //checks the position of the soldat
			{
				if (Soldat[place].movementcounter == true) //checks if it is time to move
				{
					Soldat[place].y++;//moves down
					Soldat[place].movementcounter = false;//changes the bool
				}
				else
				{
					Soldat[place].movementcounter = true;//changes the bool
				}
			}
			else if (Soldat[place].y > 151)//checks the position of the soldat
			{
				if (Soldat[place].left == false) //checks the direction
				{
					if (Soldat[place].i < 16) //checks a counter
					{
						Soldat[place].x++; //moves on the X axis
						Soldat[place].i++; //increases counter
					}
					else
					{
						Soldat[place].up = true;//changes the direction fo movement
						Soldat[place].i=0;	//resets counter
					}
				}
				else
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x--;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].up = true;//changes the direction fo movement
						Soldat[place].i=0;	//resets counter
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)//checks if they are alive and direction
		{
			if(Soldat[place].y > 0)//checks the position of the soldat
			{
				if (Soldat[place].movementcounter == true)//checks if it is time to move
				{
					Soldat[place].y--;//moves up
					Soldat[place].movementcounter = false;//changes the bool
				}
				else
				{
					Soldat[place].movementcounter = true;//changes the bool
				}
			}
			else if (Soldat[place].y < 1)//checks the position of the soldat
			{
				if (Soldat[place].left == false)//checks the direction
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x++;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].i=0;	//resets counter
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x--;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].i=0;	//resets counter
						Soldat[place].up = false;
					}
				}
				

			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates Soldat position
		}
		if (Soldat[place].x == 108)//checks the position of the soldat
		{
			Soldat[place].alive = false;//kills the hiamster
			Soldat[place].i = 0;//resets counter
			if (life == 3)//checks life
			{
				life = 1;//changes it accordingly
				Princess[1].alive= false;//kills the hiamster
				Princess[1].x= 0;//changes x of Princess
				Princess[1].y= -8;//changes y of Princess
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);//updates princess position
			}
			else
			{
				life = 0;//changes life accordingly
				if (killcounter >= 100){Game_State = 9;}//cehcks kills to determine what screen to load (9 = win 3 = game over)
				else{Game_State = 3;}
			}
		}
		if (Soldat[place].x == 124)//checks the position of the soldat
		{
			Soldat[place].alive = false;//kills the hiamster
			Soldat[place].i = 0;//resets counter
			if (life == 3)//checks life
			{
				life = 2;//changes it accordingly
				Princess[0].alive= false;//kills the hiamster
				Princess[0].x= 0;//changes x of Princess
				Princess[0].y= -8;//changes y of Princess
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);//updates princess position
			}
			else
			{
				life = 0;//changes life accordingly
				if (killcounter >= 100){Game_State = 9;}//cehcks kills to determine what screen to load (9 = win 3 = game over)
				else{Game_State = 3;}
			}
			Soldat[place].x= 0;//changes x of Soldat
			Soldat[place].y= -8;//changes y of Soldat
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position	
	}
	for(place = 0; place <= NUMBER_OF_M -1; place++) //loops through muskateers
	{
		
		if (Musketeer[place].alive == true && Musketeer[place].up == false)//checks if they are alive and direction
		{
			if (Musketeer[place].y < 152)//checks the position of the muskateer
			{
				Musketeer[place].y++;//moves down
			}
			else if (Musketeer[place].y > 151)//checks the position of the muskateer
			{
				if (Musketeer[place].left == false)//checks direction
				{
					if (Musketeer[place].i < 16) //checks counter
					{
						Musketeer[place].x++;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].up = true; //changes direction
						Musketeer[place].i=0;	//resets counter
					}
				}
				else
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x--;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].up = true;//changes direction
						Musketeer[place].i=0;	//resets counter
					}
				}
			}
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		else if (Musketeer[place].alive == true && Musketeer[place].up == true)//checks if they are alive and direction
		{
			if(Musketeer[place].y > 0)//checks the position of the muskateer
			{
				Musketeer[place].y--;//moves up
			}
			else if (Musketeer[place].y < 1)//checks the position of the muskateer
			{
				if (Musketeer[place].left == false)//checks direction
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x++;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].i=0;	//resets counter
						Musketeer[place].up = false;//changes direction
					}
				}
				else
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x--;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].i=0;	//resets counter
						Musketeer[place].up = false;//changes direction
					}
				}
				

			}
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		if (Musketeer[place].x == 108)//checks Muskateer position
		{
			Musketeer[place].alive = false; //sets the Muskateer to be dead(can't move)
			Musketeer[place].i = 0;//resets counter
			if (life == 3)//checks life state
			{
				life = 1;//changes life state
				Princess[1].alive= false;//sets the princess to be dead
				Princess[1].x= 0;//changes princess x
				Princess[1].y= -8;//changes princess y
				obj_set_pos(Princess[1].Sprite, Princess[1].x, Princess[1].y);
			}
			else
			{
				life = 0;//changes life state
				if (killcounter >= 100){Game_State = 9;}//cehcks kills to determine what screen to load (9 = win 3 = game over)
				else{Game_State = 3;}
			}
		}
		if (Musketeer[place].x == 124)//checks Muskateer position
		{
			Musketeer[place].alive = false;//sets the Muskateer to be dead
			Musketeer[place].i = 0;//resets counter
			if (life == 3)
			{
				life = 2;//changes life state
				Princess[0].alive= false;//sets the princess to be dead
				Princess[0].x= 0;//changes princess x
				Princess[0].y= -8;//changes princess y
				obj_set_pos(Princess[0].Sprite, Princess[0].x, Princess[0].y);
			}
			else
			{
				life = 0;//changes life state
				if (killcounter >= 100){Game_State = 9;}//cehcks kills to determine what screen to load (9 = win 3 = game over)
				else{Game_State = 3;}
			}
			Musketeer[place].x= 0;//changes Musketeer x
			Musketeer[place].y= -8;//changes Musketeer y
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
			
		}
		
		
		obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);	//updates Muskateer position
	}
	if (life == 2)//checks life state
	{
		for (place = 0; place <= NUMBER_OF_H;place++) //loops through the Soldats
		{
			if (Soldat[place].left == true)//which are moving left
			{
			Soldat[place].alive = false;//kills them
			Soldat[place].x= 0;//change Soldat x
			Soldat[place].y= -8;//change Soldat y
			Soldat[place].i = 0;//resets counter
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates Soldat position
			}
		}
		for (place = 0; place <= NUMBER_OF_M;place++)//loops through the Muskateers
		{
			if (Musketeer[place].left == true)//which are moving left
			{
			Musketeer[place].alive = false;//kills them
			Musketeer[place].x= 0;//change Muskateer x
			Musketeer[place].y= -8;//change Muskateer y
			Musketeer[place].i = 0;//resets counter
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
			}
		}
	}
	else if (life == 1)//checks life state
	{
		for (place = 0; place <= NUMBER_OF_H;place++)//loops through the Soldats
		{
			if (Soldat[place].left == false)//which are moving right
			{
			Soldat[place].alive = false;//kills them
			Soldat[place].x= 0;//change Soldat x
			Soldat[place].y= -8;//change Soldat y
			Soldat[place].i = 0;//resets counter
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates Soldat position
			}
		}
		for (place = 0; place <= NUMBER_OF_M;place++)//loops through the Muskateers
		{
			if (Musketeer[place].left == false)//which are moving right
			{
			Musketeer[place].alive = false;
			Musketeer[place].x= 0;//change Muskateer x
			Musketeer[place].y= -8;//change Muskateer y
			Musketeer[place].i = 0;//resets counter
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
			}
		}
	}
}
void BulletCollision()
{
		if(bullet.alive == true) //checks if the bullet exists
		{
			if(bullet.left == true)//and is going left
			{
				bullet.x-= 2; //goes left
				if(bullet.x < -8){
					bullet.alive = false;//destroy the bullet when it goes out of the screen
				}
			}
			else//right
			{
				bullet.x+= 2;//goes right
			
				if(bullet.x > 248){
					bullet.alive = false;//destroy the bullet when it goes out of the screen
				}
			}
			for(place = 0; place <= NUMBER_OF_H -1; place++) { //loops through the soldats
				if(bullet.x <= Soldat[place].x + 8 && bullet.x > Soldat[place].x && bullet.y <= Soldat[place].y + 8 && bullet.y > Soldat[place].y)//checks if the bullet and Soldats collide
				{
					bullet.alive = false;//destroy the bullet
					bullet.x = -5;//change bulelt x
					bullet.y = -5;//change bulelt y
					Soldat[place].i = 0;//resets counter
					Soldat[place].alive = false;//kills hiamster
					if (Soldat[place].x == 0 || Soldat[place].x == 232)//checks Soldat position and gives score accordingly:
					//#row 1
					{
						score += 50;
					}
					else if(Soldat[place].x == 16 || Soldat[place].x == 216)//#row 2
					{
						score += 45;
					}
					else if(Soldat[place].x == 32 || Soldat[place].x == 200)//#row 3
					{
						score += 35;
					}
					else if(Soldat[place].x == 48 || Soldat[place].x == 184)//#row 4
					{
						score += 30;
					}
					else if(Soldat[place].x == 64 || Soldat[place].x == 168)//#row 5
					{
						score += 25;
					}
					else if(Soldat[place].x == 80 || Soldat[place].x == 152)//#row 6
					{
						score += 20;
					}
					else //bottom adn top of the screen where hiamsters are easier to hit
					{
						score += 5;
					}
					killcounter++;//increases the number of kills
					Soldat[place].x= 0;//changes Soldat x
					Soldat[place].y= -8;//changes Soldat y
					obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//Uptates Soldat position
					SpawnPowerup();//checks if a powerup should spawn
					CheckKills();//checks if the leves should be changed
				}
			}
			for(place = 0; place <= NUMBER_OF_M -1; place++) {//loops through the Muskateers
				if(bullet.x <= Musketeer[place].x + 8 && bullet.x > Musketeer[place].x && bullet.y <= Musketeer[place].y + 8 && bullet.y > Musketeer[place].y)//checks if the bullet and Muskateers collide
				{
					bullet.alive = false;//destroy the bullet
					bullet.x = -5;//change bulelt x
					bullet.y = -5;//change bulelt y
					Musketeer[place].i = 0;//resets counter
					Musketeer[place].alive = false;//kills hiamster
					if (Musketeer[place].x == 0 || Musketeer[place].x == 232)//checks Soldat position and gives score accordingly:
					//#row 1
					{
						score += 500;
					}
					else if(Musketeer[place].x == 16 || Musketeer[place].x == 216)//#row 2
					{
						score += 450;
					}
					else if(Musketeer[place].x == 32 || Musketeer[place].x == 200)//#row 3
					{
						score += 350;
					}
					else if(Musketeer[place].x == 48 || Musketeer[place].x == 184)//#row 4
					{
						score += 300;
					}
					else if(Musketeer[place].x == 64 || Musketeer[place].x == 168)//#row 5
					{
						score += 250;
					}
					else if(Musketeer[place].x == 80 || Musketeer[place].x == 152)//#row 6
					{
						score += 200;
					}
					else//bottom adn top of the screen where hiamsters are easier to hit
					{
						score += 50;
					}
					killcounter++;//increases the number of kills
					Musketeer[place].x= 0;//changes Musketeer x
					Musketeer[place].y= -8;//changes Musketeer y
					obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//Uptates Musketeer position
					SpawnPowerup();//checks if a powerup should spawn
					CheckKills();//checks if the leves should be changed
				}
			}		
			obj_set_pos(Bullet, bullet.x, bullet.y);//updates bullet position
	}
}
void shoot()
{
	Bullet= &obj_buffer[1]; 
	obj_set_attr(Bullet, //sets bullet attributes
	ATTR0_SQUARE,                // Square, regular sprite
	ATTR1_SIZE_8,                    // 8x8p, 
	ATTR2_PALBANK(0) | 4);
	if(bullet.alive == false){//checks if a bullet exists
		bullet.left = lookLeft; //set the direction of the bullet
		bullet.alive = true;//make the bullet alive
		bullet.x = x;//change bullet x
		bullet.y = y + 3;//change bullet y
		obj_set_pos(Bullet, bullet.x, bullet.y);//update bullet position
	}
	if(lookLeft){
		Bullet->attr1 ^= ATTR1_HFLIP;//set the direction of the bullet
	}
}
void iddle()
{
	tte_write("#{es}");//clear the screen of text
	if(MenuSceneCooldown <1)//checks if it is time to change the background
	{
		choseIddle = rand()%4;//gets a background at random
		MenuSceneCooldown = 500;//resets the cooldown
	}
	else{MenuSceneCooldown--;}//counts down
	
	if (choseIddle == 0){LoadLevel_1();}//determines which background to load
	else if (choseIddle == 1){LoadLevel_2();}
	else if (choseIddle == 2){LoadLevel_3();}
	else{LoadLevel_4();}
	
	if (loadder==1)//checks if the assets have been initialized
	{
	initializeSoldat();//initializes the soldats
	initializeMusketeer();//initializes the muskateers
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1|DCNT_OBJ | DCNT_OBJ_1D; //tells the game what to load
    loadder++; //makes it so that this will not be initialized again
	}
	vid_vsync();//syncs the video
	key_poll();// listens for key input
	
	r = rand()%2; //sets random to be 1 or 0
	SpawnPrincess();
	SpawnEnemy();

for(place = 0; place <= NUMBER_OF_H -1; place++) //loops through Soldats
	{
		
		if (Soldat[place].alive == true && Soldat[place].up == false) //checks if they are alive and direction
		{
			if (Soldat[place].y < 152) //checks the position of the soldat
			{
				if (Soldat[place].movementcounter == true) //checks if it is time to move
				{
					Soldat[place].y++;//moves down
					Soldat[place].movementcounter = false;//changes the bool
				}
				else
				{
					Soldat[place].movementcounter = true;//changes the bool
				}
			}
			else if (Soldat[place].y > 151)//checks the position of the soldat
			{
				if (Soldat[place].left == false) //checks the direction
				{
					if (Soldat[place].i < 16) //checks a counter
					{
						Soldat[place].x++; //moves on the X axis
						Soldat[place].i++; //increases counter
					}
					else
					{
						Soldat[place].up = true;//changes the direction fo movement
						Soldat[place].i=0;	//resets counter
					}
				}
				else
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x--;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].up = true;//changes the direction fo movement
						Soldat[place].i=0;	//resets counter
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position
		}
		else if (Soldat[place].alive == true && Soldat[place].up == true)//checks if they are alive and direction
		{
			if(Soldat[place].y > 0)//checks the position of the soldat
			{
				if (Soldat[place].movementcounter == true)//checks if it is time to move
				{
					Soldat[place].y--;//moves up
					Soldat[place].movementcounter = false;//changes the bool
				}
				else
				{
					Soldat[place].movementcounter = true;//changes the bool
				}
			}
			else if (Soldat[place].y < 1)//checks the position of the soldat
			{
				if (Soldat[place].left == false)//checks the direction
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x++;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].i=0;	//resets counter
						Soldat[place].up = false;
					}
				}
				else
				{
					if (Soldat[place].i < 16)//checks a counter
					{
						Soldat[place].x--;//moves on the X axis
						Soldat[place].i++;//increases counter
					}
					else
					{
						Soldat[place].i=0;	//resets counter
						Soldat[place].up = false;
					}
				}
			}
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates Soldat position
		}
		if (Soldat[place].x == 108)//checks the position of the soldat
		{
			Soldat[place].alive = false;//kills the hiamster
			Soldat[place].i = 0;//resets counter
			Soldat[place].x= 0;//changes x of Soldat
			Soldat[place].y= -8;//changes y of Soldat
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position
		}
		if (Soldat[place].x == 124)//checks the position of the soldat
		{
			Soldat[place].alive = false;//kills the hiamster
			Soldat[place].i = 0;//resets counter
			Soldat[place].x= 0;//changes x of Soldat
			Soldat[place].y= -8;//changes y of Soldat
			obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position
			
		}
		
		
		obj_set_pos(Soldat[place].Sprite, Soldat[place].x, Soldat[place].y);//updates soldat position	
	}
	for(place = 0; place <= NUMBER_OF_M -1; place++) //loops through muskateers
	{
		
		if (Musketeer[place].alive == true && Musketeer[place].up == false)//checks if they are alive and direction
		{
			if (Musketeer[place].y < 152)//checks the position of the muskateer
			{
				Musketeer[place].y++;//moves down
			}
			else if (Musketeer[place].y > 151)//checks the position of the muskateer
			{
				if (Musketeer[place].left == false)//checks direction
				{
					if (Musketeer[place].i < 16) //checks counter
					{
						Musketeer[place].x++;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].up = true; //changes direction
						Musketeer[place].i=0;	//resets counter
					}
				}
				else
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x--;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].up = true;//changes direction
						Musketeer[place].i=0;	//resets counter
					}
				}
			}
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		else if (Musketeer[place].alive == true && Musketeer[place].up == true)//checks if they are alive and direction
		{
			if(Musketeer[place].y > 0)//checks the position of the muskateer
			{
				Musketeer[place].y--;//moves up
			}
			else if (Musketeer[place].y < 1)//checks the position of the muskateer
			{
				if (Musketeer[place].left == false)//checks direction
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x++;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].i=0;	//resets counter
						Musketeer[place].up = false;//changes direction
					}
				}
				else
				{
					if (Musketeer[place].i < 16)//checks counter
					{
						Musketeer[place].x--;//moves on the X axis
						Musketeer[place].i++;//increases counter
					}
					else
					{
						Musketeer[place].i=0;	//resets counter
						Musketeer[place].up = false;//changes direction
					}
				}
				

			}
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		if (Musketeer[place].x == 108)//checks Muskateer position
		{
			Musketeer[place].alive = false;//sets the Muskateer to be dead
			Musketeer[place].i = 0;//resets counter
			Musketeer[place].x= 0;//changes Musketeer x
			Musketeer[place].y= -8;//changes Musketeer y
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		if (Musketeer[place].x == 124)//checks Muskateer position
		{
			Musketeer[place].alive = false;//sets the Muskateer to be dead
			Musketeer[place].i = 0;//resets counter
			Musketeer[place].x= 0;//changes Musketeer x
			Musketeer[place].y= -8;//changes Musketeer y
			obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);//updates Muskateer position
		}
		obj_set_pos(Musketeer[place].Sprite, Musketeer[place].x, Musketeer[place].y);	//updates Muskateer position
	}


	oam_copy(oam_mem, obj_buffer, 128);    // only need to update one
	//checks for any input:
	if(key_hit(KEY_L)||key_hit(KEY_R)||key_hit(KEY_DOWN)||key_hit(KEY_UP)||key_hit(KEY_LEFT)||key_hit(KEY_RIGHT)||key_hit(KEY_START)||key_hit(KEY_SELECT)||key_hit(KEY_B)||key_hit(KEY_A))
	{
		reset();//resets all the needed variables
		Game_State = 0;//changes the game state (to the menu)
	}
}