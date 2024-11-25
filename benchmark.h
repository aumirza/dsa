#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <chrono>
#include <utility>

template <typename Func, typename... Args>
auto benchmark(Func f, Args &&...args)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto result = f(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_taken = end - start;
    std::cout << "Time taken: " << time_taken.count() << " milliseconds" << std::endl;
    return result;
}

#endif
