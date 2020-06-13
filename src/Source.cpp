#include "Source.h"
#include <AL.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Creates new instance of this class.
	 */
	Source::Source() :
		_source(0),
		_state(STATE_STOP)
	{
		alGenSources(1, &this->_source);
	}

	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	Source::Source(const Source &src) :
		_source(src._source),
		_state(STATE_STOP)
	{
	}

	/**
	 * Releases this instance of this class.
	 */
	Source::~Source(void)
	{
	}

	/**
	 * Assigns data by another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 * @return reference to this instance of this class
	 */
	Source& Source::operator = (Source &src)
	{
		return *this;
	}
	
	/**
	 * Starts playing its content of this audio entity.
	 *
	 * @param buffer - Sound buffer to play
	 * @param loop - true if this content should be running in a loop otherwise false
	 */
	void Source::play(unsigned int buffer, const bool loop)
	{
		if (this->_state != STATE_PLAY) {
			this->_state = STATE_PLAY;
			alSourcei(this->_source, AL_BUFFER, buffer);
			
			alSourcei(this->_source, AL_LOOPING, loop);
			alSourcePlay(this->_source);

			this->_state = STATE_STOP;
		}
	}
	
	/**
	 * Pauses playing its content of this audio entity.
	 */
	void Source::pause(void)
	{
		if (this->_state != STATE_PAUSE) {
			this->_state = STATE_PAUSE;
			
			alSourcePause(this->_source);
		}
	}
	
	/**
	 * Stops playing its content of this audio entity.
	 */
	void Source::stop(void)
	{
		if (this->_state != STATE_STOP) {
			this->_state = STATE_STOP;
			
			alSourceStop(this->_source);
		}
	}
	
	/**
	 * Rewinds current play position to the beginning.
	 */
	void Source::rewind(void)
	{
		if (this->_state != STATE_REWIND) {
			this->_state = STATE_REWIND;
			
			alSourceStop(this->_source);
		}
	}
	
	/**
	 * Assigns position to this audio entity.
	 *
	 * @param x - value on the x-axis of audio entity position
	 * @param y - value on the y-axis of audio entity position
	 * @param z - value on the z-axis of audio entity position
	 */
	void Source::setPosition(const float x, const float y, const float z)
	{
		alSource3f(this->_source, AL_POSITION, x, y, z);
	}
	
	/**
	 * Assigns vector of its direction this autio entity is heading.
	 *
	 * @param x - value on the x-axis of audio entity direction
	 * @param y - value on the y-axis of audio entity direction
	 * @param z - value on the z-axis of audio entity direction
	 */
	void Source::setDirection(const float x, const float y, const float z)
	{
		float direction[3] = {x, y, z};
		
		alSourcefv(this->_source, AL_DIRECTION, direction);
	}
	
	/**
	 * Assigns velocity vector to this audio entity.
	 *
	 * @param x - value on the x-axis of audio entity velocity
	 * @param y - value on the y-axis of audio entity velocity
	 * @param z - value on the z-axis of audio entity velocity
	 */
	void Source::setVelocity(const float x, const float y, const float z)
	{
		alSource3f(this->_source, AL_VELOCITY, x, y, z);
	}
	
	/**
	 * Assigns pitch value to this audio entity.
	 *
	 * @param pitch - new pitch value
	 */
	void Source::setPitch(const float pitch)
	{
		alSourcef(this->_source, AL_PITCH, pitch);
	}
	
	/**
	 * Assigns gain value to this audio entity.
	 *
	 * @param gain - new gain value
	 */
	void Source::setGain(const float gain)
	{
		alSourcef(this->_source, AL_GAIN, gain);
	}
	
	/**
	 * Releases all reserved memory.
	 */
	void Source::release(void)
	{
		alDeleteSources(1, &this->_source);
	}
}
