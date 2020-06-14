#pragma once

#include "NoDeviceException.h"
#include "NoContextException.h"
#include "CorruptedFileException.h"
#include "InvalidPathException.h"
#include <AL/al.h>
#include <AL/alc.h>

namespace SimpleAudio
{
	/**
	 * Simple Audio System Class.
	 */
	class Listener
	{
		public:
			/**
			 * Initilizes this system with the default audio device.
			 *
			 * @throws NoDeviceException in case that no device is available
			 */
			void initWithDefaultDevice(void) throw(NoDeviceException, NoContextException);

			/**
			 * Set the listener's position
			 *
			 * @param x X Coordinate
			 * @param y Y Coordinate
			 * @param z Z Coordinate
			 */
			void setPosition(const float x, const float y, const float z);

			/**
			 * Set the listener's orientation
			 *
			 * @param atX X Coordinate to look at
			 * @param atY Y Coordinate to look at
			 * @param atZ Z Coordinate to look at
			 * @param upX X Coordinate of up vector
			 * @param upY Y Coordinate of up vector
			 * @param upZ Z Coordinate of up vector
			 */
			void setOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ);

			/**
			 * Set the listener's velocity
			 *
			 * @param x Velocity along the x-axis
			 * @param y Velocity along the y-axis
			 * @param z Velocity along the z-axis
			 */
			void setVelocity(const float x, const float y, const float z);

			/**
			 * Listener
			 */
			Listener(void);

			/**
			 * Create new instance by copying another instance
			 *
			 * @param src Reference to the other instance
			 */
			Listener(const Listener &src);

			/**
			 * Teardown
			 */
			~Listener(void);

			/**
			 * Assign data from another instance
			 *
			 * @param src Reference to the other instance
			 * @return Reference to this instance
			 */
			Listener& operator = (const Listener &src);

		private:
			/**
			 * Active audio device
			 */
			ALCdevice* _device;

			/**
			 * Active context
			 */
			ALCcontext* _context;
	};
}
