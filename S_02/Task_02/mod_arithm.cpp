#include <random>

namespace modified {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b)
{
    static std::mt19937 generator(std::random_device{}());
    static std::bernoulli_distribution add_number(0.5);
    static std::uniform_int_distribution<int> random_number(1, 100);

    Result result = (static_cast<Result>(a) + static_cast<Result>(b)) /
                    static_cast<Result>(2);
    if (add_number(generator)) {
        result += static_cast<Result>(random_number(generator));
    }
    return result;
}
}
