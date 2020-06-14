#include "Listener.h"
#include <stdlib.h>

#if _DEBUG
#include <iostream>
#endif

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
	Listener* Listener::_instance = NULL;
	
	/**
	 * Creates new instance of this class.
	 */
	Listener::Listener(void) :
		_device(NULL),
		_context(NULL)
	{
#if _DEBUG
		std::cout << "[Listener] Initializing..." << std::endl;
#endif
	}
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	Listener::Listener(const Listener &src) :
		_device(NULL),
		_context(NULL)
	{
	}

	/**
	 * Releases this instance of this class.
	 */
	Listener::~Listener(void)
	{
#if _DEBUG
		std::cout << "[Listener] Teardown..." << std::endl;
#endif
	}
	
	/**
	 * Assigns data by another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 * @return Listener - reference to this instance of this class
	 */
	Listener& Listener::operator = (const Listener &src)
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
	 * @return Listener - reference to the only existing instance of this class.
	 */
	Listener& Listener::getInstance(void)
	{
		if(_instance == NULL){
			_instance = new Listener();
		}
		
		return *_instance;
	}
	
	/**
	 * Releases memory of this instance.
	 *
	 * @note This is part of the Singleton-Pattern.
	 */
	void Listener::release(void)
	{
#if _DEBUG
		std::cout << "[Listener] Release..." << std::endl;
#endif
		if (_instance != NULL) {
			_instance->_release();
			
			delete _instance;
			_instance = NULL;
		}
	}
	
	/**
	 * Releases reserved memory of this module.
	 */
	void Listener::_release(void)
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
	void Listener::initWithDefaultDevice(void) throw(NoDeviceException, NoContextException)
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
	void Listener::setPosition(const float x, const float y, const float z)
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
	void Listener::setOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ)
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
	void Listener::setVelocity(const float x, const float y, const float z)
	{
		alListener3f(AL_VELOCITY, x, y, z);
	}
}
