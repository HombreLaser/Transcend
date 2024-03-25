/*
 * Modification History
 *
 * 2001-September-15		Jason Rohrer
 * Created.
 */
 
 
#ifndef BUTTON_GL_INCLUDED
#define BUTTON_GL_INCLUDED 

#include "GUIComponentGL.h"

#include "minorGems/graphics/Image.h"

#include "minorGems/graphics/openGL/SingleTextureGL.h"

#include "minorGems/ui/event/ActionListenerList.h"

#include <GL/gl.h>


/**
 * A textured button for GL-based GUIs.
 *
 * @author Jason Rohrer
 */
class ButtonGL : public GUIComponentGL, public ActionListenerList {


	public:



		/**
		 * Constructs a button.
		 *
		 * @param inAnchorX the x position of the upper left corner
		 *   of this component.
		 * @param inAnchorY the y position of the upper left corner
		 *   of this component.
		 * @param inWidth the width of this component.
		 * @param inHeight the height of this component.
		 * @param inUnpressedImage the image to display
		 *   when this button is unpressed.  Must have dimensions
		 *   that are powers of 2.
		 *   Will be destroyed when this class is destroyed.
		 * @param inPressedImage the image to display
		 *   when this button is pressed.  Must have dimensions
		 *   that are powers of 2.
		 *   Will be destroyed when this class is destroyed.
		 */
		ButtonGL(
			double inAnchorX, double inAnchorY, double inWidth,
			double inHeight, Image *inUnpressedImage,
			Image *inPressedImage );


		
		~ButtonGL();
		
		// override funxtions in GUIComponentGL
		virtual void mouseDragged( double inX, double inY );
		virtual void mousePressed( double inX, double inY );
		virtual void mouseReleased( double inX, double inY );
		virtual void fireRedraw();


		
	protected:
		Image *mUnpressedImage;
		Image *mPressedImage;

		SingleTextureGL *mUnpressedTexture;
		SingleTextureGL *mPressedTexture;		

		SingleTextureGL *mCurrentTexture;
	};



inline ButtonGL::ButtonGL(
	double inAnchorX, double inAnchorY, double inWidth,
	double inHeight, Image *inUnpressedImage,
	Image *inPressedImage  )
	: GUIComponentGL( inAnchorX, inAnchorY, inWidth, inHeight ),
	  mUnpressedImage( inUnpressedImage ),
	  mPressedImage( inPressedImage ) {

	mUnpressedTexture = new SingleTextureGL( mUnpressedImage );
	mPressedTexture = new SingleTextureGL( mPressedImage );

	mCurrentTexture = mUnpressedTexture;
	}



inline ButtonGL::~ButtonGL() {
	delete mUnpressedImage;
	delete mPressedImage;

	delete mUnpressedTexture;
	delete mPressedTexture;
	}



inline void ButtonGL::mouseDragged( double inX, double inY ) {
	if( mCurrentTexture == mPressedTexture
		&& !isInside( inX, inY ) ) {
		// the mouse has been dragged outside of us, so unpress
		mCurrentTexture = mUnpressedTexture;
		}
	}



inline void ButtonGL::mousePressed( double inX, double inY ) {
	// we'll only get pressed events if the mouse is pressed on us
	mCurrentTexture = mPressedTexture;
	}



inline void ButtonGL::mouseReleased( double inX, double inY ) {
	// always unpress on a release
	mCurrentTexture = mUnpressedTexture;
	
	if( isInside( inX, inY ) ) {
		// fire an event
		fireActionPerformed( this );
		}
	}


		
inline void ButtonGL::fireRedraw() {
	
	// set our texture
	mCurrentTexture->enable();

	glColor3f( 1.0f, 1.0f, 1.0f ); 

	glDisable( GL_BLEND );

	
	glBegin( GL_QUADS ); {
		
		glTexCoord2f( 0, 1.0f );
		glVertex2d( mAnchorX, mAnchorY );

		glTexCoord2f( 1.0f, 1.0f );
		glVertex2d( mAnchorX + mWidth, mAnchorY ); 

		glTexCoord2f( 1.0f, 0 );
		glVertex2d( mAnchorX + mWidth, mAnchorY + mHeight );
		
		glTexCoord2f( 0, 0 );
		glVertex2d( mAnchorX, mAnchorY + mHeight );
		}
	glEnd();

	
	mCurrentTexture->disable();
	}



#endif



