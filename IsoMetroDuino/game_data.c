#include "tile_map.h"
#include "screen.h"

void TileMap_Load( TileMap_t* tileMap, Screen_t* screen )
{
   u32 i, j, ti;
   u8* memory;
   u8 tileColor = 1;

   // TODO: let's have two tile textures for now, so we can make a checkerboard and try to render it
   for ( i = 0; i < 2; i++ )
   {
      memory = (u8*)tileMap->tileTextureSet.textures[i].pixels;

      // top 16x32 pixels are transparent
      for ( j = 0; j < ( ( TILE_TEXTURE_SIZE / 2 ) * TILE_TEXTURE_SIZE ); j++ )
      {
         *memory = screen->transparentColorIndex;
         memory++;
      }

      // top half tapers up
      memory += 14; for ( j = 0; j < 4; j++ ) { *memory = tileColor; memory++; } memory += 14;
      memory += 12; for ( j = 0; j < 8; j++ ) { *memory = tileColor; memory++; } memory += 12;
      memory += 10; for ( j = 0; j < 12; j++ ) { *memory = tileColor; memory++; } memory += 10;
      memory += 8; for ( j = 0; j < 16; j++ ) { *memory = tileColor; memory++; } memory += 8;
      memory += 6; for ( j = 0; j < 20; j++ ) { *memory = tileColor; memory++; } memory += 6;
      memory += 4; for ( j = 0; j < 24; j++ ) { *memory = tileColor; memory++; } memory += 4;
      memory += 2; for ( j = 0; j < 28; j++ ) { *memory = tileColor; memory++; } memory += 2;
      for ( j = 0; j < 32; j++ ) { *memory = tileColor; memory++; }

      // bottom half tapers down
      for ( j = 0; j < 32; j++ ) { *memory = tileColor; memory++; }
      memory += 2; for ( j = 0; j < 28; j++ ) { *memory = tileColor; memory++; } memory += 2;
      memory += 4; for ( j = 0; j < 24; j++ ) { *memory = tileColor; memory++; } memory += 4;
      memory += 6; for ( j = 0; j < 20; j++ ) { *memory = tileColor; memory++; } memory += 6;
      memory += 8; for ( j = 0; j < 16; j++ ) { *memory = tileColor; memory++; } memory += 8;
      memory += 10; for ( j = 0; j < 12; j++ ) { *memory = tileColor; memory++; } memory += 10;
      memory += 12; for ( j = 0; j < 8; j++ ) { *memory = tileColor; memory++; } memory += 12;
      memory += 14; for ( j = 0; j < 4; j++ ) { *memory = tileColor; memory++; } memory += 14;

      tileColor = ( ( i % 2 ) == 1 ) ? 1 : 2;
   }

   // TODO: this is just an experimental tile map with alternating colors, and every square is passable
   tileMap->sizeInTiles.x = 128;
   tileMap->sizeInTiles.y = 128;

   for ( i = 0; i < tileMap->sizeInTiles.y; i++ )
   {
      ti = ( ( i % 2 ) == 0 ) ? 0 : 1;

      for ( j = 0; j < tileMap->sizeInTiles.y; j++ )
      {
         tileMap->tiles[( i * tileMap->sizeInTiles.x ) + j] = ( ti == 0 ) ? 0x80 : 0x81;
         ti = ( ti == 0 ) ? 1 : 0;
      }
   }
}