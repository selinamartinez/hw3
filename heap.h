#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>
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
  int m_;
  PComparator c_;
  std::vector<T> the_heap;
  void heapify(int idx);
  void trickleUp(int idx);


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c){

}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if(the_heap.size() == 0) { 
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{

    return the_heap.size();

 }


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return the_heap[0];


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
    throw std::underflow_error("empty heap");
  }
  //replace first element of the heap with the last element
  int last_index = the_heap.size() - 1;
  the_heap[0] = the_heap[last_index];
  the_heap.erase(the_heap.begin() + last_index);
  //fix the heap
  heapify(0);


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{

  the_heap.push_back(item);
  int idx = the_heap.size() - 1;
  //fix the heap
  trickleUp(idx);

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int idx) {

  long unsigned int parent_idx = (idx - 1) / m_;
  while ( (parent_idx >= 0 ) ) {
    if ( c_(the_heap[idx], the_heap[parent_idx] ) ) {
       //swap heap[parent_idx] and heap[idx]
      T tmp = the_heap[parent_idx];
      the_heap[parent_idx] = the_heap[idx];
      the_heap[idx] = tmp;
      idx = parent_idx;
      parent_idx = (idx - 1) / m_;

    }
    else {
      break;
    }
   
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx) {

  long unsigned int parent_idx = 0;
  while(1) {
    long unsigned int smallest_idx = parent_idx;
    //go to all the children and find the child with the smallest value
    long unsigned int starting_point = m_ * parent_idx + 1;
    for(long unsigned int i = starting_point; i <= (m_ * parent_idx + m_) && i < the_heap.size(); i++) {
      // c_(the_heap[idx], the_heap[parent_idx]
      if(c_(the_heap[i], the_heap[smallest_idx] ) ) {
        smallest_idx = i;
      }
    }
    if(smallest_idx == parent_idx) {
      break;
    }
    else {
      T temp = the_heap[smallest_idx];
      the_heap[smallest_idx] = the_heap[parent_idx];
      the_heap[parent_idx] = temp;
      parent_idx = smallest_idx;
      
    }
  }


}



#endif

