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
	 *
	 * @note This class is implemented as singleton.
	 */
	class CoreSystem
	{
		public:
			/**
			 * Returns only existing instance of this class.
			 *
			 * In case that the instance doesn't exist yet, 
			 * this method will create one.
			 *
			 * @note This is part of the Singleton-Pattern.
			 * @return reference to the only existing instance of this class.
			 */
			static CoreSystem& getInstance(void);
			
			/**
			 * Releases memory of this instance.
			 *
			 * @note This is part of the Singleton-Pattern.
			 */
			static void release(void);
			
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
			void setListenerPosition(const float x, const float y, const float z);
			
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
			void setListenerOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ);
			
			/**
			 * Assigns velocity to listener.
			 *
			 * @param x - value on the x-axis of listener velocity
			 * @param y - value on the y-axis of listener velocity
			 * @param z - value on the z-axis of listener velocity
			 */
			void setListenerVelocity(const float x, const float y, const float z);
			
		private:
			/**
			 * Creates new instance of this class.
			 */
			CoreSystem(void);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			CoreSystem(const CoreSystem &src);
			
			/**
			 * Releases this instance of this class.
			 */
			~CoreSystem(void);
			
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			CoreSystem& operator = (const CoreSystem &src);	
			
			/**
			 * Releases reserved memory of this module.
			 */
			void _release(void);
			
		private:
			/**
			 * Stores the only instance of this class.
			 *
			 * @note This is part of the Singleton-Pattern.
			 */
			static CoreSystem* _instance;
			
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
