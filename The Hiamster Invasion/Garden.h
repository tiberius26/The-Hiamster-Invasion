
//{{BLOCK(Garden)

//======================================================================
//
//	Garden, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 45 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 1440 + 2048 = 4000
//
//	Time-stamp: 2019-02-21, 15:27:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GARDEN_H
#define GRIT_GARDEN_H

#define GardenTilesLen 1440
extern const unsigned short GardenTiles[720];

#define GardenMapLen 2048
extern const unsigned short GardenMap[1024];

#define GardenPalLen 512
extern const unsigned short GardenPal[256];

#endif // GRIT_GARDEN_H

//}}BLOCK(Garden)
