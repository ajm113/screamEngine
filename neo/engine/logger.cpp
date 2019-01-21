#include "logger.hpp"


void scream::Logger::Debug(const std::string &  msg) {
	PrintToScreen(scream::LogLevel::DEBUG, msg);
}

void scream::Logger::Message(const std::string &  msg) {
	PrintToScreen(scream::LogLevel::MESSAGE, msg);
}

void scream::Logger::Warning(const std::string &  msg) {
	PrintToScreen(scream::LogLevel::WARNING, msg);
}

void scream::Logger::Error(const std::string &  msg) {
	PrintToScreen(scream::LogLevel::ERROR, msg);
}


void scream::Logger::PrintToScreen(scream::LogLevel l, const std::string & msg) {
	switch(l) {
		case scream::LogLevel::DEBUG:
		case scream::LogLevel::MESSAGE:
			std::cout << "[" << LogLevelToString(l) << "] " << msg << std::endl;
			break;
		case scream::LogLevel::WARNING:
		case scream::LogLevel::ERROR:
		default:
			std::cerr << "[" << LogLevelToString(l) << "] " << msg << std::endl;
			break;
	}
}

std::string scream::Logger::LogLevelToString(scream::LogLevel l) {
	switch(l) {
		case scream::LogLevel::DEBUG:
			return std::string("DEBUG");
		case scream::LogLevel::MESSAGE:
			return std::string("MESSAGE");
		case scream::LogLevel::WARNING:
			return std::string("WARNING");
		case scream::LogLevel::ERROR:
			return std::string("ERROR");
		default:
			return std::string("UNKOWN");
	}
}
