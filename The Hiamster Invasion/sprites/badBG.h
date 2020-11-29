
//{{BLOCK(badBG)

//======================================================================
//
//	badBG, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 2 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 64 + 2048 = 2624
//
//	Time-stamp: 2019-01-10, 15:27:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BADBG_H
#define GRIT_BADBG_H

#define badBGTilesLen 64
extern const unsigned short badBGTiles[32];

#define badBGMapLen 2048
extern const unsigned short badBGMap[1024];

#define badBGPalLen 512
extern const unsigned short badBGPal[256];

#endif // GRIT_BADBG_H

//}}BLOCK(badBG)
