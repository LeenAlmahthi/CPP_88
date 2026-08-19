#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
template <typename T>
class Array
{
    private:
        T*              _array;
        unsigned int    _size;

    public:
    Array()
    {
        _array = NULL;
        _size = 0;
    }

    Array(unsigned int i)
    {
        _size = i;
        _array = NULL;

        if (i > 0)
            _array = new T[i]();
    }

    Array(const Array& tmp)
    {
        _size = 0;
        _array = NULL;
        *this = tmp;
        // _size = tmp._size;
        // _array = NULL;

        // if (_size > 0)
        // {
        //     _array = new T[_size];

        //     for (unsigned int i = 0; i < _size; i++)
        //         _array[i] = tmp._array[i];
        // }
    }

    ~Array()
    {
        delete[] _array;
    }

    Array& operator=(const Array& tmp)
    {
        if (this != &tmp)
        {
            delete[] _array;

            _size = tmp._size;
            _array = NULL;

            if (_size > 0)
            {
                _array = new T[_size];

                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = tmp._array[i];
            }
        }

        return *this;
    }

    T& operator[](unsigned int i)
    {
        if (i >= _size)
            throw std::exception();

        return _array[i];
    }

    const T& operator[](unsigned int i) const
    {
        if (i >= _size)
            throw std::exception();

        return _array[i];
    }

    unsigned int size() const
    {
        return _size;
    }
};

#endif