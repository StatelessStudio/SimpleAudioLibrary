#pragma once

#include "BaseMessageException.h"

namespace SimpleAudio
{

/**
 * No Device Exception Class.
 */
class NoContextException : public BaseMessageException
{
public:

	/**
	 * NoContextException
	 *
	 * @param message Exception message
	 */
	NoContextException(const char* message) : BaseMessageException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	NoContextException(const NoContextException &src) : BaseMessageException(src)
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
