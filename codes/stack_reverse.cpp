/*
========================================================
File: reverse_stack.cpp
Concept: Stack - Reverse a Stack using Recursion
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<stack>
using namespace std;

/*
 * Function: PushAtBottom
 * Purpose: Insert an element at the bottom of the stack
 * Approach: Recursively remove all elements, insert value,
 *           then place removed elements back.
 * Time Complexity: O(n)
 * Space Complexity: O(n)   // recursion stack
 */
void PushAtBottom(stack<int> &s, int val){

    // Base Case: stack becomes empty
    if(s.empty()){
        s.push(val);
        return;
    }

    // Store top element
    int temp = s.top();
    s.pop();

    // Insert value at bottom
    PushAtBottom(s, val);

    // Restore removed element
    s.push(temp);
}

/*
 * Function: reverse
 * Purpose: Reverse the entire stack using recursion
 * Approach:
 *   1. Remove top element
 *   2. Reverse remaining stack
 *   3. Insert removed element at bottom
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n)
 */
void reverse(stack<int> &s){

    // Base Case
    if(s.empty()){
        return;
    }

    // Remove top element
    int temp = s.top();
    s.pop();

    // Reverse remaining stack
    reverse(s);

    // Place removed element at bottom
    PushAtBottom(s, temp);
}

/*
 * Function: PrintStack
 * Purpose: Display stack elements from top to bottom
 * Note: Stack is passed by value so original stack
 *       remains unchanged.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void PrintStack(stack<int> s){

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main(){

    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    cout << "Before Reversing Stack: ";
    PrintStack(s);

    reverse(s);

    cout << "After Reversing Stack: ";
    PrintStack(s);

    return 0;
}
