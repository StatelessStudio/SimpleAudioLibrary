#pragma once

#include "SourceState.h"

namespace SimpleAudio
{
	/**
	 * Source
	 * 
	 * A source is a "player" that has a position (and possibly velocity) where
	 * 	the sound comes from. It can also have a pitch and gain that is applied
	 * 	to all sounds that it plays
	 */
	class Source
	{
		public:
			/**
			 * Source name
			 */
			const char* name;

			/**
			 * Source
			 */
			Source();

			/**
			 * Source w/ name
			 * 
			 * @param n Source name
			 */
			Source(const char* n);

			/**
			 * Create new instance by copying another instance
			 *
			 * @param src Reference to the other instance
			 */
			Source(const Source &src);

			/**
			 * Teardown
			 */
			~Source(void);

			/**
			 * Assign data from another instance
			 *
			 * @param src Reference to the other instance
			 * @return Reference to this instance
			 */
			Source& operator = (Source &src);

			/**
	 		 * Play a sound from this source
			 *
			 * @param buffer Sound buffer to play
			 * @param loop (Optional) Set to true to loop the sound
			 */
			void play(unsigned int buffer, const bool loop=false);

			/**
			 * Pause sounds from this source
			 */
			void pause(void);

			/**
			 * Stop sounds from this source
			 */
			void stop(void);

			/**
			 * Set the source position
			 *
			 * @param x X Coordinate
			 * @param y Y Coordinate
			 * @param z Z Coordinate
			 */
			void setPosition(const float x, const float y, const float z);

			/**
			 * Set the direction the source is facing
			 *
			 * @param x Direction on the x-axis the source is facing
			 * @param y Direction on the y-axis the source is facing
			 * @param z Direction on the z-axis the source is facing
			 */
			void setDirection(const float x, const float y, const float z);

			/**
			 * Set the source's velocity
			 *
			 * @param x Velocity along the x-axis
			 * @param y Velocity along the y-axis
			 * @param z Velocity along the z-axis
			 */
			void setVelocity(const float x, const float y, const float z);

			/**
			 * Set the source's pitch
			 *
			 * @param pitch New pitch (1 is unchanged)
			 */
			void setPitch(const float pitch);

			/**
			 * Set the source's gain
			 *
			 * @param gain New gain (1 is unchanged)
			 */
			void setGain(const float gain);

		private:

			/**
			 * Source ID
			 */
			unsigned int _source;

			/**
			 * Current state
			 */
			SourceState _state;
	};
}
