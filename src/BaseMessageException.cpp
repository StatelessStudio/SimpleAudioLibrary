#include "BaseMessageException.h"

namespace SimpleAudio
{
	BaseMessageException::BaseMessageException(const char* message) : 
		std::exception(),
		_message(message)
	{
	}

	BaseMessageException::BaseMessageException(const BaseMessageException &src) :
		_message(src._message)
	{
	}

	BaseMessageException::~BaseMessageException(void) throw()
	{
	}

	BaseMessageException& BaseMessageException::operator = (const BaseMessageException &src)
	{
		this->_message = src._message;

		return *this;
	}

	const char* BaseMessageException::what(void) const throw()
	{
		return this->_message;
	}
}
