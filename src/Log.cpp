#include "Log.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>
#include <iostream>

Log m_globalLog;

Log* Log::instance()
{
	return &m_globalLog;
}

Log::Log()
: m_fd(-1)
{
}

Log::~Log()
{
	close(m_fd);
}

void Log::open(const std::string& path)
{
	m_fd = ::open(path.c_str(),S_IRUSR);
}

void Log::write(Type type, const char* text)
{
	std::cerr << "log " << text << std::endl;
	::write(m_fd,text,strlen(text));
}
