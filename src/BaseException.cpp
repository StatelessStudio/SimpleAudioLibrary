#include "BaseException.h"

namespace SimpleAudio
{

BaseException::BaseException(const char* message) : 
	std::exception(),
	_message(message)
{
}

BaseException::BaseException(const BaseException &src) :
	_message(src._message)
{
}

BaseException::~BaseException(void) throw()
{
}

BaseException& BaseException::operator = (const BaseException &src)
{
	this->_message = src._message;

	return *this;
}

const char* BaseException::what(void) const throw()
{
	return this->_message;
}

} // namespace SimpleAudio
