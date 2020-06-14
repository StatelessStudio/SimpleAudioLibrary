#pragma once

#include "BaseException.h"

namespace SimpleAudio
{

/**
 * No Device Exception Class.
 */
class NoContextException : public BaseException
{
public:

	/**
	 * NoContextException
	 *
	 * @param message Exception message
	 */
	NoContextException(const char* message) : BaseException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	NoContextException(const NoContextException &src) : BaseException(src)
	{
	}

	/**
	 * Teardown
	 */
	virtual ~NoContextException(void) throw()
	{
	}
};

} // namespace SimpleAudio
