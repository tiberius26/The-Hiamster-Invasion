
//{{BLOCK(goodBG)

//======================================================================
//
//	goodBG, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 21 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 672 + 2048 = 3232
//
//	Time-stamp: 2019-02-21, 14:38:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GOODBG_H
#define GRIT_GOODBG_H

#define goodBGTilesLen 672
extern const unsigned short goodBGTiles[336];

#define goodBGMapLen 2048
extern const unsigned short goodBGMap[1024];

#define goodBGPalLen 512
extern const unsigned short goodBGPal[256];

#endif // GRIT_GOODBG_H

//}}BLOCK(goodBG)
