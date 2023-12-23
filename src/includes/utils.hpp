

#ifndef UTILITY_H
#define UTILITY_H

#ifdef DEBUG

#include <iostream>
#include <chrono>

#define TIMER_START() auto start_time = std::chrono::high_resolution_clock::now();

#define TIMER_END(functionName) \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
    auto duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); \
    std::cout << "Time taken by " << functionName << ": " << duration_micro.count() << " microseconds, " \
              << duration_milli.count() << " milliseconds." << std::endl;

#else // DEBUG not defined

#define TIMER_START()

#define TIMER_END(functionName)

#endif // DEBUG


template <class DstType, class SrcType>
inline bool IsType(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}


#endif // UTILS_H