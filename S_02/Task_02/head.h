#pragma once

namespace original {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b);
}

namespace by_reference {
template <typename T>
T average(T& a, const T& b);
}

// Template definitions must be visible at the call site.
#include "arithm.cpp"
