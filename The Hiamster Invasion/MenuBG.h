
//{{BLOCK(MenuBG)

//======================================================================
//
//	MenuBG, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 65 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 2080 + 2048 = 4640
//
//	Time-stamp: 2019-02-21, 16:43:23
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENUBG_H
#define GRIT_MENUBG_H

#define MenuBGTilesLen 2080
extern const unsigned short MenuBGTiles[1040];

#define MenuBGMapLen 2048
extern const unsigned short MenuBGMap[1024];

#define MenuBGPalLen 512
extern const unsigned short MenuBGPal[256];

#endif // GRIT_MENUBG_H

//}}BLOCK(MenuBG)
