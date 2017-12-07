#pragma once

#include <stdexcept>

template <class T>
class Node {
 public:
 Node(T value) : value_(value), next_(NULL) {}
 Node(T value, Node* next) : value_(value), next_(next) {}

  T value_;
  Node *next_;
};

template <class T>
class List {
 public:
 List() : root_(NULL) {}
  ~List() {
    while(root_) {
      pop_front();
    }
  }

  T const & operator[](size_t idx) const {
    Node<T> *n = at(idx);
    if (!n) {
      throw std::out_of_range("");
    }
    return n->value_;
  }

  void push_back(T value) {
    if (root_) {
      Node<T> *n = root_;
      while(n->next_) {
        n = n->next_;
      }
      n->next_ = new Node<T>(value);
    } else {
      root_ = new Node<T>(value);
    }
  }
  void push_front(T value) {
    if (root_) {
      root_ = new Node<T>(value, root_);
    } else {
      root_ = new Node<T>(value);
    }
  }

  void pop_back() {
    if (!root_) {
      return;
    } else if (!root_->next_) {
      delete root_;
      root_ = NULL;
    } else {
      Node<T> *second_last = root_;
      while(second_last->next_->next_) {
        second_last = second_last->next_;
      }
      delete second_last->next_;
      second_last->next_ = NULL;
    }
  }
  void pop_front() {
    if (!root_) {
      return;
    } else {
      Node<T> *old = root_;
      root_ = root_->next_;
      delete old;
    }
  }

  size_t size() const {
    size_t s = 0;
    for (Node<T> *n = root_; n; ++s) {
      n = n->next_;
    }
    return s;
  }

 private:
  Node<T> *at(size_t idx) const {
    Node<T> *n = root_;
    for (int i = 0; i < idx && n; ++i) {
      n = n->next_;
    }
    return n;
  }

  Node<T> *root_;
};
