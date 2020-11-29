
//{{BLOCK(Credits)

//======================================================================
//
//	Credits, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 129 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 4128 + 2048 = 6688
//
//	Time-stamp: 2019-05-09, 15:40:42
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CREDITS_H
#define GRIT_CREDITS_H

#define CreditsTilesLen 4128
extern const unsigned short CreditsTiles[2064];

#define CreditsMapLen 2048
extern const unsigned short CreditsMap[1024];

#define CreditsPalLen 512
extern const unsigned short CreditsPal[256];

#endif // GRIT_CREDITS_H

//}}BLOCK(Credits)
