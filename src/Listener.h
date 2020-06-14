#ifndef __SIMPLE_AUDIO_SYSTEM_H__
#define __SIMPLE_AUDIO_SYSTEM_H__

#include "NoDeviceException.h"
#include "NoContextException.h"
#include "CorruptedFileException.h"
#include "InvalidPathException.h"
#include <AL/al.h>
#include <AL/alc.h>

#define SIMPLE_AUDIO_LIB_VERSION "0.2.0"
#define SIMPLE_AUDIO_LIB_VERSION_0_2_0 1

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
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
			 * @throws NoDeviceException - in case that no device is available
			 */
			void initWithDefaultDevice(void) throw(NoDeviceException, NoContextException);

			/**
			 * Assigns position to listener.
			 *
			 * @param x - value on the x-axis of listener position
			 * @param y - value on the y-axis of listener position
			 * @param z - value on the z-axis of listener position
			 */
			void setPosition(const float x, const float y, const float z);
			
			/**
			 * Assigns orientation to listener.
			 *
			 * @param atX - value on the x-axis of listener points at
			 * @param atY - value on the y-axis of listener points at
			 * @param atZ - value on the z-axis of listener points at
			 * @param upX - value on the x-axis of listener up vector
			 * @param upY - value on the y-axis of listener up vector
			 * @param upZ - value on the z-axis of listener up vector
			 */
			void setOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ);
			
			/**
			 * Assigns velocity to listener.
			 *
			 * @param x - value on the x-axis of listener velocity
			 * @param y - value on the y-axis of listener velocity
			 * @param z - value on the z-axis of listener velocity
			 */
			void setVelocity(const float x, const float y, const float z);

			/**
			 * Creates new instance of this class.
			 */
			Listener(void);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			Listener(const Listener &src);
			
			/**
			 * Releases this instance of this class.
			 */
			~Listener(void);
			
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			Listener& operator = (const Listener &src);	
			
		private:			
			/**
			 * Stores selected audio device of this system.
			 */
			ALCdevice* _device;
			
			/**
			 * Stores active context of this system 
			 */
			ALCcontext* _context;
	};
}

#endif
