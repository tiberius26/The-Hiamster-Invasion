
//{{BLOCK(GameOverBG)

//======================================================================
//
//	GameOverBG, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 29 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 928 + 2048 = 3488
//
//	Time-stamp: 2019-04-04, 16:03:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAMEOVERBG_H
#define GRIT_GAMEOVERBG_H

#define GameOverBGTilesLen 928
extern const unsigned short GameOverBGTiles[464];

#define GameOverBGMapLen 2048
extern const unsigned short GameOverBGMap[1024];

#define GameOverBGPalLen 512
extern const unsigned short GameOverBGPal[256];

#endif // GRIT_GAMEOVERBG_H

//}}BLOCK(GameOverBG)
