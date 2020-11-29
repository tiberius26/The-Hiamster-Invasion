
//{{BLOCK(Instructions)

//======================================================================
//
//	Instructions, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 179 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 5728 + 2048 = 8288
//
//	Time-stamp: 2019-05-16, 15:41:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_INSTRUCTIONS_H
#define GRIT_INSTRUCTIONS_H

#define InstructionsTilesLen 5728
extern const unsigned short InstructionsTiles[2864];

#define InstructionsMapLen 2048
extern const unsigned short InstructionsMap[1024];

#define InstructionsPalLen 512
extern const unsigned short InstructionsPal[256];

#endif // GRIT_INSTRUCTIONS_H

//}}BLOCK(Instructions)
