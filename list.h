#ifndef __LJSRE_LIST__
#define __LJSRE_LIST__

template <typename T, typename Allocator>
class list
{
    class list_link
    {
        T elem_;
        list_link * next_;

        list_link ()
            : elem_ (elem_)
            , next_ (0)
        { }

        list_link (T e)
            : elem_ (e)
            , next_ (0)
        { }
/*
      public:
        list_link & operator ++ ()
        {
            this = next_;
            return * this;
        }

        T operator * (list_link & i)
        {
            return elem_;
        }
*/
        friend class list;
    };

    Allocator & allocator_;

  public:
    list_link * head_;
    list_link * tail_;

    typedef list_link * iterator;

    list (Allocator & a)
        : allocator_ (a)
        , head_      (static_cast<list_link *> (allocator_.allocate (sizeof (list_link))))
        , tail_      (head_)
    {
        new (head_) list_link ();
    }

    list (T e, Allocator & a)
        : allocator_ (a)
        , head_      (static_cast<list_link *> (allocator_.allocate (sizeof (list_link))))
        , tail_      (head_)
    {
        new (head_) list_link (e);
        add (e);
    }

    inline iterator head () const
    {
        return head_->next_;
    }

    inline iterator tail () const
    {
        return tail_->next_;
    }

    static inline void next (iterator & i)
    {
        i = i->next_;
    }

    static inline T & elem (iterator i)
    {
        return i->elem_;
    }

    inline void remove (iterator i)
    {
        i->next_ = i->next_->next_;
    }

    inline void add (T e)
    {
        tail_->next_ = static_cast<list_link *> (allocator_.allocate (sizeof (list_link)));
        new (tail_->next_) list_link (e);
        tail_ = tail_->next_;
    }

    inline void append (list * l)
    {
        tail_->next_ = l->head ();
        tail_ = l->tail_;
    }
};

#endif // __LJSRE_LIST__
