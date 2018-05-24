#pragma once
#include <type_traits>


template<typename Type>
class Xrange
{
private:
    Type m_start;
    Type m_end;
    Type m_step;

    class begin_iterator;
    class end_iterator;

public:
	Xrange(Type start, Type end, Type step) : m_start(start), m_end(end), m_step(step)
	{
		static_assert(std::is_integral<Type>::value, "xrange can only be used with integral types");
	}

    begin_iterator begin()  { return begin_iterator(m_start, m_step); }
    end_iterator end()      { return end_iterator(m_end); }
};


template<typename Type>
class Xrange<Type>::begin_iterator
{
private:
    Type m_val;
    Type m_step;

public:
    begin_iterator(const Type& val, const Type& step) : m_val(val), m_step(step) {}
    begin_iterator operator++()                  { m_val += m_step; return *this; }
    bool operator!=(const end_iterator& other)   { return m_val != other.m_val; }
    Type operator*()                             { return m_val; }
};


template<typename Type>
class Xrange<Type>::end_iterator
{
private:
    Type m_val;

public:
    explicit end_iterator(const Type& val) : m_val(val) {}
    friend bool Xrange<Type>::begin_iterator::operator!=(const end_iterator& other);
};


template<typename Type = int>
Xrange<Type> xrange(Type start, Type end, Type step = 1)
{
    return Xrange<Type>(start, end, step);
}


template<typename Type = int>
Xrange<Type> xrange(Type end)
{
    return Xrange<Type>(0, end, 1);
}
