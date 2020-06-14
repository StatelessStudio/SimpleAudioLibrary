#pragma once

#include "BaseMessageException.h"

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudio
{
	/**
	 * No Device Exception Class.
	 */
	class NoDeviceException : public BaseMessageException
	{
		public:
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			NoDeviceException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			NoDeviceException(const NoDeviceException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~NoDeviceException(void) throw()
			{
			}
	};
}
