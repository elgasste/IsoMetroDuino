#include "game.h"

internal void Game_Draw( Game_t* game );

void Game_Init( Game_t* game, u16* screenBuffer )
{
   Clock_Init( &game->clock );
   Screen_Init( &game->screen, screenBuffer );
   Input_Init( &game->input );
   TileMap_Init( &game->tileMap, game->screen.palette, game->screen.transparentColorIndex );
   TileMap_Load( &game->tileMap, &game->screen );
}

void Game_Tic( Game_t* game )
{
   Input_Read( &game->input );
   Game_Draw( game );
}

internal void Game_Draw( Game_t* game )
{
   u32 row, col, numCols, x, ti;
   Bool_t offsetCol;

   Screen_WipeColor( &game->screen, COLOR_BLUE );

   // TODO: we can maybe test performance with this, but eventually we'll need to draw the tile map
   for ( row = 0; ( row * TILE_TEXTURE_VOFFSET ) <= ( SCREEN_HEIGHT - TILE_TEXTURE_SIZE ); row++ )
   {
      if ( row % 2 == 0 )
      {
         numCols = SCREEN_WIDTH / TILE_TEXTURE_SIZE;
         offsetCol = False;
      }
      else
      {
         numCols = ( SCREEN_WIDTH / TILE_TEXTURE_SIZE ) - 1;
         offsetCol = True;
      }

      ti = 0;

      for ( col = 0; col < numCols; col++ )
      {
         x = offsetCol ? ( ( col * TILE_TEXTURE_SIZE ) + ( TILE_TEXTURE_SIZE / 2 ) ) : ( col * TILE_TEXTURE_SIZE );
         Screen_DrawMemorySection( &game->screen, (u8*)game->tileMap.tileTextureSet.textures[ti].pixels,
                                   0, 0, TILE_TEXTURE_SIZE,
                                   TILE_TEXTURE_SIZE, TILE_TEXTURE_SIZE,
                                   x, row * TILE_TEXTURE_VOFFSET );
         ti = ( ti == 0 ) ? 1 : 0;
      }
   }

   Screen_RenderBuffer( &game->screen );
}
