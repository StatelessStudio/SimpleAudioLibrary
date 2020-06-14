#pragma once

#include "BaseMessageException.h"

namespace SimpleAudio
{

/**
 * Corrupted File Exception
 */
class CorruptedFileException : public BaseMessageException
{
public:

	/**
	 * CorruptedFileException
	 *
	 * @param message Exception message
	 */
	CorruptedFileException(const char* message) : BaseMessageException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	CorruptedFileException(const CorruptedFileException &src) : BaseMessageException(src)
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
