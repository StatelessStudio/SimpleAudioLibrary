/**
 * Simple Audio Library - No Context Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Header/SimpleAudioLib/NoContextException.h
 * @version 	1.0.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __NO_CONTEXT_EXCEPTION_H__
#define __NO_CONTEXT_EXCEPTION_H__

#include <SimpleAudioLib/BaseMessageException.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
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

#endif