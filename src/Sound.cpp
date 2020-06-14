#include "Sound.h"

#include <fstream>

#ifdef _DEBUG
#include <iostream>
#endif

#include <AL/al.h>

namespace SimpleAudio
{

/**
 * Creates new instance of this class.
 */
Sound::Sound() :
	_buffer(0),
	name("")
{
#if _DEBUG
	std::cout << "[Sound][Noname] Initializing..." << std::endl;
#endif
}

/**
 * Creates new instance of this class.
 */
Sound::Sound(const char* n) :
	_buffer(0),
	name(n)
{
#if _DEBUG
	std::cout << "[Sound][" << name << "] Initializing..." << std::endl;
#endif
}

/**
 * Creates new instance by copying another instance of this class.
 */
Sound::Sound(const Sound &src) :
	_buffer(src._buffer)
{
}

/**
 * Releases this instance of this class.
 */
Sound::~Sound(void)
{
#if _DEBUG
	std::cout << "[Sound][" << name << "] Teardown..." << std::endl;
#endif
	alDeleteBuffers(1, &this->_buffer);
}

/**
 * Get the buffer ID
 */
unsigned int Sound::getBuffer()
{
	return _buffer;
}

/**
 * Creates this Sound's buffer from a .wav file
 */
void Sound::loadWaveFile(const std::string path) const throw(InvalidPathException, CorruptedFileException)
{	
	if (path.empty()) {
		throw InvalidPathException("Load wave file failure: no path to file defined!");
	}
	
	std::ifstream file(path.c_str(), std::ifstream::binary);
	
	if (!file.is_open()) {
		throw CorruptedFileException("Load wave file failure: file couldn't be opened!");
	} else {
		char chunkId[5] 	= "\0";
		unsigned int size 	= 0;
	
		// read header
		file.read(chunkId, 4);
		file.read((char*)&size, 4);
	
		chunkId[4] = '\0';
#ifdef _DEBUG		
		std::cout << "Chunk ID: " << chunkId << std::endl;
		std::cout << "Size: " << size << "bytes" << std::endl;
#endif		
		file.read(chunkId, 4);
	
		chunkId[4] = '\0';
#ifdef _DEBUG			
		std::cout << "Wave ID: " << chunkId << std::endl;
#endif		
		// read first chunk header
		file.read(chunkId, 4);
		file.read((char*)&size, 4);
	
		chunkId[4] = '\0';
#ifdef _DEBUG			
		std::cout << "Chunk ID: " << chunkId << std::endl;
		std::cout << "Size: " << size << "bytes" << std::endl;
#endif		
		// read first chunk content
		short formatTag 		= 0;
		short channels 			= 0;
		int samplesPerSec 		= 0;
		int averageBytesPerSec 	= 0;
		short blockAlign 		= 0;
		short bitsPerSample 	= 0;
	
		file.read((char*)&formatTag, 2);
		file.read((char*)&channels, 2);
		file.read((char*)&samplesPerSec, 4);
		file.read((char*)&averageBytesPerSec, 4);
		file.read((char*)&blockAlign, 2);
		file.read((char*)&bitsPerSample, 2);
		
		if (size > 16) {
			file.seekg((int)file.tellg() + (size - 16));
		}
		
#ifdef _DEBUG			
		switch (formatTag) {
			case 0x0001: {
				std::cout << "PCM Format" << std::endl;
			} break;
		
			case 0x0003: {
				std::cout << "IEEE Float Format" << std::endl;
			} break;
		
			case 0x0006: {
				std::cout << "8-bit ITU-T G.711 A-law Format" << std::endl;
			} break;
		
			case 0x0007: {
				std::cout << "8-bit ITU-T G.711 mi-law Format" << std::endl;
			} break;
		
			default: {
				std::cout << "Unknown format tag" << std::endl;
			} break;
		}

		std::cout << "Channels: " << channels << std::endl;
		std::cout << "Samples Per Second: " << samplesPerSec << std::endl;
		std::cout << "average bytes per second: " << averageBytesPerSec << std::endl;
		std::cout << "Block align: " << blockAlign << std::endl;
		std::cout << "bit per sample: " << bitsPerSample << std::endl;
#endif		
		// read data chunk header
		file.read(chunkId, 4);
		file.read((char*)&size, 4);
	
		chunkId[4] = '\0';
		
#ifdef _DEBUG			
		std::cout << "Chunk ID: " << chunkId << std::endl;
		std::cout << "Size: " << size << "bytes" << std::endl;
#endif		
		unsigned char* data = new unsigned char[size];
	
		file.read((char*)data, size);

		alGenBuffers(1, const_cast<ALuint*>(&this->_buffer));
		alBufferData(this->_buffer, (channels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data, size, samplesPerSec);

		delete[] data;
		data = NULL;
		
#ifdef _DEBUG
		std::cout << "--- Done\n" << std::endl;
#endif			
	}
	
	file.close();
}

} // namespace SimpleAudio
