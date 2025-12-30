#include "scoped_file.h"

ScopedFile::ScopedFile(const std::string& path, const std::string& mode)
	: file_(OpenFile(path, mode))
{
}

ScopedFile::~ScopedFile()
{
	if (file_)
	{
		std::fclose(file_);
	}
}

ScopedFile::ScopedFile(ScopedFile&& other) noexcept
	: file_(other.file_)
{
	other.file_ = nullptr;
}

ScopedFile& ScopedFile::operator=(ScopedFile&& other) noexcept
{
	if (this == &other)
		return *this;

	if (file_)
	{
		std::fclose(file_);
	}

	file_ = other.file_;
	other.file_ = nullptr;

	return *this;
}

bool ScopedFile::is_open() const
{
	return file_ != nullptr;
}

FILE* ScopedFile::get() const
{
	return file_;
}

FILE* ScopedFile::OpenFile(const std::string& path, const std::string& mode)
{
#if defined(_MSC_VER)
	FILE* file = nullptr;
	if (fopen_s(&file, path.c_str(), mode.c_str()) == 0)
		return file;

	return nullptr;
#else
	return std::fopen(path.c_str(), mode.c_str());
#endif
}
