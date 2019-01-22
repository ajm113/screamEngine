#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>

namespace scream {

	enum LogLevel { DEBUG, MESSAGE, WARNING, ERROR };

	class Logger {
		public:
			void Debug(const std::string & msg);
			void Message(const std::string & msg);
			void Warning(const std::string & msg);
			void Error(const std::string & msg);

		protected:
			void PrintToScreen(LogLevel l, const std::string & msg);
			std::string LogLevelToString(LogLevel l);
	};
}

#endif
