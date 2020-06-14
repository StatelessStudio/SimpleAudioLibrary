#include "Listener.h"

#if _DEBUG
#include <iostream>
#endif

namespace SimpleAudio
{

Listener::Listener(void) :
	_device(NULL),
	_context(NULL)
{
#if _DEBUG
	std::cout << "[Listener] Initializing..." << std::endl;
#endif
}

Listener::Listener(const Listener &src) :
	_device(NULL),
	_context(NULL)
{
}

Listener::~Listener(void)
{
#if _DEBUG
	std::cout << "[Listener] Teardown..." << std::endl;
#endif
	if (this->_context != NULL) {
		alcMakeContextCurrent(NULL);
		alcDestroyContext(this->_context);
	}

	if (this->_device != NULL) {
		alcCloseDevice(this->_device);
	}
}

Listener& Listener::operator = (const Listener &src)
{
	return *this;
}

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

void Listener::setPosition(const float x, const float y, const float z)
{
	alListener3f(AL_POSITION, x, y, z);
}

void Listener::setOrientation(const float atX, const float atY, const float atZ, const float upX, const float upY, const float upZ)
{
	float orientation[6] = {atX, atY, atZ, upX, upY, upZ};

	alListenerfv(AL_ORIENTATION, orientation);
}

void Listener::setVelocity(const float x, const float y, const float z)
{
	alListener3f(AL_VELOCITY, x, y, z);
}

} // namespace SimpleAudio
