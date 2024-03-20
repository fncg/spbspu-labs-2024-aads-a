#ifndef CONST_LIST_ITERATOR_HPP
#define CONST_LIST_ITERATOR_HPP

#include <iterator>
#include "node.hpp"

namespace nikitov
{
  template< class T >
  class List;

  template< class T >
  class Node;

  template< class T >
  class ConstListIterator: public std::iterator< std::bidirectional_iterator_tag, T >
  {
    friend class List< T >;
  private:
    explicit ConstListIterator(detail::Node< T >* node);

  public:
    ConstListIterator(const ConstListIterator< T >&) = default;
    ~ConstListIterator() = default;

    ConstListIterator< T >& operator=(const ConstListIterator< T >&) = default;

    ConstListIterator< T >& operator++();
    ConstListIterator< T > operator++(int);
    ConstListIterator< T >& operator--();
    ConstListIterator< T > operator--(int);

    const T& operator*() const;
    const T* operator->() const;

    bool operator==(const ConstListIterator< T >& other) const;
    bool operator!=(const ConstListIterator< T >& other) const;

  private:
    detail::Node< T >* node_;
  };

  template< class T >
  ConstListIterator< T >::ConstListIterator(detail::Node< T >* node):
    node_(node)
  {}

  template< class T >
  ConstListIterator< T >& ConstListIterator< T >::operator++()
  {
    node_ = node_->next_;
    return *this;
  }

  template< class T >
  ConstListIterator< T > ConstListIterator< T >::operator++(int)
  {
    ConstListIterator< T > temp(*this);
    node_ = node_->next_;
    return temp;
  }

  template< class T >
  ConstListIterator< T >& ConstListIterator< T >::operator--()
  {
    node_ = node_->prev_;
    return *this;
  }

  template< class T >
  ConstListIterator< T > ConstListIterator< T >::operator--(int)
  {
    ConstListIterator< T > temp(*this);
    node_ = node_->prev_;
    return temp;
  }

  template< class T >
  const T& ConstListIterator< T >::operator*() const
  {
    return node_->value_;
  }

  template< class T >
  const T* ConstListIterator< T >::operator->() const
  {
    return std::addressof(node_->value_);
  }

  template< class T >
  bool ConstListIterator< T >::operator==(const ConstListIterator< T >& other) const
  {
    return node_ == other.node_;
  }

  template< class T >
  bool ConstListIterator< T >::operator!=(const ConstListIterator< T >& other) const
  {
    return node_ != other.node_;
  }
}
#endif
