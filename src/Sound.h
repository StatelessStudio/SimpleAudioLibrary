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
	 * Stores current buffer id of this entity.
	 */
	unsigned int _buffer;

public:
	/**
	 * Sound name
	 */
	const char* name;

	/**
	 * Creates new instance of this class.
	 */
	Sound();

	/**
	 * Creates new named instance of this class.
	 * 
	 * @param n Name of the sound
	 */
	Sound(const char *n);
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	Sound(const Sound &src);
	
	/**
	 * Releases this instance of this class.
	 */
	~Sound(void);

	/**
	 * Get the buffer ID
	 * 
	 * @return {unsigned int} Returns the buffer ID
	 */
	unsigned int getBuffer();

	/**
 	 * Creates this Sound's buffer from a .wav file
	 *
	 * @param path - including path to the audio file
	 * @throws InvalidPathException 	- in case that given path parameter is empty
	 * @throws CorruptedFileException	- in case that the audio file couldn't be opened
	 */
	void loadWaveFile(const char* path) const throw(InvalidPathException, CorruptedFileException);
};

} // namespace SimpleAudio
