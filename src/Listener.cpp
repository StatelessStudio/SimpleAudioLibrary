#include "CoreSystem.h"
#include <stdlib.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Stores the only instance of this class.
	 *
	 * @note This is part of the Singleton-Pattern.
	 */
	CoreSystem* CoreSystem::_instance = NULL;
	
	/**
	 * Creates new instance of this class.
	 */
	CoreSystem::CoreSystem(void) :
		_device(NULL),
		_context(NULL)
	{
	}
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	CoreSystem::CoreSystem(const CoreSystem &src) :
		_device(NULL),
		_context(NULL)
	{
	}

	/**
	 * Releases this instance of this class.
	 */
	CoreSystem::~CoreSystem(void)
	{
	}
	
	/**
	 * Assigns data by another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 * @return CoreSystem - reference to this instance of this class
	 */
	CoreSystem& CoreSystem::operator = (const CoreSystem &src)
	{
		return *this;
	}
	
	/**
	 * Returns only existing instance of this class.
	 *
	 * In case that the instance doesn't exist yet, 
	 * this method will create one.
	 *
	 * @note This is part of the Singleton-Pattern.
	 * @return CoreSystem - reference to the only existing instance of this class.
	 */
	CoreSystem& CoreSystem::getInstance(void)
	{
		if(_instance == NULL){
			_instance = new CoreSystem();
		}
		
		return *_instance;
	}
	
	/**
	 * Releases memory of this instance.
	 *
	 * @note This is part of the Singleton-Pattern.
	 */
	void CoreSystem::release(void)
	{
		if (_instance != NULL) {
			_instance->_release();
			
			delete _instance;
			_instance = NULL;
		}
	}
	
	/**
	 * Releases reserved memory of this module.
	 */
	void CoreSystem::_release(void)
	{
		if (this->_context != NULL) {
			alcMakeContextCurrent(NULL);
			alcDestroyContext(this->_context);
		}
		
		if (this->_device != NULL) {
			alcCloseDevice(this->_device);
		}
	}

	/**
	 * Initilizes this system with the default audio device.
	 *
	 * @throws NoDeviceException - in case that no device is available
	 */
	void CoreSystem::initWithDefaultDevice(void) throw(NoDeviceException, NoContextException)
	{
		this->_device = alcOpenDevice(NULL);
		
		if (this->_device == NULL) {
			throw NoDeviceException("Init with default device failure: Couldn't open a connection to audio device!");
		}
		
		this->_context = alcCreateContext(this->_device, NULL);
		
		if (this->_context == NULL) {
			throw NoContextException("Init with default device failure: Couldn't create OpenAL context!");
		} else {
			alcMakeContextCurrent(this->_context);
		}
	}
	
	/**
	 * Assigns position to listener.
	 *
	 * @param x - value on the x-axis of listener position
	 * @param y - value on the y-axis of listener position
	 * @param z - value on the z-axis of listener position
	 */
	void CoreSystem::setListenerPosition(const float x, const float y, const float z)
	{
		alListener3f(AL_POSITION, x, y, z);
	}
	
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
	void CoreSystem::setListenerOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ)
	{
		float orientation[6] = {atX, atY, atZ, upX, upY, upZ};
		
		alListenerfv(AL_ORIENTATION, orientation);
	}
	
	/**
	 * Assigns velocity to listener.
	 *
	 * @param x - value on the x-axis of listener velocity
	 * @param y - value on the y-axis of listener velocity
	 * @param z - value on the z-axis of listener velocity
	 */
	void CoreSystem::setListenerVelocity(const float x, const float y, const float z)
	{
		alListener3f(AL_VELOCITY, x, y, z);
	}
}
