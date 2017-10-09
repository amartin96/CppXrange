#pragma once

template<typename Type = int> class Xrange
{
private:
    Type m_start;
    Type m_end;
    Type m_step;

public:
    class iterator;
    class end_iterator;

    Xrange(Type start, Type end, Type step) : m_start(start), m_end(end), m_step(step) {}
    iterator begin()    { return iterator(m_start, m_step); }
    iterator end()      { return iterator(m_end, 0); }
};

template<typename Type> class Xrange<Type>::iterator
{
private:
    Type m_val;
    Type m_step;

public:
    iterator(const Type& val, const Type& step) : m_val(val), m_step(step) {}
    iterator operator++()                   { m_val += m_step; return *this; }
    bool operator!=(const iterator& other)  { return m_val != other.m_val; }
    Type operator*()                        { return m_val; }
};

template<typename Type = int> Xrange<Type> xrange(Type start, Type end, Type step = 1)
{
    return Xrange<Type>(start, end, step);
}

template<typename Type = int> Xrange<Type> xrange(Type end)
{
    return Xrange<Type>(0, end, 1);
}