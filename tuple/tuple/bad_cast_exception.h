#pragma once

#include <string>
#include <exception>

namespace experimental {

	class bad_cast_exception : public std::exception {

	protected:

		std::string msg_;

	public:

		bad_cast_exception(const char*  message) {
			msg_ = message;
		}

		virtual const char* what() const {

			return msg_.c_str();

		}

		virtual ~bad_cast_exception() {}

	};


}
