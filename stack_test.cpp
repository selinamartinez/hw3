#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

int main()  {

    Stack<int>s;

    s.push(3);
    s.push(2);
    s.push(15);
    cout << s.size() << endl;
    cout << s.top() << endl;
}