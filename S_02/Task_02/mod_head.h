#pragma once

#include <random>

namespace modified {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b)
{
    static std::mt19937 generator(std::random_device{}());
    static std::bernoulli_distribution add_number(0.5);
    static std::uniform_int_distribution<int> random_number(1, 100);

    double result = (static_cast<double>(a) + static_cast<double>(b)) / 2.0;
    if (add_number(generator)) {
        result += random_number(generator);
    }
    return static_cast<Result>(result);
}
}
