#include "screen.h"

#define PLOT_PIXEL( b, x, y, c ) b[( ( y ) * SCREEN_WIDTH ) + ( x )] = c

void Screen_Init( Screen_t* screen, u16* buffer )
{
   u32 i;

   screen->buffer = buffer;

   for ( i = 0; i < SCREEN_PALETTE_SIZE; i++ )
   {
      screen->palette[i] = COLOR_BLACK;
   }

   screen->palette[0] = COLOR_PINK;
   screen->palette[1] = COLOR_WHITE;
   screen->palette[2] = COLOR_RED;
   screen->palette[3] = COLOR_GREEN;
   screen->palette[4] = COLOR_BLUE;
   screen->palette[5] = COLOR_MAGENTA;
   screen->palette[6] = COLOR_YELLOW;
   screen->palette[7] = COLOR_CYAN;

   screen->transparentColorIndex = 0;
}

void Screen_WipeColor( Screen_t* screen, u16 color )
{
   u32 i;
   u16* bufferPos = screen->buffer;

   for ( i = 0; i < SCREEN_PIXELS; i++ )
   {
      *bufferPos = color;
      bufferPos++;
   }
}

void Screen_DrawMemorySection( Screen_t* screen, u8* memory, u32 mx, u32 my, u32 ms, u32 mw, u32 mh, u32 sx, u32 sy )
{
   u8 colorIndex;
   u32 x, y;
   u16* bufferPos = &screen->buffer[( sy * SCREEN_WIDTH ) + sx];
   u8* memoryPos = &memory[( my * ms ) + mx];

   for ( y = 0; y < mh; y++ )
   {
      for ( x = 0; x < mw; x++ )
      {
         colorIndex = *memoryPos;

         if ( colorIndex != screen->transparentColorIndex )
         {
            PLOT_PIXEL( screen->buffer, sx + x, sy + y, screen->palette[colorIndex] );
         }

         memoryPos++;
      }

      bufferPos += SCREEN_WIDTH;
      memoryPos += ( ms - mw );
   }
}