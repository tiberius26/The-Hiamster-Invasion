
//{{BLOCK(WinScreen)

//======================================================================
//
//	WinScreen, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 243 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 7776 + 2048 = 10336
//
//	Time-stamp: 2019-05-09, 15:40:28
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WINSCREEN_H
#define GRIT_WINSCREEN_H

#define WinScreenTilesLen 7776
extern const unsigned short WinScreenTiles[3888];

#define WinScreenMapLen 2048
extern const unsigned short WinScreenMap[1024];

#define WinScreenPalLen 512
extern const unsigned short WinScreenPal[256];

#endif // GRIT_WINSCREEN_H

//}}BLOCK(WinScreen)
