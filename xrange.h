#pragma once

template<typename Type = int> class xrange
{
private:
    Type m_start;
    Type m_end;
    Type m_step;

public:
    class iterator;
    class end_iterator;

    xrange(Type start, Type end, Type step = 1) : m_start(start), m_end(end), m_step(step) {}
    iterator begin()    { return iterator(m_start, m_step); }
    iterator end()      { return iterator(m_end, 0); }
    //end_iterator end() { return end_iterator(m_end); }
};

template<typename Type> class xrange<Type>::iterator
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

template<typename Type> class xrange<Type>::end_iterator
{
private:
    const Type& m_val;

public:
    explicit end_iterator(const Type& val) : m_val(val) {}
    friend bool operator!=(iterator& it, const end_iterator& end_it) { return *it != end_it.m_val; }
};