/*
 * Modification History
 *
 * 2001-February-4		Jason Rohrer
 * Created.  
 */
 
 
#ifndef REDRAW_LISTENER_GL_INCLUDED
#define REDRAW_LISTENER_GL_INCLUDED 


/**
 * Interface for an object that will be called at the beginning of
 * every openGL redraw.
 *
 * @author Jason Rohrer 
 */
class RedrawListenerGL { 
	
	public:
		
		/**
		 * Tells the redraw listener that a redraw is occuring.
		 *
		 * Note that the redraw operation waits for this call to return
		 * before proceeding.
		 */
		virtual void fireRedraw() = 0;
		
		
	};

#endif
