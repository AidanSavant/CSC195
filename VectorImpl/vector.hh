#ifndef _VEC_IMPL_H_
#define _VEC_IMPL_H_

#include <utility>
#include <concepts>
#include <algorithm>
#include <type_traits>

template<class T>
requires 
    std::copy_constructible<T>   && 
    std::is_copy_assignable_v<T> &&
    std::is_destructible_v<T>
class Vec {
public:
    using ValueType  = T;
    using ValuePtr   = T*;
    using SizeType   = std::size_t;

    // Default ctor
    Vec() :
        m_cap(0),
        m_len(0),
        m_data_buffer(nullptr)
    {}

    // Default ctor with initial size
    explicit Vec(SizeType size) :
        m_cap(size),
        m_len(size),
        m_data_buffer(new T[size])
    {
        std::fill(begin(), end(), T());
    }

    /* === Copy ctor & copy assignment === */
    Vec(const Vec& other) :
        m_cap(other.m_cap),
        m_len(other.m_len),
        m_data_buffer(new T[m_cap])
    {
        std::copy(other.begin(), other.end(), m_data_buffer);
    }

    Vec& operator=(const Vec& other) {
        if(this == other) {
            return *this;
        }

        ValuePtr new_data_buffer = new T[other.m_cap];
        std::copy(other.begin(), other.end(), new_data_buffer);
        delete[] m_data_buffer;

        m_cap = other.m_cap;
        m_len = other.m_len;             
        m_data_buffer = new_data_buffer;
    }

    /* === Move ctor & move assignment === */
    Vec(Vec&& other)
    noexcept(std::is_nothrow_move_constructible_v<decltype(m_data_buffer)>) :
        m_cap(std::exchange(other.m_cap, 0)),
        m_len(std::exchange(other.m_len, 0)),
        m_data_buffer(std::exchange(other.m_data_buffer, nullptr))
    {}

    ValuePtr begin() const { return m_data_buffer; }
    ValuePtr end()   const { return m_data_buffer + m_len; }

private:
    SizeType m_cap;
    SizeType m_len;
    ValuePtr m_data_buffer;
};

#endif

