#pragma once

namespace modified {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b);
}

// Template definitions must be visible at the call site.
#include "mod_arithm.cpp"
