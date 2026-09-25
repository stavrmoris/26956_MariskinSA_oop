#pragma once

#include "config.h"
#include "../../S_02/Task_02/mod_head.h"

#include <array>
#include <deque>
#include <list>
#include <limits>
#include <random>
#include <type_traits>
#include <vector>

namespace task_04 {
using task_04_config::M;
using task_04_config::N;
using task_04_config::T1;
using task_04_config::T2;

static_assert(M > 0, "M must be greater than zero");
static_assert(N >= 0, "N must not be negative");
static_assert(std::is_arithmetic_v<T1>, "T1 must be a numeric type");
static_assert(std::is_arithmetic_v<T2>, "T2 must be a numeric type");
static_assert(std::is_signed_v<T1>, "T1 must represent values below zero");
static_assert(!std::is_same_v<T1, T2>, "T1 and T2 must be different types");

using Inputs = std::array<T1, M>;
using ArrayResults = std::array<T2, M>;
using VectorResults = std::vector<T2>;
using ListResults = std::list<T2>;
using DequeResults = std::deque<T2>;

template <typename Value>
Value random_value(std::mt19937& engine)
{
    if constexpr (std::is_integral_v<Value>) {
        static_assert(N <= std::numeric_limits<Value>::max(), "N exceeds the range of T1");
        std::uniform_int_distribution<long long> distribution(-N, N);
        return static_cast<Value>(distribution(engine));
    } else {
        std::uniform_real_distribution<Value> distribution(
            static_cast<Value>(-N), static_cast<Value>(N));
        return distribution(engine);
    }
}

inline Inputs make_array(std::mt19937& engine)
{
    Inputs values{};
    // Classical for with an index.
    for (std::size_t i = 0; i < M; ++i) {
        values[i] = random_value<T1>(engine);
    }
    return values;
}

inline std::vector<T1> make_vector(std::mt19937& engine)
{
    std::vector<T1> values(M);
    // Iterator-based for.
    for (auto it = values.begin(); it != values.end(); ++it) {
        *it = random_value<T1>(engine);
    }
    return values;
}

inline std::list<T1> make_list(std::mt19937& engine)
{
    std::list<T1> values(M);
    // Range-based for.
    for (auto& value : values) {
        value = random_value<T1>(engine);
    }
    return values;
}

inline std::deque<T1> make_deque(std::mt19937& engine)
{
    std::deque<T1> values(M);
    for (auto& value : values) {
        value = random_value<T1>(engine);
    }
    return values;
}

T2 apply_average(const T1& value, const T1& shared_argument)
{
    return modified::average<T2>(value, shared_argument);
}

inline VectorResults array_to_vector(const Inputs& source, const T1& shared_argument)
{
    VectorResults result;
    result.reserve(M);
    for (std::size_t i = 0; i < M; ++i) {
        result.push_back(apply_average(source[i], shared_argument));
    }
    return result;
}

inline ListResults vector_to_list(const std::vector<T1>& source, const T1& shared_argument)
{
    ListResults result;
    for (auto it = source.begin(); it != source.end(); ++it) {
        result.push_back(apply_average(*it, shared_argument));
    }
    return result;
}

inline DequeResults list_to_deque(const std::list<T1>& source, const T1& shared_argument)
{
    DequeResults result;
    for (const auto& value : source) {
        result.push_back(apply_average(value, shared_argument));
    }
    return result;
}

inline ArrayResults deque_to_array(const std::deque<T1>& source, const T1& shared_argument)
{
    ArrayResults result{};
    std::size_t index = 0;
    for (const auto& value : source) {
        result[index++] = apply_average(value, shared_argument);
    }
    return result;
}
} // namespace task_04
