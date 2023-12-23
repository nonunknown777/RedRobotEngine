

#ifndef UTILITY_H
#define UTILITY_H

#ifdef DEBUG

#include <iostream>
#include <chrono>
#include "raylib.h"
#define TIMER_START() auto start_time = std::chrono::high_resolution_clock::now();

#define TIMER_END(functionName) \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
    auto duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); \
    std::string output = "MICROSECS: " + std::to_string(duration_micro.count()); \
    DrawText(output.c_str(),720,700,16,BLACK );

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