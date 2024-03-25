/*
 * Modification History
 *
 * 2000-December-21		Jason Rohrer
 * Created. 
 */
 
 
#ifndef CHANNEL_FILTER_INCLUDED
#define CHANNEL_FILTER_INCLUDED
 
 
/**
 * Interface for a class that can filter a 2D channel.
 *
 * @author Jason Rohrer 
 */
class ChannelFilter { 
	
	public:
		virtual void apply( double *inChannel, int inWidth, int inHeight ) = 0;
		
	};
	
#endif
