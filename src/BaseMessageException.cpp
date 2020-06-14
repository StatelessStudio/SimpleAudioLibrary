#include "BaseMessageException.h"

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudio
{
	/**
	 * Creates new instance of this class.
	 *
	 * @param message - string including exception message
	 */
	BaseMessageException::BaseMessageException(const char* message) : 
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
	 * @return BaseMessageException - reference to this instance of this class
	 */
	BaseMessageException& BaseMessageException::operator = (const BaseMessageException &src)
	{
		this->_message = src._message;
		
		return *this;
	}
	
	/**
	 * Returns exception message.
	 *
	 * @return string - exception message
	 */
	const char* BaseMessageException::what(void) const throw()
	{
		return this->_message;
	}
}
