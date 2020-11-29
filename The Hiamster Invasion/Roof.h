
//{{BLOCK(Roof)

//======================================================================
//
//	Roof, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 6 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 192 + 2048 = 2752
//
//	Time-stamp: 2019-02-21, 15:40:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROOF_H
#define GRIT_ROOF_H

#define RoofTilesLen 192
extern const unsigned short RoofTiles[96];

#define RoofMapLen 2048
extern const unsigned short RoofMap[1024];

#define RoofPalLen 512
extern const unsigned short RoofPal[256];

#endif // GRIT_ROOF_H

//}}BLOCK(Roof)
