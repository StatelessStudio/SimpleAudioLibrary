#pragma once

#include "SourceState.h"

#include <string>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudio
{	
	/**
	 * Audio Entity Class.
	 */
	class Source
	{
		public:
			/**
			 * Source name
			 */
			const char* name;

			/**
			 * Creates new instance of this class.
			 */
			Source();

			/**
			 * Creates new instance of this class.
			 * 
			 * @param n Source name
			 */
			Source(const char* n);

			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			Source(const Source &src);
			
			/**
			 * Releases this instance of this class.
			 */
			~Source(void);

			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			Source& operator = (Source &src);
			
			/**
			 * Starts playing its content of this audio entity.
			 *
			 * @param buffer - Sound buffer to play
			 * @param loop - true if this content should be running in a loop otherwise false
			 */
			void play(unsigned int buffer, const bool loop=false);
			
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
			 * Stores current source id of this entity.
			 */
			unsigned int _source;
			
			/**
			 * Stores current state of this entity.
			 */
			SourceState _state;
	};
}
