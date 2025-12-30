#include "scoped_timer.h"

#include <iostream>

ScopedTimer::ScopedTimer(std::string label)
	: label_(std::move(label))
	, startTime_(Clock::now())
{

}

ScopedTimer::~ScopedTimer()
{
	if (!active_)
		return;

	const auto endTime = Clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime_).count();

	if (!label_.empty())
	{
		std::cout << label_ << ": ";
	}

	std::cout << duration << " ms\n";
}

ScopedTimer::ScopedTimer(ScopedTimer&& other) noexcept
	: label_(std::move(other.label_))
	, startTime_(other.startTime_)
	, active_(other.active_)
{
	other.active_ = false;
}

ScopedTimer& ScopedTimer::operator=(ScopedTimer&& other) noexcept
{
	if (this == &other)
		return *this;

	// Finish current timer if active
	if (active_)
	{
		this->~ScopedTimer();
	}

	label_ = std::move(other.label_);
	startTime_ = other.startTime_;
	active_ = other.active_;

	other.active_ = false;

	return *this;
}
