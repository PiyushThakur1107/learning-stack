/*
========================================================
File: stack_linked_list.cpp
Concept: Stack - Linked List Implementation (Template)
Language: C++
Author: Piyush
========================================================
*/

#include<iostream>
using namespace std;

// Forward declaration of Stack class
template<class T>
class Stack;

// Node class (generic)
template<class T>
class Node {
    T data;           // stores value
    Node<T>* next;    // pointer to next node

public:
    // Constructor
    Node(T val) {
        data = val;
        next = nullptr;
    }

    // Allow Stack to access private members
    friend class Stack<T>;
};

// Stack using Linked List
template<class T>
class Stack {
    Node<T>* head;   // top of stack

public:
    // Constructor
    Stack() {
        head = nullptr;
    }

    /*
     * Function: push
     * Purpose: Insert element at top of stack
     * Time Complexity: O(1)
     */
    void push(T val){
        Node<T>* newnode = new Node<T>(val);

        // Insert at head (top of stack)
        newnode->next = head;
        head = newnode;
    }

    /*
     * Function: pop
     * Purpose: Remove top element
     * Time Complexity: O(1)
     */
    void pop() {
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        // Break link and delete
        temp->next = nullptr;
        delete temp;
    }

    /*
     * Function: top
     * Purpose: Return top element
     * Time Complexity: O(1)
     */
    T top() {
        if(isEmpty()) {
            cout << "Stack Underflow\n";
            return T();   // default value
        }
        return head->data;
    }

    /*
     * Function: isEmpty
     * Purpose: Check if stack is empty
     * Time Complexity: O(1)
     */
    bool isEmpty(){
        return head == nullptr;
    }

    /*
     * Destructor
     * Purpose: Free all allocated memory
     */
    ~Stack() {
        while(head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    // Output: 1 2 3
    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}
