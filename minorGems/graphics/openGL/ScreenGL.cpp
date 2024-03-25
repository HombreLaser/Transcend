/*
 * Modification History
 *
 * 2000-December-19		Jason Rohrer
 * Created. 
 *
 * 2001-January-31		Jason Rohrer
 * Fixed a bug in the fullscreen code.
 *
 * 2001-February-4		Jason Rohrer
 * Added support for keyboard up functions.
 * Added support for redraw listeners. 
 * Added missing initialization.
 *
 * 2001-August-29		Jason Rohrer
 * Added support for vectors of mouse, keyboard, and scene handlers.
 *
 * 2001-September-15    Jason Rohrer
 * Fixed a bug in passing redraw events to the redraw listeners.
 *
 * 2001-October-13   	Jason Rohrer
 * Added a function for applying the view matrix transformation.
 * Removed unneeded code from the glutResize function.
 *
 * 2001-October-29   	Jason Rohrer
 * Added support for focusable keyboard handlers.
 *
 * 2001-October-29   	Jason Rohrer
 * Added support for focusable keyboard handlers.
 *
 * 2004-August-30   	Jason Rohrer
 * Fixed distortion issues when screen aspect ratio is not 1:1.
 *
 * 2005-February-7   	Jason Rohrer
 * Fixed bug of incorrect GL matrix stack usage.  Now fog works correctly.
 *
 * 2005-February-21   	Jason Rohrer
 * Removed incorrect call to glPopMatrix.
 *
 * 2005-March-4   	Jason Rohrer
 * Changed to call redraw listeners before applying view transform.
 */


#include "ScreenGL.h" 
#include <math.h>

/* ScreenGL to be accessed by callback functions.
 *
 * Note that this is a bit of a hack, but the callbacks
 * require a C-function (not a C++ member) and have fixed signatures,
 * so there's no way to pass the current screen into the functions.
 *
 * This hack prevents multiple instances of the ScreenGL class from
 * being used simultaneously.
 */
ScreenGL *currentScreenGL;


// prototypes
/*
void glutResize( int inW, int inH );
void glutKeyboard( unsigned char  inKey, int inX, int inY );
void glutMotion( int inX, int inY );
void glutPassiveMotion( int inX, int inY );
void glutMouse( int inButton, int inState, int inX, int inY );
void glutDisplay();
void glutIdle();
*/

ScreenGL::ScreenGL( int inWide, int inHigh, char inFullScreen, 
					char *inWindowName,
					KeyboardHandlerGL *inKeyHandler,
					MouseHandlerGL *inMouseHandler,
					SceneHandlerGL *inSceneHandler  ) 
	: mWide( inWide ), mHigh( inHigh ), mFullScreen( inFullScreen ),
	  mViewPosition( new Vector3D( 0, 0, 0 ) ),
	  mViewOrientation( new Angle3D( 0, 0, 0 ) ),
	  mMouseHandlerVector( new SimpleVector<MouseHandlerGL*>() ),
	  mKeyboardHandlerVector( new SimpleVector<KeyboardHandlerGL*>() ),
	  mSceneHandlerVector( new SimpleVector<SceneHandlerGL*>() ),
	  mRedrawListenerVector( new SimpleVector<RedrawListenerGL*>() ) {


	// add handlers if NULL (the default) was not passed in for them
	if( inMouseHandler != NULL ) {
		addMouseHandler( inMouseHandler );
		}
	if( inKeyHandler != NULL ) {
		addKeyboardHandler( inKeyHandler );
		}
	if( inSceneHandler != NULL ) {
		addSceneHandler( inSceneHandler );
		}

	
	if( mFullScreen ) {
		glutInitDisplayMode( 
			GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
            //| GLUT_FULLSCREEN );
		}
	else {
		glutInitDisplayMode( 
			GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
		}
	
	glutInitWindowSize( mWide, mHigh );
	glutCreateWindow( inWindowName );

	if( mFullScreen ) {
		glutFullScreen();
		}

	glutKeyboardFunc( glutKeyboard );
	glutKeyboardUpFunc( glutKeyboardUp );
	glutSpecialFunc( glutSpecialKeyboard );
	glutSpecialUpFunc( glutSpecialKeyboardUp );
	glutReshapeFunc( glutResize );
	glutMotionFunc( glutMotion );
	glutMouseFunc( glutMouse );
	glutPassiveMotionFunc( glutPassiveMotion );
	glutDisplayFunc( glutDisplay );
	glutIdleFunc( glutIdle );
	
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glCullFace( GL_BACK );
	glFrontFace( GL_CCW );
	
	}



void ScreenGL::start() {
	currentScreenGL = this;
	glutMainLoop();
	}



void ScreenGL::applyViewTransform() {
    // compute view angle

    // default angle is 90, but we want to force a 1:1 aspect ratio to avoid
    // distortion.
    // If our screen's width is different than its height, we need to decrease
    // the view angle so that the angle coresponds to the smaller dimension.
    // This keeps the zoom factor constant in the smaller dimension.

    // Of course, because of the way perspective works, only one Z-slice
    // will have a constant zoom factor
    // The zSlice variable sets the distance of this slice from the picture
    // plane
    double zSlice = .31;

    double maxDimension = mWide;
    if( mHigh > mWide ) {
        maxDimension = mHigh;
        }
    double aspectDifference = fabs( mWide / 2 - mHigh / 2 ) / maxDimension;
    // default angle is 90 degrees... half the angle is PI/4
    double angle = atan( tan( M_PI / 4 ) +
                         aspectDifference / zSlice );

    // double it to get the full angle
    angle *= 2;
    
    
    // convert to degrees
    angle = 360 * angle / ( 2 * M_PI );


    // set up the projection matrix
    glMatrixMode( GL_PROJECTION );

	glLoadIdentity();
    
    //gluPerspective( 90, mWide / mHigh, 1, 9999 );
    gluPerspective( angle,
                    1,
                    1, 9999 );

    
    // set up the model view matrix
    glMatrixMode( GL_MODELVIEW );
    
    glLoadIdentity();

	// create default view and up vectors, 
	// then rotate them by orientation angle
	Vector3D *viewDirection = new Vector3D( 0, 0, 1 );
	Vector3D *upDirection = new Vector3D( 0, 1, 0 );
	
	viewDirection->rotate( mViewOrientation );
	upDirection->rotate( mViewOrientation );
	
	// get a point out in front of us in the view direction
	viewDirection->add( mViewPosition );
	
	// look at takes a viewer position, 
	// a point to look at, and an up direction
	gluLookAt( mViewPosition->mX, 
				mViewPosition->mY, 
				mViewPosition->mZ,
				viewDirection->mX, 
				viewDirection->mY, 
				viewDirection->mZ,
				upDirection->mX, 
				upDirection->mY, 
				upDirection->mZ );
	
	delete viewDirection;
	delete upDirection;
    }



void glutResize( int inW, int inH ) {	
	ScreenGL *s = currentScreenGL;
	s->mWide = inW;
	s->mHigh = inH;

    // viewport is square and matches largest dimension
    // (to ensure a 1:1 aspect ratio)
    
    if( s->mWide >= s->mHigh ) {
        int excess = s->mWide - s->mHigh;
        
        glViewport( 0, -excess / 2, s->mWide, s->mWide );
        }
    else {
        int excess = s->mHigh - s->mWide;
        
        glViewport( -excess / 2, 0, s->mHigh, s->mHigh );
        }
	glutPostRedisplay();
	}



void glutKeyboard( unsigned char inKey, int inX, int inY ) {
	char someFocused = currentScreenGL->isKeyboardHandlerFocused();
		
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mKeyboardHandlerVector->size(); h++ ) {
		KeyboardHandlerGL *handler 
			= *( currentScreenGL->mKeyboardHandlerVector->getElement( h ) );

		// if some are focused, only fire to this handler if it is one
		// of the focused handlers
		if( !someFocused || handler->isFocused() ) {
			handler->keyPressed( inKey, inX, inY );
			}
		}
	}



void glutKeyboardUp( unsigned char inKey, int inX, int inY ) {
	char someFocused = currentScreenGL->isKeyboardHandlerFocused();
	
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mKeyboardHandlerVector->size(); h++ ) {
		KeyboardHandlerGL *handler 
			= *( currentScreenGL->mKeyboardHandlerVector->getElement( h ) );

		// if some are focused, only fire to this handler if it is one
		// of the focused handlers
		if( !someFocused || handler->isFocused() ) {
			handler->keyReleased( inKey, inX, inY );
			}
		}
	}	

	
	
void glutSpecialKeyboard( int inKey, int inX, int inY ) {
	char someFocused = currentScreenGL->isKeyboardHandlerFocused();
	
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mKeyboardHandlerVector->size(); h++ ) {
		KeyboardHandlerGL *handler 
			= *( currentScreenGL->mKeyboardHandlerVector->getElement( h ) );
		
		// if some are focused, only fire to this handler if it is one
		// of the focused handlers
		if( !someFocused || handler->isFocused() ) {
			handler->specialKeyPressed( inKey, inX, inY );
			}
		}
	}
	


void glutSpecialKeyboardUp( int inKey, int inX, int inY ) {
	char someFocused = currentScreenGL->isKeyboardHandlerFocused();
	
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mKeyboardHandlerVector->size(); h++ ) {
		KeyboardHandlerGL *handler 
			= *( currentScreenGL->mKeyboardHandlerVector->getElement( h ) );

		// if some are focused, only fire to this handler if it is one
		// of the focused handlers
		if( !someFocused || handler->isFocused() ) {
			handler->specialKeyReleased( inKey, inX, inY );
			}
		}
	}	


	
void glutMotion( int inX, int inY ) {
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mMouseHandlerVector->size(); h++ ) {
		MouseHandlerGL *handler 
			= *( currentScreenGL->mMouseHandlerVector->getElement( h ) );
		handler->mouseDragged( inX, inY );
		}
	}
	


void glutPassiveMotion( int inX, int inY ) {
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mMouseHandlerVector->size(); h++ ) {
		MouseHandlerGL *handler 
			= *( currentScreenGL->mMouseHandlerVector->getElement( h ) );
		handler->mouseMoved( inX, inY );
		}
	}			
	
	
	
void glutMouse( int inButton, int inState, int inX, int inY ) {
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mMouseHandlerVector->size(); h++ ) {
		MouseHandlerGL *handler 
			= *( currentScreenGL->mMouseHandlerVector->getElement( h ) );
		handler->mouseMoved( inX, inY );
		if( inState == GLUT_DOWN ) {
			handler->mousePressed( inX, inY );
			}
		else if( inState == GLUT_UP ) {
			handler->mouseReleased( inX, inY );
			}
		else {
			printf( "Error:  Unknown mouse state received from OpenGL\n" );
			}	
		}
	}
	
	
	
void glutDisplay() {
	ScreenGL *s = currentScreenGL;
	
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    // fire to all redraw listeners
    // do this first so that they can update our view transform
    // this makes control much more responsive
	for( int r=0; r<s->mRedrawListenerVector->size(); r++ ) {
		RedrawListenerGL *listener 
			= *( s->mRedrawListenerVector->getElement( r ) );
		listener->fireRedraw();
		}
	
    // apply our view transform
	s->applyViewTransform();

    
	// fire to all handlers
	for( int h=0; h<currentScreenGL->mSceneHandlerVector->size(); h++ ) {
		SceneHandlerGL *handler 
			= *( currentScreenGL->mSceneHandlerVector->getElement( h ) );
		handler->drawScene();
		}

	
	
	glutSwapBuffers();
	}



void glutIdle() {
	glutPostRedisplay();
	}		
