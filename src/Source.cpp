#include "Source.h"
#include <AL.h>

#ifdef _DEBUG
#include <iostream>
#endif

namespace SimpleAudio
{

Source::Source() :
	_source(0),
	_state(SourceState::STOP),
	name("")
{
#if _DEBUG
std::cout << "[Source][Noname] Initializing..." << std::endl;
#endif
	alGenSources(1, &this->_source);
}

Source::Source(const char* n) :
	_source(0),
	_state(SourceState::STOP),
	name(n)
{
#if _DEBUG
std::cout << "[Source][" << name << "] Initializing..." << std::endl;
#endif
	alGenSources(1, &this->_source);
}

Source::Source(const Source &src) :
	_source(src._source),
	_state(SourceState::STOP)
{
}

Source::~Source(void)
{
#if _DEBUG
std::cout << "[Source][" << name << "] Teardown..." << std::endl;
#endif
	alDeleteSources(1, &this->_source);
}

Source& Source::operator = (Source &src)
{
	return *this;
}

void Source::play(unsigned int buffer, const bool loop)
{
	if (this->_state != SourceState::PLAY) {
		this->_state = SourceState::PLAY;
		alSourcei(this->_source, AL_BUFFER, buffer);

		alSourcei(this->_source, AL_LOOPING, loop);
		alSourcePlay(this->_source);

		this->_state = SourceState::STOP;
	}
}

void Source::pause(void)
{
	if (this->_state != SourceState::PAUSE) {
		this->_state = SourceState::PAUSE;

		alSourcePause(this->_source);
	}
}

void Source::stop(void)
{
	if (this->_state != SourceState::STOP) {
		this->_state = SourceState::STOP;

		alSourceStop(this->_source);
	}
}

void Source::setPosition(const float x, const float y, const float z)
{
	alSource3f(this->_source, AL_POSITION, x, y, z);
}

void Source::setDirection(const float x, const float y, const float z)
{
	float direction[3] = {x, y, z};

	alSourcefv(this->_source, AL_DIRECTION, direction);
}

void Source::setVelocity(const float x, const float y, const float z)
{
	alSource3f(this->_source, AL_VELOCITY, x, y, z);
}

void Source::setPitch(const float pitch)
{
	alSourcef(this->_source, AL_PITCH, pitch);
}

void Source::setGain(const float gain)
{
	alSourcef(this->_source, AL_GAIN, gain);
}

} // namespace SimpleAudio
