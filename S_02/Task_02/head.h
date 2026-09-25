#pragma once

namespace original {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b)
{
    const double mean = (static_cast<double>(a) + static_cast<double>(b)) / 2.0;
    return static_cast<Result>(mean);
}
}

namespace by_reference {
template <typename T>
T average(T& a, const T& b)
{
    a = static_cast<T>((static_cast<double>(a) + static_cast<double>(b)) / 2.0);
    return a;
}
}
