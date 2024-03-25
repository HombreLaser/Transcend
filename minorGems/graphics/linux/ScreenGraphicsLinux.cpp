/*
 * Modification History
 *
 * 2000-November-18		Jason Rohrer
 * Created.
 *
 * 2000-November-19		Jason Rohrer
 * Change so that it doesn't use SDL's interrupt parachute, i.e.,
 *   so it will quit on ^c.
 *
 * 2001-May-1   Jason Rohrer
 * Changed to use more standard SDL include location.
 */
 
#include "minorGems/graphics/ScreenGraphics.h"

#include <SDL/SDL.h>

/**
 * Note:  Linux implementation uses windowed mode.
 */

ScreenGraphics::ScreenGraphics( int inWidth, int inHeight )
	: mWidth( inWidth ), mHeight( inHeight ) {
	
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE ) < 0 ) {
		printf( "Couldn't initialize SDL: %s\n", SDL_GetError() );
		return;
		}
	
	SDL_Surface *screen = SDL_SetVideoMode( mWidth, mHeight, 
		32, SDL_SWSURFACE );
	
	if ( screen == NULL ) {
		printf( "Couldn't set %dx%dx32 video mode: %s\n", mWidth, mHeight,
			SDL_GetError() );
		return;
		}
		
	
	mNativeObjectPointer = (void*)screen;
	}



ScreenGraphics::~ScreenGraphics() {
	SDL_Quit();
	}



char ScreenGraphics::isResolutionAvailable( int inWidth, int inHeight ) {
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE ) < 0 ) {
		printf( "Couldn't initialize SDL: %s\n", SDL_GetError() );
		return false;
		}
		
	// ask SDL if this screen size is supported
	char videoModeOk = 
		(char)SDL_VideoModeOK( inWidth, inHeight, 32, SDL_SWSURFACE );
	
	SDL_Quit();
	
	
	return videoModeOk;
	}	



void ScreenGraphics::swapBuffers( GraphicBuffer *inOutBuffer ) {
	if( inOutBuffer->getHeight() != mHeight ||
		inOutBuffer->getWidth() != mWidth ) {
		printf( "Buffer of incorrect size passed to screen.\n" );
		return;
		}
	
	SDL_Surface *screen = (SDL_Surface*)mNativeObjectPointer;
	
	// check if we need to lock the screen
	if( SDL_MUSTLOCK( screen ) ) {
		if( SDL_LockSurface( screen ) < 0 ) {
			printf( "Couldn't lock screen: %s\n", SDL_GetError() );
			return;
			}
		}
		
	Uint32 *buffer = (Uint32 *)( screen->pixels );
	memcpy( (void*)buffer, (void*)( inOutBuffer->getBuffer() ), 
		mWidth * mHeight * 4 );

	// unlock the screen if necessary
	if ( SDL_MUSTLOCK(screen) ) {
		SDL_UnlockSurface(screen);
		}
	
	SDL_Flip( screen );	
	}
