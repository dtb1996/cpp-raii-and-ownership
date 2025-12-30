#pragma once

#include <chrono>
#include <string>

class ScopedTimer
{
public:
	explicit ScopedTimer(std::string label = "");
	~ScopedTimer();

	// Non-copyable
	ScopedTimer(const ScopedTimer&) = delete;
	ScopedTimer& operator=(const ScopedTimer&) = delete;

	// Movable
	ScopedTimer(ScopedTimer&& other) noexcept;
	ScopedTimer& operator=(ScopedTimer&& other) noexcept;

private:
	using Clock = std::chrono::high_resolution_clock;

	std::string label_;
	Clock::time_point startTime_;
	bool active_{ true };
};

