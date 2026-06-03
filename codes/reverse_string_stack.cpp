/*
========================================================
File: reverse_string_using_stack.cpp
Concept: Stack - Reverse a String
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
 * Function: reverseString
 * Purpose: Reverse a string using Stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
string reverseString(string str){

    string ans;

    stack<char> s;

    // Push all characters into stack
    for(int i = 0; i < str.size(); i++){
        s.push(str[i]);
    }

    // Pop characters and store in answer string
    while(!s.empty()){

        char top = s.top();

        ans += top;

        s.pop();
    }

    return ans;
}

int main(){

    string str = "Hello";

    cout<<"Original String : "<<str<<endl;

    cout<<"Reversed String : "<<reverseString(str)<<endl;

    return 0;
}
