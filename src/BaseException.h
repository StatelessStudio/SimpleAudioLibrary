#pragma once

#include <exception>

namespace SimpleAudio
{

/**
 * Base Exception
 */
class BaseException : public std::exception
{
public:

	/**
	 * BaseException
	 *
	 * @param message Exception message
	 */
	BaseException(const char* message);

	/**
	 * Create new instance by copying another instance
	 *
	 * @param src Reference to the other instance
	 */
	BaseException(const BaseException &src);

	/**
	 * Teardown
	 */
	virtual ~BaseException(void) throw();

	/**
	 * Assign data from another instance
	 *
	 * @param src Reference to the other instance
	 * @return Reference to this instance
	 */
	BaseException& operator = (const BaseException &src);

	/**
	 * Get the exception message
	 *
	 * @return Returns exception message
	 */
	virtual const char* what(void) const throw();

private:

	/**
	 * Exception message
	 */
	const char* _message;
};

} // namespace SimpleAudio
