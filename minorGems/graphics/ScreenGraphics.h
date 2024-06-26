/*
 * Modification History
 *
 * 2000-November-18		Jason Rohrer
 * Created.
 */
 
#ifndef SCREEN_GRAPHICS_INCLUDED
#define SCREEN_GRAPHICS_INCLUDED


#include "GraphicBuffer.h"

/**
 * Interface for accessing full-screen, 32-bit graphics.
 */
class ScreenGraphics {
	
	public:
		
		/**
		 * Constructs a <code>ScreenGraphics</code>.
		 * Adjusts screen resolution and fills screen with black.
		 *
		 * @param inWidth width of desired full screen.
		 * @param inHeight height of desired full screen.
		 */
		ScreenGraphics( int inWidth, int inHeight );
		
		
		
		/**
		 * Desctructor restores screen to original state.
		 */
		~ScreenGraphics();
		
		
		/**
		 * Swaps a buffer to the screen.
		 * The next buffer to be filled is returned in <code>inOutBuffer</code>.
		 * No guarentee is made about what will be in the next buffer returned.
		 * (On systems that support on-card double buffering, it may even
		 * be a buffer pointing directly into video memory.)
		 *
		 * @param inOutBuffer pointer to the buffer to swap to the screen,
		 *   and pointer where the next buffer will be stored.
		 */
		void swapBuffers( GraphicBuffer *inOutBuffer );
		
		
		
		/**
		 * Determines whether a particular screen setting is available.
		 *
		 * NOTE:  Do not call after constructing a ScreenGraphics instance.
		 *
		 * @param inWidth width of desired full screen.
		 * @param inHeight height of desired full screen.
		 *
		 * @return true iff screen setting is available.
		 */
		 static char isResolutionAvailable( int inWidth, int inHeight );
			
			
	private:
	
		int mWidth;
		int mHeight;
		
		void *mNativeObjectPointer;
	};
	
#endif
