/*
 * Modification History
 *
 * 2000-December-19		Jason Rohrer
 * Created.
 *
 * 2001-February-4		Jason Rohrer
 * Added key release functions.
 *
 * 2001-October-29		Jason Rohrer
 * Added fuction for querying a handler's focus.  
 */
 
 
#ifndef KEYBOARD_HANDLER_GL_INCLUDED
#define KEYBOARD_HANDLER_GL_INCLUDED 


/**
 * Interface for an object that can field OpenGL keystrokes.
 *
 * @author Jason Rohrer 
 */
class KeyboardHandlerGL { 
	
	public:


		
		/**
		 * Gets whether this handler is focused (in other words,
		 * whether this handler wants to reserve keyboard
		 * events for itself).
		 *
		 * If no registered handler is focused, then all
		 * registered handlers receive keyboard events.  However,
		 * if some handlers are focused, then only focused handlers
		 * receive keyboard events.
		 *
		 * Note that in general, handlers should be unfocused.
		 * A default implementation is included in this interface,
		 * so handlers that do not care about focus can ignore
		 * this function.
		 *
		 * @return true iff this handler is focused. 
		 */
		virtual char isFocused();
		
		
		
		/**
		 * Callback function for when an ASCII-representable key is pressed.
		 *
		 * @param inKey ASCII representation of the pressed key.
		 * @param inX x position of mouse when key was pressed.
		 * @param inY y position of mouse when key was pressed.
		 */
		virtual void keyPressed( unsigned char inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an ASCII-representable key is released.
		 *
		 * @param inKey ASCII representation of the released key.
		 * @param inX x position of mouse when key was released.
		 * @param inY y position of mouse when key was released.
		 */
		virtual void keyReleased( unsigned char inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an special key is pressed.
		 *
		 * @param inKey integer constant representation of the pressed key.
		 * @param inX x position of mouse when key was pressed.
		 * @param inY y position of mouse when key was pressed.
		 */
		virtual void specialKeyPressed( int inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an special key is released.
		 *
		 * @param inKey integer constant representation of the released key.
		 * @param inX x position of mouse when key was released.
		 * @param inY y position of mouse when key was released.
		 */
		virtual void specialKeyReleased( int inKey, int inX, int inY ) = 0;
		
	};



inline char KeyboardHandlerGL::isFocused() {
	return false;
	}



#endif
