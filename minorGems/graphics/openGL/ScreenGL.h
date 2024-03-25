/*
 * Modification History
 *
 * 2000-December-19		Jason Rohrer
 * Created. 
 *
 * 2001-January-15		Jason Rohrer
 * Added compile instructions for Linux to the comments.
 *
 * 2001-February-4		Jason Rohrer
 * Added a function for getting the view angle.
 * Added support for keyboard up functions. 
 * Added support for redraw listeners.
 * Added a missing destructor.
 *
 * 2001-August-29		Jason Rohrer
 * Added support for adding and removing mouse, keyboard, and scene handlers.
 *
 * 2001-August-30		Jason Rohrer
 * Fixed some comments.
 *
 * 2001-September-15   	Jason Rohrer
 * Added functions for accessing the screen size.
 *
 * 2001-October-13   	Jason Rohrer
 * Added a function for applying the view matrix transformation.
 *
 * 2001-October-29   	Jason Rohrer
 * Added a private function that checks for focused keyboard handlers.
 *
 * 2004-June-11   	Jason Rohrer
 * Added functions for getting/setting view position.
 *
 * 2004-June-14   	Jason Rohrer
 * Added comment about need for glutInit call.
 */
 
 
#ifndef SCREEN_GL_INCLUDED
#define SCREEN_GL_INCLUDED 

#include <GL/gl.h>
#include <GL/glut.h>

#include "MouseHandlerGL.h"
#include "KeyboardHandlerGL.h"
#include "SceneHandlerGL.h"

#include "RedrawListenerGL.h"

#include "minorGems/math/geometry/Vector3D.h"
#include "minorGems/math/geometry/Angle3D.h"

#include "minorGems/util/SimpleVector.h"


// prototypes
void glutResize( int inW, int inH );
void glutKeyboard( unsigned char  inKey, int inX, int inY );
void glutKeyboardUp( unsigned char  inKey, int inX, int inY );
void glutSpecialKeyboard( int inKey, int inX, int inY );
void glutSpecialKeyboardUp( int inKey, int inX, int inY );
void glutMotion( int inX, int inY );
void glutPassiveMotion( int inX, int inY );
void glutMouse( int inButton, int inState, int inX, int inY );
void glutDisplay();
void glutIdle();


/**
 * Object that handles general initialization of an OpenGL screen.
 *
 * Compile note:  For Linux, add these library flags:
 * -lGL -lglut -lGLU -L/usr/X11R6/lib
 *
 * @author Jason Rohrer 
 */
class ScreenGL { 
	
	public:
		
		/**
		 * Constructs a ScreenGL.
         *
         * Before calling this constructor, glutInit must be called with
         * the application's command-line arguments.  For example, if
         * the application's main function looks like:
         *
         * int main( int inNumArgs, char **inArgs ) { ... }
         *
         * Then you must call glutInit( &inNumArgs, inArgs ) before
         * constructing a screen.
		 *
		 * @param inWide width of screen.
		 * @param inHigh height of screen.
		 * @param inFullScreen set to true for full screen mode.
		 * @param inWindowName name to be displayed on title bar of window.
		 * @param inKeyHandler object that will receive keyboard events.
		 *   NULL specifies no handler (defaults to NULL).
		 *   Must be destroyed by caller.
		 * @param inMouseHandler object that will receive mouse events.
		 *   NULL specifies no handler (defaults to NULL).
		 *   Must be destroyed by caller.
		 * @param inSceneHandler object that will be called to draw
		 *   the scene during in response to redraw events.
		 *   NULL specifies no handler (defaults to NULL).
		 *   Must be destroyed by caller.
		 */
		ScreenGL( int inWide, int inHigh, char inFullScreen, 
				  char *inWindowName,
				  KeyboardHandlerGL *inKeyHandler = NULL,
				  MouseHandlerGL *inMouseHandler = NULL,
				  SceneHandlerGL *inSceneHandler = NULL );
		
		
		/**
		 * Destructor closes and releases the screen.
		 */	
		~ScreenGL();	
		
		
		/**
		 * Starts the GLUT main loop.
		 * 
		 * Note that this function call never returns.
		 */
		void start();
		
		
		/**
		 * Moves the view position.
		 *
		 * @param inPositionChange directional vector describing motion.
		 *   Must be destroyed by caller.
		 */
		void moveView( Vector3D *inPositionChange );
		
		
		/**
		 * Rotates the view.
		 *
		 * @param inOrientationChange angle to rotate view by.
		 *   Must be destroyed by caller.
		 */
		void rotateView( Angle3D *inOrientationChange );
		
		
		/**
		 * Gets the angle of the current view direction.
		 *
		 * @return the angle of the current view direction.
		 *   Not a copy, so shouldn't be modified or destroyed by caller.
		 */
		Angle3D *getViewOrientation();


		/**
		 * Gets the current view position.
		 *
		 * @return the position of the current view.
		 *  Must be destroyed by caller.
		 */
		Vector3D *getViewPosition();

        
		/**
		 * Sets the current view position.
		 *
		 * @param inPosition the new position.
		 *   Must be destroyed by caller.
		 */
		void setViewPosition( Vector3D *inPosition );
        
        
		/**
		 * Gets the width of the screen.
		 *
		 * @return the width of the screen, in pixels.
		 */
		int getWidth();



		/**
		 * Gets the height of the screen.
		 *
		 * @return the height of the screen, in pixels.
		 */
		int getHeight();


		
		/**
		 * Adds a mouse handler.
		 *
		 * @param inHandler the handler to add  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void addMouseHandler( MouseHandlerGL *inHandler );
		

		
		/**
		 * Removes a mouse handler.
		 *
		 * @param inHandler the handler to remove.  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void removeMouseHandler( MouseHandlerGL *inHandler );


		/**
		 * Adds a keyboard handler.
		 *
		 * @param inHandler the handler to add  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void addKeyboardHandler( KeyboardHandlerGL *inHandler );
		

		
		/**
		 * Removes a keyboard handler.
		 *
		 * @param inHandler the handler to remove.  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void removeKeyboardHandler( KeyboardHandlerGL *inHandler );
		

		/**
		 * Adds a scene handler.
		 *
		 * @param inHandler the handler to add  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void addSceneHandler( SceneHandlerGL *inHandler );
		

		
		/**
		 * Removes a scene handler.
		 *
		 * @param inHandler the handler to remove.  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void removeSceneHandler( SceneHandlerGL *inHandler );
		

		
		/**
		 * Adds a redraw listener.
		 *
		 * @param inListener the listener to add.  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void addRedrawListener( RedrawListenerGL *inListener );
		
		
		/**
		 * Removes a redraw listener.
		 *
		 * @param inListener the listener to remove.  Must 
		 *   be destroyed by caller.
		 *
		 * Must not be called after calling start().
		 */
		void removeRedrawListener( RedrawListenerGL *inListener );
		


		/**
		 * Applies the current view matrix transformation
		 * to the matrix at the top of the GL_PROJECTION stack.
		 */
		void applyViewTransform();

		
		
		/**
		 * Access the various handlers.
		 */
		//KeyboardHandlerGL *getKeyHandler();
		//MouseHandlerGL *getMouseHandler();
		//SceneHandlerGL *getSceneHandler();
		
		
		
	private :
		
		// GLUT callbacks
		/*void glutResize( int inW, int inH );
		void glutKeyboard( unsigned char  inKey, int inX, int inY );
		void glutMotion( int inX, int inY );
		void glutPassiveMotion( int inX, int inY );
		void glutMouse( int inButton, int inState, int inX, int inY );
		*/
		
		friend void glutResize( int inW, int inH );
		friend void glutKeyboard( unsigned char inKey, int inX, int inY );
		friend void glutKeyboardUp( unsigned char inKey, int inX, int inY );
		friend void glutSpecialKeyboard( int inKey, 
			int inX, int inY );
		friend void glutSpecialKeyboardUp( int inKey, 
			int inX, int inY );	
		friend void glutMotion( int inX, int inY );
		friend void glutPassiveMotion( int inX, int inY );
		friend void glutMouse( int inButton, int inState, int inX, int inY );
		friend void glutDisplay();
		friend void glutIdle();
		
		int mWide;
		int mHigh;
		
		char mFullScreen;
		
		Vector3D *mViewPosition;
		
		// orientation of 0,0,0 means looking in the direction (0,0,1)
		// with an up direction of (0,1,0)
		Angle3D *mViewOrientation;
		
		// vectors of handlers and listeners
		SimpleVector<MouseHandlerGL*> *mMouseHandlerVector;
		SimpleVector<KeyboardHandlerGL*> *mKeyboardHandlerVector;
		SimpleVector<SceneHandlerGL*> *mSceneHandlerVector;
		SimpleVector<RedrawListenerGL*> *mRedrawListenerVector;

		

		/**
		 * Gets whether at least one of our keyboard handlers is focused.
		 *
		 * @return true iff at least one keyboard handler is focused.
		 */
		char isKeyboardHandlerFocused();


		
	};



inline ScreenGL::~ScreenGL() {
	delete mViewPosition;
	delete mViewOrientation;
	delete mRedrawListenerVector;
	delete mMouseHandlerVector;
	delete mKeyboardHandlerVector;
	delete mSceneHandlerVector;
	}



inline void ScreenGL::moveView( Vector3D *inPositionChange ) {
	mViewPosition->add( inPositionChange );
	}



inline void ScreenGL::rotateView( Angle3D *inOrientationChange ) {
	mViewOrientation->add( inOrientationChange );
	}



inline Angle3D *ScreenGL::getViewOrientation() {
	return mViewOrientation;
	}



inline Vector3D *ScreenGL::getViewPosition() {
	return new Vector3D( mViewPosition );
	}



inline void ScreenGL::setViewPosition( Vector3D *inPosition ) {
    delete mViewPosition;
    mViewPosition = new Vector3D( inPosition );
    }



inline int ScreenGL::getWidth() {
	return mWide;
	}



inline int ScreenGL::getHeight() {
	return mHigh;
	}



inline void ScreenGL::addRedrawListener( RedrawListenerGL *inListener ) {
	mRedrawListenerVector->push_back( inListener );
	}
		


inline void ScreenGL::removeRedrawListener( RedrawListenerGL *inListener ) {
	mRedrawListenerVector->deleteElement( inListener );
	}



inline void ScreenGL::addMouseHandler( MouseHandlerGL *inListener ) {
	mMouseHandlerVector->push_back( inListener );
	}
		


inline void ScreenGL::removeMouseHandler( MouseHandlerGL *inListener ) {
	mMouseHandlerVector->deleteElement( inListener );
	}



inline void ScreenGL::addKeyboardHandler( KeyboardHandlerGL *inListener ) {
	mKeyboardHandlerVector->push_back( inListener );
	}
		


inline void ScreenGL::removeKeyboardHandler( KeyboardHandlerGL *inListener ) {
	mKeyboardHandlerVector->deleteElement( inListener );
	}



inline void ScreenGL::addSceneHandler( SceneHandlerGL *inListener ) {
	mSceneHandlerVector->push_back( inListener );
	}
		


inline void ScreenGL::removeSceneHandler( SceneHandlerGL *inListener ) {
	mSceneHandlerVector->deleteElement( inListener );
	}



inline char ScreenGL::isKeyboardHandlerFocused() {
	for( int h=0; h<mKeyboardHandlerVector->size(); h++ ) {
		KeyboardHandlerGL *handler 
			= *( mKeyboardHandlerVector->getElement( h ) );
		if( handler->isFocused() ) {
			return true;
			}
		}
	
	// else none were focused
	return false;
	}



#endif
