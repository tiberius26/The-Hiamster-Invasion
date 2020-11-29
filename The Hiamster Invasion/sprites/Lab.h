
//{{BLOCK(Lab)

//======================================================================
//
//	Lab, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 4 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 128 + 2048 = 2688
//
//	Time-stamp: 2019-02-21, 14:57:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LAB_H
#define GRIT_LAB_H

#define LabTilesLen 128
extern const unsigned short LabTiles[64];

#define LabMapLen 2048
extern const unsigned short LabMap[1024];

#define LabPalLen 512
extern const unsigned short LabPal[256];

#endif // GRIT_LAB_H

//}}BLOCK(Lab)
