/*
 * Modification History
 *
 * 2001-September-15	Jason Rohrer
 * Created.
 *
 * 2005-February-21	  Jason Rohrer
 * Added comments about channel ordering.
 * Created a cpp file for static init and longer function definitions.
 */
 
 
#ifndef SINGLE_TEXTURE_GL_INCLUDED
#define SINGLE_TEXTURE_GL_INCLUDED 

#include <GL/gl.h>
#include <stdio.h>
#include <string.h>

#include "minorGems/graphics/Image.h"
#include "minorGems/graphics/RGBAImage.h"


 
/**
 * A single-layer OpenGL 32-bit texture map.
 *
 * This is essentially a simplified version of TextureGL.
 *
 * @author Jason Rohrer 
 */
class SingleTextureGL { 
	
	public:


		
		/**
		 * Constructs a texture map, specifying texture data.
		 *
		 * Note that this constructor can only be called
		 * after a GL context has been setup.
		 *
		 * @param inImage the image to use as a source
		 *   for texture data.  The image should have
		 *   4 channels.  Any extra channels are ignored,
		 *   and black is set into additional texture
		 *   channels if inImage has too few channels.
		 *   Must be destroyed by caller, and can be
		 *   destroyed as soon as this constructor returns.
		 *   Channels are ordered as RGBA.
		 *   Must be destroyed by caller.
		 *
		 * Note that width and height must each be powers of 2 and
		 * not larger than 256 (for 3DFX compatability).  Additionally,
		 * for 3DFX compatability, the aspect ratio should not exceed 8:1.
		 */
		SingleTextureGL( Image *inImage );


		
		/**
		 * The OpenGL texture is deleted when the SingleTextureGL object is
		 * destroyed.
		 */
		~SingleTextureGL();
		

		
		/**
		 * Sets the data for this texture.
		 *
		 * @param inImage the image to use as a source
		 *   for texture data.  The image should have
		 *   4 channels.  Any extra channels are ignored,
		 *   and black is set into additional texture
		 *   channels if inImage has too few channels.
		 *   Must be destroyed by caller, and can be
		 *   destroyed as soon as this constructor returns.
		 *   Channels are ordered as RGBA.
		 *   Must be destroyed by caller.
		 *
		 * Note that width and height must each be powers of 2 and
		 * not larger than 256 (for 3DFX compatability).  Additionally,
		 * for 3DFX compatability, the aspect ratio should not exceed 8:1.
		 */
		void setTextureData( Image *inImage );
		

		
		/**
		 * Enables this texture.
		 */
		void enable();

		
		
		/**
		 * Disables this texture and all of its layers.
		 */
		void disable();		

		
		
	private:

		unsigned int mTextureID;

	};






inline SingleTextureGL::SingleTextureGL( Image *inImage ) {

    glGenTextures( 1, &mTextureID );
    
	setTextureData( inImage );
	}



inline SingleTextureGL::~SingleTextureGL() {
	unsigned int *textureIDs = new unsigned int[1];
	textureIDs[0] = mTextureID;
	glDeleteTextures( 1, textureIDs );
	delete [] textureIDs;
	}



inline void SingleTextureGL::enable() {	
    glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, mTextureID ); 

    int error = glGetError();
	if( error != GL_NO_ERROR ) {		// error
		printf( "Error binding texture id %d, error = %d\n",
                mTextureID, error );
		}
	}



inline void SingleTextureGL::disable() {
	glDisable( GL_TEXTURE_2D );
	}
	
	
	
#endif


