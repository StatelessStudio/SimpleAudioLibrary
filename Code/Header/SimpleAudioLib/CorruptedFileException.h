/**
 * Simple Audio Library - Corrupted File Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Header/SimpleAudioLib/CorruptedFileException.h
 * @version 	1.0.0 02-Aug-13
 * @version		1.1.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __CORRUPTED_FILE_EXCEPTION_H__
#define __CORRUPTED_FILE_EXCEPTION_H__

#include <SimpleAudioLib/BaseMessageException.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Corrupted File Exception Class.
	 */
	class CorruptedFileException : public BaseMessageException
	{
		public:
		
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			CorruptedFileException(const std::string message) : BaseMessageException(message)
			{
			}
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			CorruptedFileException(const CorruptedFileException &src) : BaseMessageException(src)
			{
			}
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~CorruptedFileException(void) throw()
			{
			}
	};
}

#endif