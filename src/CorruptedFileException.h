#pragma once

#include "BaseException.h"

namespace SimpleAudio
{

/**
 * Corrupted File Exception
 */
class CorruptedFileException : public BaseException
{
public:

	/**
	 * CorruptedFileException
	 *
	 * @param message Exception message
	 */
	CorruptedFileException(const char* message) : BaseException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	CorruptedFileException(const CorruptedFileException &src) : BaseException(src)
	{
	}

	/**
	 * Teardown
	 */
	virtual ~CorruptedFileException(void) throw()
	{
	}
};

} // namespace SimpleAudio
