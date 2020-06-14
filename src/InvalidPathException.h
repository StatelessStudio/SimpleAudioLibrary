#pragma once

#include "BaseException.h"

namespace SimpleAudio
{

/**
 * Invalid Path Exception
 */
class InvalidPathException : public BaseException
{
public:

	/**
	 * InvalidPathException
	 *
	 * @param message Exception message
	 */
	InvalidPathException(const char* message) : BaseException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	InvalidPathException(const InvalidPathException &src) : BaseException(src)
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
