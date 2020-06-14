#pragma once

namespace SimpleAudio
{

/**
 * Source States
 */
enum SourceState
{
	/**
	 * Source is stopped
	 */
	STOP = 0,
	
	/**
	 * Source is starting
	 * @note The source may continue to play after the play state is reverted,
	 * 	depending on the length of the sound
	 */
	PLAY = 1,
	
	/**
	 * Source is paused
	 */
	PAUSE = 2
};

} // namespace SimpleAudio
