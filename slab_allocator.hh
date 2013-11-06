#ifndef __LIBVBA_SLAB_ALLOCATOR_HH__
#define __LIBVBA_SLAB_ALLOCATOR_HH__
/*
 * Works nice for tiny POD objects (~30 bytes and lower)
 * WARNING: Does not free memory for distinct objects!
 *
 * Works ~20 times faster, than linux's glibc allocator :]
 */

#include <algorithm> // std::for_each
#include <vector> // slab queue

#include "static_check.h"

template < unsigned int MAXIMUM_INLINE = 4 * 1024
         , unsigned int SLAB_SIZE = 1024 * 1024
         >
class slab_allocator
{
    std::vector<char *> slabs_; /* quasilist of allocated slabs of 'SLAB_SIZE' bytes */
    char *              current_slab_p_;
    char *              current_slab_end_;
    slab_allocator(const slab_allocator &);             /* forbid copy */
    slab_allocator & operator=(const slab_allocator &); /* forbid copy */

  public:
    slab_allocator ()
        : slabs_ ()
        , current_slab_p_ (0)
        , current_slab_end_ (0)
    {
        STATIC_CHECK ((MAXIMUM_INLINE <= SLAB_SIZE) || (MAXIMUM_INLINE == 0), maximum_inline_greater_than_slab_size);
    }

    virtual ~slab_allocator ()
    {
        std::for_each (slabs_.rbegin(), slabs_.rend(), static_cast<void (*) (void *)> (&(::operator delete)));
    }

    void clear ()
    {
        std::for_each (slabs_.rbegin(), slabs_.rend(), static_cast<void (*) (void *)> (&(::operator delete)));
        slabs_.clear ();
        current_slab_p_ = 0;
        current_slab_end_ = 0;
    }

    void * allocate (size_t size)
    {
        void * result;

        if (MAXIMUM_INLINE != 0)
        {
            if (size > MAXIMUM_INLINE) /* very large objects */
            {
                result = operator new (size);
                slabs_.push_back ((char *) result);
                return result;
            }
        }

        const size_t yet_in_slab = current_slab_end_ - current_slab_p_;
        if (yet_in_slab < size) /* no space in slab */
        {
            char * new_slab   = (char *) operator new (SLAB_SIZE);
            current_slab_p_   = new_slab;
            current_slab_end_ = new_slab + SLAB_SIZE;
            slabs_.push_back (new_slab);
        }
        result = current_slab_p_;
        current_slab_p_ += size;

        return result;
    }

    template <typename T>
    inline T * allocate_type ()
    {
        return static_cast<T *> (allocate (sizeof (T)));
    }

    template <typename T>
    inline T * allocate_type_array (unsigned int count)
    {
        return static_cast<T *> (allocate (sizeof (T) * count));
    }
};

// Setting first template param (MAXIMUM_INLINE) to 0 is used in allocate method
// to reduce check if chunk is larger than MAX_INLINE
// (cause all AST nodes are small)
typedef slab_allocator <0, 1024 * 1024> ast_allocator;

typedef slab_allocator <> array_allocator;

#endif // __LIBVBA_SLAB_ALLOCATOR_HH__
