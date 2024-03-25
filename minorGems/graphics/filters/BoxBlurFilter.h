/*
 * Modification History
 *
 * 2000-December-21		Jason Rohrer
 * Created.
 *
 * 2001-January-6		Jason Rohrer
 * Added a getRadius function for completeness.  
 */
 
 
#ifndef BOX_BLUR_FILTER_INCLUDED
#define BOX_BLUR_FILTER_INCLUDED
 
#include "minorGems/graphics/ChannelFilter.h" 
 
/**
 * Blur convolution filter that uses a box for averaging.
 *
 * @author Jason Rohrer 
 */
class BoxBlurFilter : public ChannelFilter { 
	
	public:
		
		/**
		 * Constructs a box filter.
		 *
		 * @param inRadius the radius of the box in pixels.
		 */
		BoxBlurFilter( int inRadius );
		
		
		/**
		 * Sets the box radius.
		 *
		 * @param inRadius the radius of the box in pixels.
		 */
		void setRadius( int inRadius );
		
		
		/**
		 * Gets the box radius.
		 *
		 * @return the radius of the box in pixels.
		 */
		int getRadius();
		
		
		// implements the ChannelFilter interface
		void apply( double *inChannel, int inWidth, int inHeight );

	private:
		int mRadius;
	};
	
	
	
inline BoxBlurFilter::BoxBlurFilter( int inRadius ) 
	: mRadius( inRadius ) {	
	
	}



inline void BoxBlurFilter::setRadius( int inRadius ) {
	mRadius = inRadius;
	}



inline int BoxBlurFilter::getRadius() {
	return mRadius;
	}	
	
	
	
inline void BoxBlurFilter::apply( double *inChannel, 
	int inWidth, int inHeight ) {
	
	double *blurredChannel = new double[ inWidth * inHeight ];
	
	for( int y=0; y<inHeight; y++ ) {
		int yIndexContrib = y * inWidth;
		
		int startBoxY = y - mRadius;
		int endBoxY = y + mRadius;
		
		if( startBoxY < 0 ) {
			startBoxY = 0;
			}
		if( endBoxY >= inHeight ) {
			endBoxY = inHeight - 1;
			}
		
		int boxSizeY = endBoxY - startBoxY + 1;
		
		for( int x=0; x<inWidth; x++ ) {
			
			int startBoxX = x - mRadius;
			int endBoxX = x + mRadius;
			
			if( startBoxX < 0 ) {
				startBoxX = 0;
				}
			if( endBoxX >= inWidth ) {
				endBoxX = inWidth - 1;
				}
			
			int boxSizeX = endBoxX - startBoxX + 1;
			
			// sum all pixels in the box around this pixel
			for( int boxY = startBoxY; boxY<=endBoxY; boxY++ ) {
				int yBoxIndexContrib = boxY * inWidth;
				for( int boxX = startBoxX; boxX<=endBoxX; boxX++ ) {	
		
					blurredChannel[ yIndexContrib + x ]
						+= inChannel[ yBoxIndexContrib + boxX ];
					}
				}
			
			// divide to complete the average
			blurredChannel[ yIndexContrib + x ] /= (boxSizeX * boxSizeY);
			}
		}
	
	// copy blurred image back into passed-in image
	memcpy( inChannel, blurredChannel, sizeof(double) * inWidth * inHeight );
	
	delete [] blurredChannel;	
	}
	
#endif
