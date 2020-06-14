#pragma once

#include "BaseMessageException.h"

namespace SimpleAudio
{

/**
 * Invalid Path Exception
 */
class InvalidPathException : public BaseMessageException
{
public:

	/**
	 * InvalidPathException
	 *
	 * @param message Exception message
	 */
	InvalidPathException(const char* message) : BaseMessageException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	InvalidPathException(const InvalidPathException &src) : BaseMessageException(src)
	{
	}

	/**
	 * Teardown
	 */
	virtual ~InvalidPathException(void) throw()
	{
	}
};

} // namespace SimpleAudio
