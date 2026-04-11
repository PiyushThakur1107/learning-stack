/*
========================================================
File: stack_array.cpp
Concept: Stack - Array Implementation
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Stack implementation using fixed-size array
class Stack {
    int arr[100];   // array to store stack elements (capacity = 100)
    int top = -1;   // index of top element
                    // top = -1 means stack is empty

public:

    /*
     * Function: push
     * Purpose: Insert an element at the top of the stack
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push(int val) {

        // Case 1: Stack Overflow (array is full)
        if(top == 99){
            cout << "Stack Overflow\n";
            return;
        }

        // Move top pointer to next index
        top++;

        // Insert value at new top position
        arr[top] = val;
    }

    /*
     * Function: pop
     * Purpose: Remove the top element from the stack
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void pop() {

        // Case 1: Stack Underflow (empty stack)
        if(top == -1){
            cout << "Stack Underflow\n";
            return;
        }

        // Logical deletion:
        // No need to erase value from array
        // Just move top pointer back
        top--;
    }

    /*
     * Function: peek
     * Purpose: Return the top element without removing it
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int peek() {

        // Case 1: Stack is empty
        if(top == -1){
            cout << "Stack Underflow\n";
            return -1;   // sentinel value (indicates error)
        }

        // Return element at top
        return arr[top];
    }

    /*
     * Function: print
     * Purpose: Display all elements in the stack
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void print() {

        // Case 1: Stack is empty
        if(top == -1) {
            cout << "Stack Empty\n";
            return;
        }

        // Print elements from bottom to top
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main(){
    Stack s;

    // Push elements into stack
    for(int i = 0; i < 10; i++){
        s.push(i);
    }

    // Peek top element
    cout << "Top element: " << s.peek() << "\n";

    // Print entire stack
    cout << "Stack elements (bottom to top): ";
    s.print();

    return 0;
}
