#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector> 
// include this so can use vector container 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_; 
  // variable for the heap 
  int m_; 
  PComparator c_; 
  // variables needed for constructor 
  void heapifyDown(size_t idx); 
  // trickledown from slides - used in pop 
  void heapifyUp(size_t idx); 
  // trickleup from slides - used in push 

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), c_(c)
{
  // complete 
}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  // complete 
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  // add node 
  heap_.push_back(item); 
  // add the item 
  heapifyUp(heap_.size() - 1);
  // use up for push 
  // COMPLETE 
}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap_.empty(); 
  // complete - same as stack 
}


template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_.size(); 
  // complete - same as stack 
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t idx)
{
  // similar to what was on lecture slides 
  // first check if it is leaf node - get idx of left child first 
  size_t left = m_ * idx + 1; // bc starting at idx 0 so plus 1 more than if starting at 1 
  if (left >= size()){
    return; 
    // if leaf node 
  }
  size_t priority = left; 
  // start this with left, will change as continue 
  for (size_t i = 1; i < m_; i++){
    // goes through all the children 
    size_t right = left + i; 
    // get right 
    // now compare to find the priority 
    if (right < size() && c_(heap_[right], heap_[priority])){
      priority = right; 
    }
  }

  // finally compare with parent then recursive call to continue down the heap 
  if (c_(heap_[priority], heap_[idx])){
    std::swap(heap_[idx], heap_[priority]);
    // recursive call: 
    heapifyDown(priority);
  }

  // check if right child exists, swap, recursive 
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t idx)
{
  // implementation based on slides from lecture 
  // find parent, swap, loc = parent, new parent
  // should be recursive 
  // if (idx == 0){
  //   return; 
  //   // base case: root has no parent 
  // } 
  size_t parent = (idx - 1) / m_; 
  // parent loc 
  while (idx > 0 && c_(heap_[idx], heap_[parent])){
    std::swap(heap_[idx], heap_[parent]); 
    idx = parent; 
    parent = (idx - 1) / m_; 
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
// only retrieves the top (does not remove it)
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty, so there is no top element");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  // top element will always be the index 0 
  return heap_.front();
  // COMPLETE 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty, so there is nothing to pop");

  }
  // to pop: want the root node to be at back so you can pop_back() then heapify 
  // basic template from lecture slides 
  heap_[0] = heap_.back(); 
  // set it equal to back 
  heap_.pop_back(); 
  // pop what you just set 
  if (!empty()){
    heapifyDown(0); 
    // down for pop if pop didnt make heap empty 
  }

}



#endif

