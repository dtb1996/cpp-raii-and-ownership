#pragma once

#include <cstdio>
#include <string>

class ScopedFile
{
public:
	ScopedFile(const std::string& path, const std::string& mode);
	~ScopedFile();

	// Non-copyable
	ScopedFile(const ScopedFile&) = delete;
	ScopedFile& operator=(const ScopedFile&) = delete;

	// Movable
	ScopedFile(ScopedFile&& other) noexcept;
	ScopedFile& operator=(ScopedFile&& other) noexcept;

	// Utility functions
	bool is_open() const;
	FILE* get() const;

private:
	FILE* file_{ nullptr };

	static FILE* OpenFile(const std::string& path, const std::string& mode);
};

