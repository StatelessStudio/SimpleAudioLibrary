#pragma once

#include <exception>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudio
{
	/**
	 * Base Message Exception Class.
	 */
	class BaseMessageException : public std::exception
	{
		public:
			
			/**
			 * Creates new instance of this class.
			 *
			 * @param message - string including exception message
			 */
			BaseMessageException(const char* message);
			
			/**
			 * Creates new instance by copying another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 */
			BaseMessageException(const BaseMessageException &src);
			
			/**
			 * Releases this instance of this class.
			 */
			virtual ~BaseMessageException(void) throw();
			
			/**
			 * Assigns data by another instance of this class.
			 *
			 * @param src - reference to the other instance of this class
			 * @return reference to this instance of this class
			 */
			BaseMessageException& operator = (const BaseMessageException &src);
			
			/**
			 * Returns exception message.
			 *
			 * @return string including exception message
			 */
			virtual const char* what(void) const throw();
			
		private:
		
			/**
			 * Stores exception message.
			 */
			const char* _message;
	};
}
