#pragma once

#include <exception>

namespace SimpleAudio
{
	/**
	 * Base Exception
	 */
	class BaseMessageException : public std::exception
	{
		public:
			
			/**
			 * BaseMessageException
			 *
			 * @param message Exception message
			 */
			BaseMessageException(const char* message);
			
			/**
			 * Create new instance by copying another instance
			 *
			 * @param src Reference to the other instance
			 */
			BaseMessageException(const BaseMessageException &src);
			
			/**
			 * Teardown
			 */
			virtual ~BaseMessageException(void) throw();
			
			/**
			 * Assign data from another instance
			 *
			 * @param src Reference to the other instance
			 * @return Reference to this instance
			 */
			BaseMessageException& operator = (const BaseMessageException &src);
			
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
}
