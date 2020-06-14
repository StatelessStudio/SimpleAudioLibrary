#pragma once

#include "BaseMessageException.h"

namespace SimpleAudio
{
	/**
	 * No Device Exception Class.
	 */
	class NoDeviceException : public BaseMessageException
	{
		public:

			/**
			 * NoDeviceException
			 *
			 * @param message Exception message
			 */
			NoDeviceException(const char* message) : BaseMessageException(message)
			{
			}

			/**
			 * Create new instance by copying another instance
			 *
			 * @param src Reference to the other instance
			 */
			NoDeviceException(const NoDeviceException &src) : BaseMessageException(src)
			{
			}

			/**
			 * Teardown
			 */
			virtual ~NoDeviceException(void) throw()
			{
			}
	};
}
