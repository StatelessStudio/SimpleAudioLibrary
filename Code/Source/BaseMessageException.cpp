/**
 * Simple Audio Library - Base Message Exception Module.
 *
 * @author		Andy Liebke<coding@andysmiles4games.com>
 * @file		Source/BaseMessageException.cpp
 * @version 	1.0.0 04-Aug-13
 * @copyright	Copyright (c) 2013 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleAudioLib/BaseMessageException.h>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
{
	/**
	 * Creates new instance of this class.
	 *
	 * @param message - string including exception message
	 */
	BaseMessageException::BaseMessageException(const std::string message) : 
		std::exception(),
		_message(message)
	{
	}
	
	/**
	 * Creates new instance by copying another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 */
	BaseMessageException::BaseMessageException(const BaseMessageException &src) :
		_message(src._message)
	{
	}

	/**
	 * Releases this instance of this class.
	 */
	BaseMessageException::~BaseMessageException(void) throw()
	{
	}
	
	/**
	 * Assigns data by another instance of this class.
	 *
	 * @param src - reference to the other instance of this class
	 * @return reference to this instance of this class
	 */
	BaseMessageException& BaseMessageException::operator = (const BaseMessageException &src)
	{
		this->_message = src._message;
		
		return *this;
	}
	
	/**
	 * Returns exception message.
	 *
	 * @return string including exception message
	 */
	const char* BaseMessageException::what(void) const throw()
	{
		return this->_message.c_str();
	}
}