/*
========================================================
File: stack_vector.cpp
Concept: Stack - Vector Implementation
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<vector>   // Required for using vector
using namespace std;

// Stack class implementing LIFO (Last In First Out)
class Stack {

    // Underlying container to store stack elements
    // vector is dynamic → automatically resizes as elements are added/removed
    vector<int> vec;

public:

    /*
     * Function: push
     * Purpose: Insert an element at the top of the stack
     * Time Complexity: O(1) amortized
     * Space Complexity: O(1)
     */
    void push(int val){
        // push_back inserts element at end → acts as top of stack
        vec.push_back(val);
    }

    /*
     * Function: pop
     * Purpose: Remove the top element from the stack
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void pop() {

        // Safety check → cannot remove from empty stack
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }

        // Removes last element (top of stack)
        vec.pop_back();
    }

    /*
     * Function: top
     * Purpose: Return the top element without removing it
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int top() {

        // Safety check → accessing empty stack is invalid
        if(isEmpty()){
            cout << "Stack is Empty\n";
            return -1; // Sentinel value (indicates error)
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
    bool isEmpty(){

        // If size is 0 → no elements present
        return vec.size() == 0;
    }
};

int main(){

    // Create stack object
    Stack s;

    // Push elements → order: 3 (bottom), 2, 1 (top)
    s.push(3);
    s.push(2);
    s.push(1);

    // Loop until stack becomes empty
    while(!s.isEmpty()){

        // Print top element
        cout << s.top() << " ";

        // Remove top element
        s.pop();
    }

    // Output will be: 1 2 3 (LIFO order)
    cout << endl;

    return 0;
}
