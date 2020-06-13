#pragma once

#include <AL/AL.h>
#include "CorruptedFileException.h"
#include "InvalidPathException.h"

#include <string>

namespace SimpleAudioLib
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
	 * Creates new instance of this class.
	 */
	Sound();
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	Sound(const Sound &src);
	
	/**
	 * Releases this instance of this class.
	 */
	virtual ~Sound(void);
	
	/**
	 * Releases memory of this instance.
	 *
	 * @note This is part of the Singleton-Pattern.
	 */
	void release(void);

	/**
	 * Get the buffer ID
	 * 
	 * @return {unsigned int} Returns the buffer ID
	 */
	unsigned int getBuffer();

	/**
 	 * Creates this Sound's buffer from a .wav file
	 *
	 * @param path - string including path to the audio file
	 * @throws InvalidPathException 	- in case that given path parameter is empty
	 * @throws CorruptedFileException	- in case that the audio file couldn't be opened
	 */
	void loadWaveFile(const std::string path) const throw(InvalidPathException, CorruptedFileException);
};

} // namespace SimpleAudioLib
