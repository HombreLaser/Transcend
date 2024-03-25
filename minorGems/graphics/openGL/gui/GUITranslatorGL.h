/*
 * Modification History
 *
 * 2001-September-15		Jason Rohrer
 * Created.
 *
 * 2001-September-16		Jason Rohrer
 * Changed so that translation preserves the aspect
 * ration of GUI components.
 * Fixed a bug with inverted y components of mouse coordinates.
 *
 * 2001-October-29		Jason Rohrer
 * Added support for focus.
 *
 * 2001-November-3		Jason Rohrer
 * Changed translation methods to be public.
 */
 
 
#ifndef GUI_TRANSLATOR_GL_INCLUDED
#define GUI_TRANSLATOR_GL_INCLUDED 

#include "GUIComponentGL.h"

#include <GL/gl.h>

#include "minorGems/graphics/openGL/MouseHandlerGL.h"
#include "minorGems/graphics/openGL/KeyboardHandlerGL.h"
#include "minorGems/graphics/openGL/RedrawListenerGL.h"
#include "minorGems/graphics/openGL/ScreenGL.h"

/**
 * A class that translates coordinates for a gui component.
 *
 * Notes on intended use:
 * This class is best used as a wrapper for the entire
 * GL-based gui.  In this case, the component passed to the
 * constructor would be a GUIContainerGL containing the
 * entire GUI.  This class can be thought of as a wrapper
 * for interfacing size-independent GUI components to the
 * screen.
 *
 * @author Jason Rohrer
 */
class GUITranslatorGL : public MouseHandlerGL,
					  public KeyboardHandlerGL,
					  public RedrawListenerGL {


	public:

		/**
		 * Constructs a translator.
		 *
		 * @param inComponent the component for which events
		 *   will be translated and delegated.  All events will
		 *   be delegated to inComponent, regardless of whether the
		 *   events pass the inComponent->isInside() test.
		 *   Will be destroyed when this class is destroyed.
		 * @param inScreen the screen whose size is used during
		 *   event translation.  Must be destroyed by caller after
		 *   this class is destroyed.
		 */
		GUITranslatorGL( GUIComponentGL *inComponent, ScreenGL *inScreen );
	

		
		~GUITranslatorGL();


		
		/**
		 * Translates screen coordinates to gui coordinates.
		 *
		 * @param inX the x value of the screen coordinate.
		 * @param inY the y value of the screen coordinate.
		 * @param outX a pointer to an value in which the gui x
		 *  component will be returned.
		 * @param outY a pointer to an value in which the gui y
		 *  component will be returned.
		 */
		void translate( int inX, int inY, double *outX, double *outY );

		

		/**
		 * Translates screen coordinates to gui coordinates.
		 *
		 * @param inX the x value of the screen coordinate.
		 * 
		 * @return the gui x component will be returned.
		 */
		double translateX( int inX );

		

		/**
		 * Translates screen coordinates to gui coordinates.
		 *
		 * @param inX the x value of the screen coordinate.
		 * 
		 * @return the gui x component will be returned.
		 */
		double translateY( int inY );


		
		// implements the MouseHandlerGL interface
		virtual void mouseMoved( int inX, int inY );
		virtual void mouseDragged( int inX, int inY );
		virtual void mousePressed( int inX, int inY );
		virtual void mouseReleased( int inX, int inY );
		
		// implements the KeyboardHandlerGL interface
		virtual char isFocused();
		virtual void keyPressed( unsigned char inKey, int inX, int inY );
		virtual void specialKeyPressed( int inKey, int inX, int inY );
		virtual void keyReleased( unsigned char inKey, int inX, int inY );
		virtual void specialKeyReleased( int inKey, int inX, int inY );
		
		// implements the RedrawListener interface
		virtual void fireRedraw();


		
	protected:
		
		GUIComponentGL *mComponent;
		ScreenGL *mScreen;



		/**
		 * Gets the factor by which screen coordinates need
		 * to be multiplied to get gui coordinates.
		 *
		 * @return the translation factor to multiply by.
		 */
		double getTranslationFactor();


		
	};



inline GUITranslatorGL::GUITranslatorGL( GUIComponentGL *inComponent,
										 ScreenGL *inScreen )
	: mComponent( inComponent ), mScreen( inScreen ) {

	}



inline GUITranslatorGL::~GUITranslatorGL() {

	delete mComponent;
	}



inline void GUITranslatorGL::translate( int inX, int inY,
										double *outX, double *outY ) {
	
	*outX = translateX( inX );
	*outY = translateY( inY );
	}
		


inline double GUITranslatorGL::translateX( int inX ) {
	return inX * getTranslationFactor();
	}



inline double GUITranslatorGL::translateY( int inY ) {
	int height = mScreen->getHeight();
	
	return ( height - inY ) * getTranslationFactor();
	}







inline double GUITranslatorGL::getTranslationFactor() {
	double width = (double)( mScreen->getWidth() );
	double height = (double)( mScreen->getHeight() );

	if( width <= height ) {
		return 1.0 / width;
		}
	else {
		return 1.0 / height;
		}
	}



inline void GUITranslatorGL::mouseMoved( int inX, int inY ) {
	mComponent->mouseMoved( translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::mouseDragged( int inX, int inY ) {
	mComponent->mouseDragged( translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::mousePressed( int inX, int inY ) {
	mComponent->mousePressed( translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::mouseReleased( int inX, int inY ) {
	mComponent->mouseReleased( translateX( inX ), translateY( inY ) );
	}



inline char GUITranslatorGL::isFocused() {
	return mComponent->isFocused();
	}


		
inline void GUITranslatorGL::keyPressed(
	unsigned char inKey, int inX, int inY ) {
	mComponent->keyPressed( inKey, translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::specialKeyPressed(
	int inKey, int inX, int inY ) {
	mComponent->specialKeyPressed( inKey,
								   translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::keyReleased(
	unsigned char inKey, int inX, int inY ) {
	mComponent->keyReleased( inKey, translateX( inX ), translateY( inY ) );
	}



inline void GUITranslatorGL::specialKeyReleased(
	int inKey, int inX, int inY ) {
	mComponent->specialKeyReleased( inKey,
									translateX( inX ), translateY( inY ) );
	}


		
inline void GUITranslatorGL::fireRedraw() {
	// setup orthographic projection matrices before
	// telling our component to draw itself
	// (thus, the component can draw in [0.0, 1.0] space
	// with no regard to screen size)

	// Ack:
	// some of this code was adapted from NeHe's tutorial #17,
	// which can be found at http://nehe.gamedev.net

	glMatrixMode( GL_PROJECTION );   // Select The Projection Matrix
	glPushMatrix();   // Store The Projection Matrix
	
	glLoadIdentity();   // Reset The Projection Matrix
	
	// setup an orthographic projection for our 2d gui

	// the shorter screen dimension gets mapped to the range [0,1],
	// and the longer dimension extends beyond 1.0
	double translationFactor = getTranslationFactor();
	double guiScreenWidth = mScreen->getWidth() * translationFactor;
	double guiScreenHeight = mScreen->getHeight() * translationFactor;

	// we don't care about z for 2d gui's, so just select
	// the region around 0
	double zStart = -1;
	double zEnd = 1;

	// set the projection matrix to an orthographic projection
	glOrtho( 0, guiScreenWidth, 0, guiScreenHeight, zStart, zEnd );

	glMatrixMode( GL_MODELVIEW );  // Select The Modelview Matrix
	glPushMatrix();  // Store The Modelview Matrix
	// set the model view matrix to the identity
	glLoadIdentity();


	glDisable( GL_DEPTH_TEST );
	glDisable( GL_CULL_FACE );


	
	// draw our gui
	mComponent->fireRedraw();


	
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );
	
	// restore the matrices
	glMatrixMode( GL_MODELVIEW );  // Select The Modelview Matrix
	glPopMatrix();  // Restore The Old Modelview Matrix
	
	glMatrixMode( GL_PROJECTION );  // Select The Projection Matrix
	glPopMatrix();  // Restore The Old Projection Matrix
	
	}



#endif


