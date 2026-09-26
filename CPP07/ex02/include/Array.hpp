#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstddef>

template <typename T>
class Array {
private:
    T*              _elements;
    unsigned int    _size;

public:
    // 1. Default constructor: creates an empty array
    Array() : _elements(NULL), _size(0) {}

    // 2. Constructor with size: creates an array of n default-initialized elements
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

    // 3. Copy constructor: deep copy
    Array(const Array& other) : _elements(NULL), _size(0) {
        *this = other;
    }

    // 4. Assignment operator: deep copy
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _elements;
            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size]();
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }

    // 5. Destructor: frees allocated memory
    ~Array() {
        delete[] _elements;
    }

    // 6. Subscript operator for non-const objects
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }

    // 7. Subscript operator for const objects
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }

    // 8. Member function size()
    unsigned int size() const {
        return _size;
    }

    // Custom Exception for out-of-bounds access
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#endif