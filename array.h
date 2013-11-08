#ifndef __LJS_ARRAY__
#define __LJS_ARRAY__

template <typename T>
struct array
{
    const unsigned int SIZE;
    T * start;
    unsigned int index;

    array (unsigned int sz)
        : SIZE  (sz)
        , start (static_cast<T *> (operator new (SIZE * sizeof (T))))
        , index (0)
    { }

    ~array ()
    {
        operator delete (start);
    }

    inline void clear ()
    {
        index = 0;
    }

  private:
    array (const array &);              /* forbid copy */
    array & operator = (const array &); /* forbid copy */
};

#endif // __LJS_ARRAY__

