#pragma once

#include <AL/AL.h>
#include "CorruptedFileException.h"
#include "InvalidPathException.h"
namespace SimpleAudio
{

class Sound
{
private:
	/**
	 * Buffer ID
	 */
	unsigned int _buffer;

public:
	/**
	 * Sound name
	 */
	const char* name;

	/**
	 * Sound
	 */
	Sound();

	/**
	 * Sound w/ name
	 * 
	 * @param n Name of the sound
	 */
	Sound(const char *n);

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	Sound(const Sound &src);

	/**
	 * Teardown
	 */
	~Sound(void);

	/**
	 * Get the buffer ID
	 * 
	 * @return {unsigned int} Returns the buffer ID
	 */
	unsigned int getBuffer();

	/**
 	 * Create this Sound's buffer from a .wav file
	 *
	 * @param path Filepath to the wavefile
	 * @throws InvalidPathException 	- in case that given path parameter is empty
	 * @throws CorruptedFileException	- in case that the audio file couldn't be opened
	 */
	void loadWaveFile(const char* path) const throw(InvalidPathException, CorruptedFileException);
};

} // namespace SimpleAudio
