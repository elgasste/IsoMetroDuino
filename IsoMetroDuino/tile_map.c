#include "tile_map.h"

void TileMap_Init( TileMap_t* tileMap, u16* palette, u8 transparentColorIndex )
{
   u32 i, j;

   tileMap->sizeInTiles.x = 0;
   tileMap->sizeInTiles.y = 0;

   for ( i = 0; i < TILE_TEXTURE_COUNT; i++ )
   {
      for ( j = 0; j < ( TILE_TEXTURE_SIZE * TILE_TEXTURE_SIZE ); j++ )
      {
         tileMap->tileTextureSet.textures[i].pixels[j] = transparentColorIndex;
      }
   }

   tileMap->tileTextureSet.palette = palette;
}
