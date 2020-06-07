#include "AudioEntity.h"
#include <OpenAL/al.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Creates new instance of this class.
	 *
	 * @param data 			- bineary audio content
	 * @param size			- size of the bineary audio content
	 * @param frequency		- audio frequency
	 * @param numChannels	- number of channels that audio content is made for
	 */
	AudioEntity::AudioEntity(unsigned char* data, const unsigned int size, const unsigned int frequency, const short numChannels) :
		_buffer(0),
		_source(0),
		_state(STATE_STOP)
	{
		alGenBuffers(1, &this->_buffer);
		alBufferData(this->_buffer, (numChannels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data, size, frequency);
		
		alGenSources(1, &this->_source);
		alSourcei(this->_source, AL_BUFFER, this->_buffer);
	}
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	AudioEntity::AudioEntity(const AudioEntity &src) :
		_buffer(src._buffer),
		_source(src._source),
		_state(STATE_STOP)
	{
	}
	
	/**
	 * Releases this instance of this class.
	 */
	AudioEntity::~AudioEntity(void)
	{
	}
	
	/**
	 * Assigns data by another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 * @return reference to this instance of this class
	 */
	AudioEntity& AudioEntity::operator = (AudioEntity &src)
	{
		return *this;
	}
	
	/**
	 * Starts playing its content of this audio entity.
	 *
	 * @param loop - true if this content should be running in a loop otherwise false
	 */
	void AudioEntity::play(const bool loop)
	{
		if (this->_state != STATE_PLAY) {
			this->_state = STATE_PLAY;
			
			alSourcei(this->_source, AL_LOOPING, loop);
			alSourcePlay(this->_source);
		}
	}
	
	/**
	 * Pauses playing its content of this audio entity.
	 */
	void AudioEntity::pause(void)
	{
		if (this->_state != STATE_PAUSE) {
			this->_state = STATE_PAUSE;
			
			alSourcePause(this->_source);
		}
	}
	
	/**
	 * Stops playing its content of this audio entity.
	 */
	void AudioEntity::stop(void)
	{
		if (this->_state != STATE_STOP) {
			this->_state = STATE_STOP;
			
			alSourceStop(this->_source);
		}
	}
	
	/**
	 * Rewinds current play position to the beginning.
	 */
	void AudioEntity::rewind(void)
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
	void AudioEntity::setPosition(const float x, const float y, const float z)
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
	void AudioEntity::setDirection(const float x, const float y, const float z)
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
	void AudioEntity::setVelocity(const float x, const float y, const float z)
	{
		alSource3f(this->_source, AL_VELOCITY, x, y, z);
	}
	
	/**
	 * Assigns pitch value to this audio entity.
	 *
	 * @param pitch - new pitch value
	 */
	void AudioEntity::setPitch(const float pitch)
	{
		alSourcef(this->_source, AL_PITCH, pitch);
	}
	
	/**
	 * Assigns gain value to this audio entity.
	 *
	 * @param gain - new gain value
	 */
	void AudioEntity::setGain(const float gain)
	{
		alSourcef(this->_source, AL_GAIN, gain);
	}
	
	/**
	 * Releases all reserved memory.
	 */
	void AudioEntity::release(void)
	{
		alDeleteSources(1, &this->_source);
		alDeleteBuffers(1, &this->_buffer);
	}
}
