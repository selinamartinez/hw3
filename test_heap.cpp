#include <iostream>
#include "heap.h"

using namespace std;

int main(){
	//Heap<int> h1;

    //create  a comparator class called ObjAComparator...use it for greater. So if std::greater<int>
    //then its a max heap
    std::less<int> c1;

  /*
	Heap<int, std::less<int> > h2(3, c1);

	h2.push(50);
	h2.push(49);

    std::cout << "The top value is: " << h2.top() << std::endl; //should be 49
    h2.pop();
    std::cout << "and the size should be 1 now: " << h2.size() << std::endl; //should be 49

    std::cout << "The new top should be 50: " << h2.top() << std::endl; //should be 50
    */


    Heap<int> heap(3);
	heap.push(0);
	heap.push(5);
	heap.push(10);
	heap.push(15);
	heap.push(20);

	std::cout << "top should be 0: " << heap.top() << std::endl; 
	heap.pop();
    std::cout << "top should be 5: " << heap.top() << std::endl; 
	heap.pop();
	std::cout << "top should be 10: " << heap.top() << std::endl; 
	heap.pop();
	std::cout << "top should be 15: " << heap.top() << std::endl; 
	heap.pop();
	std::cout << "top should be 20: " << heap.top() << std::endl; 


}