#pragma once

#include <type_traits>
#include <functional>
#include <iostream>

namespace rre {



#ifdef DEBUG


#define TIMER_START() auto start_time = std::chrono::high_resolution_clock::now();
#define TIMER_START_CONTINUE() start_time = std::chrono::high_resolution_clock::now();

#define TIMER_END(functionName) \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
    auto duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); \
    std::string output = functionName + std::to_string(duration_micro.count()); \
    DrawText(output.c_str(),720,700,16,BLACK );

#define TIMER_END_PRINT(functionName) \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
    auto duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); \
    std::string output = "MICROSECS: " + std::to_string(duration_micro.count()); \
    std::cout << functionName << " " << output << "\n";

#define TIMER_END_PRINT_CONTINUE(functionName) \
    end_time = std::chrono::high_resolution_clock::now(); \
    duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
    duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); \
    output = "MICROSECS: " + std::to_string(duration_micro.count()); \
    std::cout << functionName << " " << output << "\n";

#else // DEBUG not defined

#define TIMER_START()

#define TIMER_END(functionName)

#endif // DEBUG


// template <class DstType, class SrcType>
// inline bool IsType(const SrcType* src)
// {
//   return dynamic_cast<const DstType*>(src) != nullptr;
// }

//Check if class A is derived from B
// template<class Base, class Derived>
// using extends_from = std::is_base_of<Base,Derived>::value;

// template<class C>
// inline bool extends_from(Node* node) {
//     return dynamic_cast<C*>(node) != nullptr;
// }

}

template<class C, typename T>
struct FuncPtr {
    C& instance;
    void (C::*function)(T) = nullptr;

    FuncPtr(C& obj, void (C::*func)(T)) : instance(obj), function(func) {
    }

    // Call the stored member function with a provided argument
    void call(T arg) {
        if (function) {
            (instance.*function)(arg);
        } else {
            throw std::runtime_error("Error: Function pointer is nullptr.\n\n");
        }
    }
};

#include "raylib.h"
#include "glm/vec2.hpp"

inline Vector2 Vec2(glm::vec2& vec) {
    return Vector2(vec.x,vec.y);
}

// FuncPtr<Class>(ClassInstance,)