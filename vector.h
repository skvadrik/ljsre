#ifndef __LJS_VECTOR__
#define __LJS_VECTOR__

#include <string.h> // memcpy

// use vector only with POD-types
// beware vector performs shallow copy via memcpy
template<typename T, typename Allocator>
class vector
{
    Allocator & allocator_;
    T * start_;
    unsigned int size_max_;
    unsigned int size_;

  public:
    vector (Allocator & allocator)
        : allocator_ (allocator)
        , start_     (static_cast<T *> (allocator_.allocate (sizeof (T))))
        , size_max_  (1)
        , size_      (0)
    { }

    vector (Allocator & allocator, unsigned int sz)
        : allocator_ (allocator)
        , start_     (static_cast<T *> (allocator_.allocate (sizeof (T) * sz)))
        , size_max_  (sz)
        , size_      (sz)
    { }

    explicit vector (const vector & o)
        : allocator_ (o.allocator_)
        , start_     (static_cast<T *> (allocator_.allocate (o.size_max_ * sizeof (T))))
        , size_max_  (o.size_max_)
        , size_      (o.size_)
    {
        memcpy (start_, o.start_, size_ * sizeof (T));
    }

    inline unsigned int size () const
    {
        return size_;
    }

    inline T& operator [] (unsigned int i) const
    {
        return start_[i];
    }

    inline void push_back (T e)
    {
        if (size_ >= size_max_)
        {
            const unsigned int sz = size_max_ * sizeof (T);
            T * old_start = start_;
            start_ = static_cast<T *> (allocator_.allocate (sz << 1));
            memcpy (start_, old_start, sz);
            size_max_ <<= 1;
        }
        start_[size_++] = e;
    }

  private:
    vector & operator = (const vector &);
};

#endif // __LJS_VECTOR__
