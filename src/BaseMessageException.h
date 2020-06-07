#ifndef __BASE_MESSAGE_EXCEPTION_H__
#define __BASE_MESSAGE_EXCEPTION_H__

#include <exception>
#include <string>

/**
 * Simple Audio Library Namespace.
 */
namespace SimpleAudioLib
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
			BaseMessageException(const std::string message);
			
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
			std::string _message;
	};
}

#endif
