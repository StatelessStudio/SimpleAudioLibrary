#pragma once

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{

/**
 * Audio Entity State List.
 */
enum SourceState
{
	/**
	 * Audio entity stops playing.
	 */
	STOP = 0,
	
	/**
	 * Audio entity plays its audio data.
	 */
	PLAY = 1,
	
	/**
	 * Audio entity pauses playing its audio data.
	 */
	PAUSE = 2,
	
	/**
	 * Audio entity rewinds current play postion to the beginning.
	 */
	REWIND = 3
};

} // namespace SimpleAudioLib
