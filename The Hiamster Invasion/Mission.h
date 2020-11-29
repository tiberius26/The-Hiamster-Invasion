
//{{BLOCK(Mission)

//======================================================================
//
//	Mission, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 175 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 5600 + 2048 = 8160
//
//	Time-stamp: 2019-05-09, 15:40:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MISSION_H
#define GRIT_MISSION_H

#define MissionTilesLen 5600
extern const unsigned short MissionTiles[2800];

#define MissionMapLen 2048
extern const unsigned short MissionMap[1024];

#define MissionPalLen 512
extern const unsigned short MissionPal[256];

#endif // GRIT_MISSION_H

//}}BLOCK(Mission)
