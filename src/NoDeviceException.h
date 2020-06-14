#pragma once

#include "BaseException.h"

namespace SimpleAudio
{

/**
 * No Device Exception Class.
 */
class NoDeviceException : public BaseException
{
public:

	/**
	 * NoDeviceException
	 *
	 * @param message Exception message
	 */
	NoDeviceException(const char* message) : BaseException(message)
	{
	}

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	NoDeviceException(const NoDeviceException &src) : BaseException(src)
	{
	}

	/**
	 * Teardown
	 */
	virtual ~NoDeviceException(void) throw()
	{
	}
};

} // namespace SimpleAudio
