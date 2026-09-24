namespace original {
template <typename Result, typename First, typename Second>
Result average(const First& a, const Second& b)
{
    return (static_cast<Result>(a) + static_cast<Result>(b)) / static_cast<Result>(2);
}
}

namespace by_reference {
template <typename T>
T average(T& a, const T& b)
{
    a = (a + b) / static_cast<T>(2);
    return a;
}
}
