#ifndef CPP2_S21_CONTAINERS_1_QUEUE_H
#define CPP2_S21_CONTAINERS_1_QUEUE_H

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class queue {
 public:
  class Node;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class Node {
   public:
    Node *prev;
    Node *next;
    value_type value;
    Node();
    explicit Node(value_type value);
  };

  // constructors
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  // destructor
  ~queue();
  // overload operator
  queue &operator=(queue &&q);

  // queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty();
  size_type size();

  // public methods
  void push(const_reference value);
  void pop();
  void swap(queue &other);

 private:
  Node *head;
  Node *tail;
  size_type queue_size;
};

}  // namespace s21

#include "queue.tpp"
#endif  // CPP2_S21_CONTAINERS_1_QUEUE_H
