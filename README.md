## HW 3

Selina Martinez
selinama@usc.edu

### Programming Problem Notes

1. Linked List Split/Pivot

2. Linked List Filter
- Run llrec-test.cpp
- ./llrec-test llrec-test1.in
- Currently, pred is set to filtering out the odds.. to filter out evens, 
  change the class pred in llrec-test.cpp so that if the value is odd, false is returned 

3. Templated Stack
-Stack test written in stack_test.cpp
  -To run do:
     - g++ -g stack_test.cpp -o stack_test
     - ./stack_test

4. Heap Implementation
-Run using Codio's instructions: 
   - make
   - make test
-Additional tests can be found in test_heap.cpp
  -To run, do:
      - g++ -g test_heap.cpp -o test_heap
      - ./test_heap

5. Logic Simulator 
  -Follow Codio instructions:
    - ./logicsim {file.txt} > {file}.uml
    - java -jar plantuml.jar {file}.uml
 