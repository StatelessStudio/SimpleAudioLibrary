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
	class NoContextException : public BaseMessageException
	{
		public:
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			NoContextException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			NoContextException(const NoContextException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~NoContextException(void) throw()
			{
			}
	};
}
