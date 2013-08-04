/**
 * Simple Audio Library - Invalid Path Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Header/SimpleAudioLib/InvalidPathException.h
 * @version 	1.0.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __INVALID_PATH_EXCEPTION_H__
#define __INVALID_PATH_EXCEPTION_H__

#include <SimpleAudioLib/BaseMessageException.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * No Device Exception Class.
	 */
	class InvalidPathException : public BaseMessageException
	{
		public:
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			InvalidPathException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			InvalidPathException(const InvalidPathException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~InvalidPathException(void) throw()
			{
			}
	};
}

#endif