/*
 * Modification History
 *
 * 2001-October-13	Jason Rohrer
 * Created.
 * Changed to support alpha-blended fonts, even for 3-channel font textures.
 * Fixed a bug in the font coloring.
 *
 * 2001-November-3	Jason Rohrer
 * Fixed some missing includes.
 */



#ifndef TEXT_GL_INCLUDED
#define TEXT_GL_INCLUDED

#include <stdio.h>
#include <stdarg.h>

#include <GL/gl.h>

#include "minorGems/graphics/Color.h"
#include "minorGems/graphics/Image.h"

#include "minorGems/graphics/openGL/SingleTextureGL.h"

/**
 * A class for drawing text strings to an OpenGL context.
 * Fonts are texture maps.
 *
 * @author Jason Rohrer
 */
class TextGL {


		
	public:



		/**
		 * Constructs a gl text object.
		 *
		 * Note that this function can only be called
		 * after an OpenGL drawing context has been created.
		 *
		 * @param inImage the image to use as a font texture.
		 *   Must be a square image with dimensions that are a power of 2.
		 *   Fonts in the image are assumed to be in row-major ASCII order,
		 *   with 16 characters per row.
		 *   Must be destroyed by caller.  Can be destroyed as soon as
		 *   this constructor returns.
		 * @param inUseAlpha true iff alpha blending should
		 *   be used when rendering the font textures.  If alpha
		 *   blending is enabled and the image has only 3 channels,
		 *   only the red channel (channel 0)
		 *   of the image is used:  it is interpreted as the alpha
		 *   channel for a white fontset.
		 *
		 */
		TextGL( Image *inImage, char inUseAlpha = false );



		virtual ~TextGL();



		/**
		 * Sets the main color of the font.
		 *
		 * If the gradient color is non-NULL, this color will be at the
		 * top of the fonts.  Otherwise, the entire extent
		 * of the font will be this color.
		 *
		 * @param inColor the main color of the font.
		 *   Will be destroyed when this class is destroyed.
		 */
		void setFontColor( Color *inColor );



		/**
		 * Gets the main color of the font.
		 *
		 * If the gradient color is non-NULL, this color will be at the
		 * top of the fonts. Otherwise, the entire extent
		 * of the font will be this color.
		 *
		 * @return the main color of the font.
		 *   Will be destroyed when this class is destroyed.
		 */
		Color *getFontColor();

		
		
		/**
		 * Sets the gradient color of the font.
		 *
		 * If non-NULL, this color will be at the
		 * bottom of the fonts.
		 *
		 * @param inColor the gradient color of the font, or
		 *   NULL to disable the gradient.
		 *   Will be destroyed when this class is destroyed.
		 */
		void setGradientColor( Color *inColor );



		/**
		 * Gets the gradient color of the font.
		 *
		 * If non-NULL, this color will be at the
		 * bottom of the fonts.
		 *
		 * @return the gradient color of the font, or
		 *   NULL to disable the gradient.
		 *   Will be destroyed when this class is destroyed.
		 */
		Color *getGradientColor();



		/**
		 * Draws a text string into a specified region of the
		 * context.  Text is squeezed to fit into the region.
		 *
		 * Uses the currently active OpenGL projection settings.
		 *
		 * @param inString the \0-delimited string to draw.
		 *   Must be destroyed by caller if not const.
		 * @param inX the x coordinate of the region's lower-left
		 *   corner.
		 * @param inY the y coordinate of the region's lower-left
		 *   corner.
		 * @param inWidth the width of the region.
		 * @param inHeight the height of the region.
		 */
		void drawText( char *inString, double inX, double inY,
					   double inWidth, double inHeight );



	protected:

		Color *mFontColor;
		Color *mGradientColor;
		
		SingleTextureGL *mFontTexture;

		char mUseAlpha;

		/**
		 * Draws a character into a specified region of the
		 * context.  The character is squeezed to fit into the region.
		 *
		 * Uses the currently active OpenGL projection settings.
		 *
		 * @param inCharacter the character to draw.
		 * @param inX the x coordinate of the region's lower-left
		 *   corner.
		 * @param inY the y coordinate of the region's lower-left
		 *   corner.
		 * @param inWidth the width of the region.
		 * @param inHeight the height of the region.
		 */
		void drawCharacter( char inCharacter, double inX, double inY,
							double inWidth, double inHeight );


		
   	};



inline TextGL::TextGL( Image *inImage, char inUseAlpha )
	: mFontColor( new Color( 1.0f, 1.0f, 1.0f, 1.0f ) ),
	  mGradientColor( NULL ), mUseAlpha( inUseAlpha ) {

	if( inUseAlpha && inImage->getNumChannels() != 4 ) {
	
		Image *fontImage = new Image( inImage->getWidth(),
									  inImage->getHeight(),
									  4 );

		int numPixels = inImage->getWidth() * inImage->getHeight();

	
		// copy the red channel of inImage into our alpha
		memcpy( fontImage->getChannel(3), inImage->getChannel(0),
				numPixels * sizeof( double ) );

		// set other channels to white
		for( int c=0; c<3; c++ ) {
			double *channel = fontImage->getChannel( c );
			for( int p=0; p<numPixels; p++ ) {
				channel[p] = 1.0;
				}
			}
	
	
		mFontTexture = new SingleTextureGL( fontImage );

		delete fontImage;
		}
	else {
		// use the texture directly
		mFontTexture = new SingleTextureGL( inImage );
		}
	}



inline TextGL::~TextGL() {
	delete mFontTexture;
	if( mFontColor != NULL ) {
		delete mFontColor;
		}
	if( mGradientColor != NULL ) {
		delete mGradientColor;
		}
	}



inline void TextGL::setFontColor( Color *inColor ) {
	if( mFontColor != NULL && mFontColor != inColor ) {
		delete mFontColor;
		}
	mFontColor = inColor;
	}



inline void TextGL::setGradientColor( Color *inColor ) {
	if( mGradientColor != NULL && mGradientColor != inColor ) {
		delete mGradientColor;
		}
	mGradientColor = inColor;
	}



inline Color *TextGL::getFontColor() {
	return mFontColor;
	}



inline Color *TextGL::getGradientColor() {
	return mGradientColor;
	}



inline void TextGL::drawText( char *inString, double inX, double inY,
							  double inWidth, double inHeight ) {

	int numChars = strlen( inString );

	double charWidth = inWidth / numChars;

	double currentCharX = inX;

	char oldBlendState = glIsEnabled( GL_BLEND );

	if( mUseAlpha ) {
		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		}
	
	for( int i=0; i<numChars; i++ ) {
		char c = inString[i];

		drawCharacter( c, currentCharX, inY, charWidth, inHeight );
		
		currentCharX += charWidth;
		}

	if( mUseAlpha ) {
		// restore blend state if necessary
		if( !oldBlendState ) {
			glDisable( GL_BLEND );
			}
		}
	
	}



inline void TextGL::drawCharacter( char inCharacter, double inX, double inY,
								   double inWidth, double inHeight ) {

	double charStartX = inX;
	double charStartY = inY;

	double charEndX = inX + inWidth;
	double charEndY = inY + inHeight;

	// y start and end in texture flipped
	double textureStartX = ( inCharacter % 16  ) / 16.0;
	double textureStartY = ( inCharacter / 16  ) / 16.0 + 1.0 / 16;
	double textureEndX = textureStartX + 1.0 / 16;
	double textureEndY = textureStartY - 1.0 / 16;

	
	mFontTexture->enable();

	glBegin( GL_QUADS ); {
		if( mGradientColor != NULL ) {
			glColor4f( mGradientColor->r, mGradientColor->g,
					   mGradientColor->b, mGradientColor->a );
			}
		else {
			glColor4f( mFontColor->r, mFontColor->g,
					   mFontColor->b, mFontColor->a );
			}
				 
		glTexCoord2f( textureStartX, textureStartY );
		glVertex2d( charStartX, charStartY );
		
		glTexCoord2f( textureEndX, textureStartY );
		glVertex2d( charEndX, charStartY ); 

		
		glColor4f( mFontColor->r, mFontColor->g,
				   mFontColor->b, mFontColor->a );

		
		glTexCoord2f( textureEndX, textureEndY );
		glVertex2d( charEndX, charEndY );
		
		glTexCoord2f( textureStartX, textureEndY );
		glVertex2d( charStartX, charEndY );
		}
	glEnd();


	mFontTexture->disable();
	}



#endif
