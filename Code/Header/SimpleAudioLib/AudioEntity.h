/**
 * Simple Audio Library - Audio Entity Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Header/SimpleAudioLib/AudioEntity.h
 * @version 	1.0.0 27-Jul-13
 * @version		1.1.0 28-Jul-13
 * @version		1.2.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __AUDIO_ENTITY_H__
#define __AUDIO_ENTITY_H__

#include <string>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Audio Entity State List.
	 */
	enum EAudioEntityState
	{
		/**
		 * Audio entity stops playing.
		 */
		STATE_STOP = 0,
		
		/**
		 * Audio entity plays its audio data.
		 */
		STATE_PLAY = 1,
		
		/**
		 * Audio entity pauses playing its audio data.
		 */
		STATE_PAUSE = 2,
		
		/**
		 * Audio entity rewinds current play postion to the beginning.
		 */
		STATE_REWIND = 3
	};
	
	/**
	 * Audio Entity Class.
	 */
	class AudioEntity
	{
		public:
			/**
			 * Creates new instance of this class.
			 *
			 * @param data 			- bineary audio content
			 * @param size			- size of the bineary audio content
			 * @param frequency		- audio frequency
			 * @param numChannels	- number of channels that audio content is made for
			 */
			AudioEntity(unsigned char* data, const unsigned int size, const unsigned int frequency, const short numChannels);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			AudioEntity(const AudioEntity &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~AudioEntity(void);
			
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			AudioEntity& operator = (AudioEntity &src);
			
			/**
			 * Starts playing its content of this audio entity.
			 *
			 * @param loop - true if this content should be running in a loop otherwise false
			 */
			void play(const bool loop=false);
			
			/**
			 * Pauses playing its content of this audio entity.
			 */
			void pause(void);
			
			/**
			 * Stops playing its content of this audio entity.
			 */
			void stop(void);
			
			/**
			 * Rewinds current play position to the beginning.
			 */
			void rewind(void);
			
			/**
			 * Releases all reserved memory.
			 */
			void release(void);
			
			/**
			 * Assigns position to this audio entity.
			 *
			 * @param x - value on the x-axis of audio entity position
			 * @param y - value on the y-axis of audio entity position
			 * @param z - value on the z-axis of audio entity position
			 */
			void setPosition(const float x, const float y, const float z);
			
			/**
			 * Assigns vector of its direction this autio entity is heading.
			 *
			 * @param x - value on the x-axis of audio entity direction
			 * @param y - value on the y-axis of audio entity direction
			 * @param z - value on the z-axis of audio entity direction
			 */
			void setDirection(const float x, const float y, const float z);
			
			/**
			 * Assigns velocity vector to this audio entity.
			 *
			 * @param x - value on the x-axis of audio entity velocity
			 * @param y - value on the y-axis of audio entity velocity
			 * @param z - value on the z-axis of audio entity velocity
			 */
			void setVelocity(const float x, const float y, const float z);
			
			/**
			 * Assigns pitch value to this audio entity.
			 *
			 * @param pitch - new pitch value
			 */
			void setPitch(const float pitch);
			
			/**
			 * Assigns gain value to this audio entity.
			 *
			 * @param gain - new gain value
			 */
			void setGain(const float gain);
			
		private:
		
			/**
			 * Stores current buffer id of this entity.
			 */
			unsigned int _buffer;
			
			/**
			 * Stores current source id of this entity.
			 */
			unsigned int _source;
			
			/**
			 * Stores current state of this entity.
			 */
			EAudioEntityState _state;
	};
}

#endif