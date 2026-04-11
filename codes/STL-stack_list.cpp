/*
========================================================
File: stack_list.cpp
Concept: Stack - Template Implementation using STL list
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<list>
using namespace std;

// Template Stack using STL list (doubly linked list internally)
template<class T>
class Stack{

    list<T> ll;   // underlying container

public:

    /*
     * Function: push
     * Purpose: Insert element at top of stack
     * Time Complexity: O(1)
     */
    void push(T val){
        // Insert at front → acts as top
        ll.push_front(val);
    }

    /*
     * Function: pop
     * Purpose: Remove top element
     * Time Complexity: O(1)
     */
    void pop() {

        // Underflow check
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }

        ll.pop_front();
    }

    /*
     * Function: top
     * Purpose: Return top element without removing it
     * Time Complexity: O(1)
     */
    T top(){

        // Underflow check
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return T();   // default value
        }

        return ll.front();
    }

    /*
     * Function: isEmpty
     * Purpose: Check if stack is empty
     * Time Complexity: O(1)
     */
    bool isEmpty(){
        return ll.empty();   // cleaner than size()==0
    }
};

int main()  {

    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    // Output: 1 2 3 (LIFO)
    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}
