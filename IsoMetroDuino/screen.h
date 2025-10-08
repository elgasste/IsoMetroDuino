#if !defined( SCREEN_H )
#define SCREEN_H

#include "common.h"

#define SCREEN_WIDTH                   256
#define SCREEN_HEIGHT                  192
#define SCREEN_PIXELS                  ( SCREEN_WIDTH * SCREEN_HEIGHT )

#define SCREEN_PALETTE_SIZE            256

#define COLOR_BLACK                    0x0000
#define COLOR_WHITE                    0xFFFF
#define COLOR_RED                      0xF800
#define COLOR_GREEN                    0x07E0
#define COLOR_BLUE                     0x001F
#define COLOR_MAGENTA                  0xF81F
#define COLOR_YELLOW                   0xFFE0
#define COLOR_CYAN                     0x07FF
#define COLOR_PINK                     0xFD0F

typedef struct Screen_t
{
   u16* buffer;
   u16 palette[SCREEN_PALETTE_SIZE];
   u8 transparentColorIndex;
}
Screen_t;

#if defined( __cplusplus )
extern "C" {
#endif

void Screen_Init( Screen_t* screen, u16* buffer );
void Screen_WipeColor( Screen_t* screen, u16 color );
void Screen_DrawMemorySection( Screen_t* screen, u8* memory, u32 mx, u32 my, u32 ms, u32 mw, u32 mh, u32 sx, u32 sy );

// platform-specific
void Screen_RenderBuffer( Screen_t* screen );

#if defined( __cplusplus )
}
#endif

#endif // SCREEN_H
