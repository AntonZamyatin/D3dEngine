#pragma once
#include <chrono>

class EngTimer
{
public:
	EngTimer() noexcept;
	float Mark() noexcept;
	float Peek() const noexcept;
private:
	std::chrono::steady_clock::time_point last;
};