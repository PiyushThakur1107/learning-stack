/*
========================================================
File: stack_template_vector.cpp
Concept: Stack - Template Implementation using Vector
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Template class → allows stack to store any data type (int, string, etc.)
template<class T>
class Stack {

    // Underlying container (dynamic array)
    // vector automatically resizes when elements are added
    vector<T> vec;

public:

    /*
     * Function: push
     * Purpose: Insert an element at the top of the stack
     * Time Complexity: O(1) amortized
     * Space Complexity: O(1)
     */
    void push(T val) {
        // push_back adds element at end → acts as top of stack
        vec.push_back(val);
    }

    /*
     * Function: pop
     * Purpose: Remove the top element from the stack
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void pop() {

        // Case 1: Stack is empty
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }

        // Remove last element (top of stack)
        vec.pop_back();
    }

    /*
     * Function: top
     * Purpose: Return the top element without removing it
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    T top() {

        // Case 1: Stack is empty
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return T();   // return default value of type T
        }

        // Last index represents top of stack
        int lastIdx = vec.size() - 1;

        return vec[lastIdx];
    }

    /*
     * Function: isEmpty
     * Purpose: Check whether stack is empty
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() {

    // Create stack of type string
    Stack<string> s;

    // Push elements → order: morning (bottom), Good, Hello (top)
    s.push("morning");
    s.push("Good");
    s.push("Hello");

    // Loop until stack becomes empty
    while(!s.isEmpty()){

        // Print top element
        cout << s.top() << " ";

        // Remove top element
        s.pop();
    }

    // Output: Hello Good morning
    cout << endl;

    return 0;
}
