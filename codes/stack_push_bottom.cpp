/*
========================================================
File: push_at_bottom.cpp
Concept: Stack - Push Element at Bottom
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<stack>
using namespace std;

/*
 * Function: PushAtBottom
 * Purpose: Insert an element at the bottom of a stack
 * Approach: Recursion
 * Time Complexity: O(n)
 * Space Complexity: O(n)   // recursive call stack
 */
void PushAtBottom(stack<int> &s, int val){

    // Base Case:
    // If stack becomes empty,
    // insert element at bottom
    if(s.empty()){
        s.push(val);
        return;
    }

    // Store top element
    int temp = s.top();
    s.pop();

    // Recursive call
    PushAtBottom(s, val);

    // Restore removed elements
    s.push(temp);
}

int main(){

    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    cout<<"Stack before insertion at bottom:\n";

    stack<int> temp = s;

    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

    PushAtBottom(s, 4);

    cout<<"\nStack after insertion at bottom:\n";

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;

    return 0;
}
