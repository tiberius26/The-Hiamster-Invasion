
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

const unsigned short GardenTiles[720] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
	0xF022,0x33F0,0x0222,0x333F,0xF022,0x3333,0x0222,0x333F,
	0x0222,0x333F,0xF022,0x3333,0x0222,0x333F,0xF022,0x33F0,
	0x8333,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x8878,0x8833,0x8888,0x8833,0x8888,

	0x8388,0x3888,0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,
	0x8888,0x3888,0x8888,0x3888,0x8888,0x3388,0x8888,0x3388,
	0x0223,0x3F0F,0x2223,0x33F0,0x0223,0x333F,0x2223,0x33F0,
	0x2223,0x33F0,0x0223,0x333F,0x2223,0x33F0,0x0223,0x3F0F,
	0xF322,0x33F3,0x0222,0x333F,0xF022,0x3333,0x0222,0x333F,
	0x0222,0x333F,0xF022,0x3333,0x0222,0x333F,0xF022,0x33F0,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8333,0x8888,
	0x8333,0x8880,0x8333,0x8888,0x8333,0x8888,0x8833,0x8888,

	0x8888,0x3388,0x8888,0x3388,0x7788,0x3388,0x8888,0x3338,
	0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,
	0x2233,0xF0F0,0x2233,0x3F02,0x2233,0x33F0,0x2233,0x3F02,
	0x2233,0x3F02,0x2233,0x33F0,0x2233,0x3F02,0x2233,0xF0F0,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x7888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x8888,0x8883,0x8088,0x8883,0x8888,
	0x8888,0x3338,0x8888,0x3338,0x0888,0x3338,0x8888,0x3338,
	0x8888,0x3338,0x8888,0x3338,0x8888,0x3388,0x8888,0x3388,

	0x8883,0x8888,0x8883,0x8888,0x8883,0x8888,0x8883,0x8888,
	0x8883,0x8888,0x8883,0x7888,0x8833,0x8888,0x8833,0x8888,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3378,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x7888,0x8833,0x8888,0x8833,0x8888,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3380,0x8888,0x3388,

	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x8088,0x8333,0x8888,0x8333,0x8888,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x8888,0x3888,0x8888,0x3888,0x8887,0x3888,
	0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,0x7333,0x8888,
	0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,
	0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,0x8888,0x3887,

	0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8888,0x3888,0x8888,0x3888,0x8880,0x3888,0x8888,0x3888,
	0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,0x8888,0x3888,
	0x8333,0x8878,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,
	0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,
	0x8888,0x3888,0x8888,0x3888,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x0888,0x3388,0x8888,0x3388,0x8888,0x3388,

	0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,
	0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,
	0x8888,0x3378,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x8880,0x3388,0x8888,0x3388,0x8788,0x3388,
	0x3333,0x8888,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8333,0x8878,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3338,0x8888,0x3338,
	0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,

	0x8333,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8333,0x8888,
	0x8888,0x3333,0x8888,0x3333,0x8888,0x3338,0x8808,0x3338,
	0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,
	0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8333,0x8888,0x8333,0x8888,0x8333,0x0888,0x8333,0x8888,
	0x8333,0x8888,0x8333,0x8888,0x8833,0x8888,0x8833,0x7888,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,

	0x8878,0x3338,0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,
	0x8888,0x3338,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8833,0x8888,0x8833,0x8888,0x8333,0x8888,0x3333,0x8888,
	0x3333,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8880,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,
	0x8833,0x8888,0x8833,0x8888,0x8833,0x8888,0x8833,0x8088,

	0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8888,0x3333,0x8887,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8833,0x8888,0x8833,0x8888,0x8333,0x8888,0x8333,0x8888,
	0x8333,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x0883,0x8887,
	0x8883,0x8888,0x8883,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x3333,0x8887,0x3333,0x8888,0x3333,0x8888,0x3333,
	0x8888,0x3338,0x8888,0x3338,0x8888,0x3338,0x8888,0x3388,

	0x2233,0xF0F0,0x2233,0x3F02,0x2233,0x33F0,0x2233,0x3F02,
	0x2233,0x3F02,0x2233,0x33F0,0x2233,0x3F02,0x2233,0xF3F3,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8808,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8880,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3387,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8880,0x3388,
	0x8888,0x7888,0x0088,0x8888,0x8883,0x8888,0x8883,0x8888,
	0x8883,0x8888,0x8883,0x8888,0x8883,0x8888,0x8883,0x8888,

	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
	0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,0x8888,0x3388,
};

const unsigned short GardenMap[1024] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0001,0x0001,0x0001,0x0002,0x0001,0x0001,
	0x0001,0x0002,0x0001,0x0001,0x0001,0x0002,0x0003,0x0004,
	0x0001,0x0001,0x0002,0x0001,0x0001,0x0001,0x0002,0x0001,
	0x0001,0x0001,0x0002,0x0001,0x0001,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0006,0x0001,0x0005,0x0001,0x0006,
	0x0001,0x0005,0x0001,0x0006,0x0001,0x0005,0x0007,0x0008,
	0x0006,0x0001,0x0005,0x0001,0x0006,0x0001,0x0005,0x0001,
	0x0006,0x0001,0x0005,0x0001,0x0006,0x0001,0x0000,0x0000,

	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,
	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x000A,0x000B,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x000C,0x000D,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0000,0x0000,

	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,
	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x000E,0x000F,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0010,0x0011,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0000,0x0000,

	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,
	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0012,0x0013,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0014,0x0015,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0000,0x0000,

	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,
	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0016,0x0017,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0018,0x0019,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0000,0x0000,

	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,
	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x001A,0x001B,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x001C,0x001D,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0000,0x0000,

	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,
	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x001E,0x0414,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x001F,0x0020,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0000,0x0000,

	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,
	0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0021,0x0022,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,
	0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,0x0009,
	0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0023,0x0024,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0005,0x0001,
	0x0009,0x0001,0x0005,0x0001,0x0009,0x0001,0x0000,0x0000,

	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,
	0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0025,0x0418,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,
	0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,0x0002,
	0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0026,0x0027,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0005,0x0001,
	0x0002,0x0001,0x0005,0x0001,0x0002,0x0001,0x0000,0x0000,

	0x0001,0x0028,0x0001,0x0005,0x0001,0x0028,0x0001,0x0005,
	0x0001,0x0028,0x0001,0x0005,0x0001,0x0028,0x0029,0x002A,
	0x0005,0x0001,0x0028,0x0001,0x0005,0x0001,0x0028,0x0001,
	0x0005,0x0001,0x0028,0x0001,0x0005,0x0001,0x0000,0x0000,
	0x0001,0x0001,0x0001,0x0009,0x0001,0x0001,0x0001,0x0009,
	0x0001,0x0001,0x0001,0x0009,0x0001,0x0001,0x002B,0x002C,
	0x0009,0x0001,0x0001,0x0001,0x0009,0x0001,0x0001,0x0001,
	0x0009,0x0001,0x0001,0x0001,0x0009,0x0001,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

const unsigned short GardenPal[256] __attribute__((aligned(4)))=
{
	0x0000,0x0010,0x0200,0x0210,0x4000,0x4010,0x4200,0x6318,
	0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF,
	0x0004,0x0007,0x000B,0x000F,0x0013,0x0017,0x001B,0x001F,
	0x0080,0x00E0,0x0160,0x01E0,0x0260,0x02E0,0x0360,0x03E0,
	0x0084,0x00E7,0x016B,0x01EF,0x0273,0x02F7,0x037B,0x03FF,
	0x1000,0x1C00,0x2C00,0x3C00,0x4C00,0x5C00,0x6C00,0x7C00,
	0x1004,0x1C07,0x2C0B,0x3C0F,0x4C13,0x5C17,0x6C1B,0x7C1F,
	0x1080,0x1CE0,0x2D60,0x3DE0,0x4E60,0x5EE0,0x6F60,0x7FE0,

	0x0842,0x0C63,0x14A5,0x1CE7,0x2529,0x2D6B,0x35AD,0x3DEF,
	0x4631,0x4E73,0x56B5,0x5EF7,0x6739,0x6F7B,0x77BD,0x7FFF,
	0x001F,0x007F,0x00FF,0x017F,0x01FF,0x027F,0x02FF,0x037F,
	0x03FF,0x03FC,0x03F8,0x03F4,0x03F0,0x03EC,0x03E8,0x03E4,
	0x03E0,0x0FE0,0x1FE0,0x2FE0,0x3FE0,0x4FE0,0x5FE0,0x6FE0,
	0x7FE0,0x7F80,0x7F00,0x7E80,0x7E00,0x7D80,0x7D00,0x7C80,
	0x7C00,0x7C03,0x7C07,0x7C0B,0x7C0F,0x7C13,0x7C17,0x7C1B,
	0x7C1F,0x701F,0x601F,0x501F,0x401F,0x301F,0x201F,0x101F,

	0x001F,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0421,0x0842,0x0C63,0x1084,0x14A5,0x18C6,0x1CE7,
	0x2108,0x2529,0x294A,0x2D6B,0x318C,0x35AD,0x39CE,0x3DEF,
	0x4210,0x4631,0x4A52,0x4E73,0x5294,0x56B5,0x5AD6,0x5EF7,
	0x6318,0x6739,0x6B5A,0x6F7B,0x739C,0x77BD,0x7BDE,0x7FFF,
};

//}}BLOCK(Garden)
