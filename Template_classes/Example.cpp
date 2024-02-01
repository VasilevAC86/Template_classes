#include "Example.hpp"

float Example::Workload() const {
	float result{};
	for (int i = 0; i < a; ++i)
		result += b;
	return result;
}
