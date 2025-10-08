#if !defined( TILE_MAP_H )
#define TILE_MAP_H

#include "common.h"
#include "vector.h"

#define TILE_TEXTURE_SIZE     32
#define TILE_TEXTURE_COUNT    128
#define TILE_TEXTURE_VOFFSET  8

#define TILEMAP_MAX_TILES     16384    // 128x128 tiles

typedef struct Screen_t Screen_t;

typedef struct TileTexture_t
{
   u8 pixels[TILE_TEXTURE_SIZE * TILE_TEXTURE_SIZE];
}
TileTexture_t;

typedef struct TileTextureSet_t
{
   TileTexture_t textures[TILE_TEXTURE_COUNT];
   u16* palette;
}
TileTextureSet_t;

typedef struct TileMap_t
{
   TileTextureSet_t tileTextureSet;

   // bits 0-6: tile texture index
   // bit 7: is passable
   // bits 8-31: reserved
   u32 tiles[TILEMAP_MAX_TILES];
   Vector2u32_t sizeInTiles;
}
TileMap_t;

#if defined( __cplusplus )
extern "C" {
#endif

void TileMap_Init( TileMap_t* tileMap, u16* palette, u8 transparentColorIndex );

// game_data.c
void TileMap_Load( TileMap_t* tileMap, Screen_t* screen );

#if defined( __cplusplus )
}
#endif

#endif // TILE_MAP_H
