/**
 * Simple Audio Library - No Device Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Header/SimpleAudioLib/NoDeviceException.h
 * @version 	1.0.0 27-Jul-13
 * @version		1.1.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __NO_DEVICE_EXCEPTION_H__
#define __NO_DEVICE_EXCEPTION_H__

#include <SimpleAudioLib/BaseMessageException.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
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

#endif