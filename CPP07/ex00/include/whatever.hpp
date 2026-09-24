#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// 1. SWAP template: swaps the values of two given parameters
template <typename T>
void swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}

// 2. MIN template: returns the smallest value (or 'b' if equal)
template <typename T>
const T & min(const T & a, const T & b) {
    if (a < b)
        return a;
    return b;
}

// 3. MAX template: returns the greatest value (or 'b' if equal)
template <typename T>
const T & max(const T & a, const T & b) {
    if (a > b)
        return a;
    return b;
}

#endif