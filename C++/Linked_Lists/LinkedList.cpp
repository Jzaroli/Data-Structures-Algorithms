//  LinkedList.cpp
//      Various CRUD like methods and related operations for a Linked List in OOP
//
//  Author: Johann Zaroli
//  CU ID: joza4047
//  GitHub Username: Jzaroli
//  Hours to complete lab: 3.5 + 2 + 1
//

#include "LinkedList.h"
#include <string>

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
    // Your code here
    top_ptr_ = nullptr;
}

// deconstructor,
LinkedList::~LinkedList() {}

// Initializes Node
node* LinkedList::init_node(int data) {
    node* ret(new node);
    ret->data = data;
    return ret;
}

string LinkedList::report() {
    string ret;
    // Your code here
    node* current_node = get_top();

    while (current_node != nullptr) {
        string append = to_string(current_node->data);
        ret = ret + append + " ";
        current_node = current_node->next;
    }
    return ret;
}

void LinkedList::append_data(int data) {
    // Your code here
    node* new_node = init_node(data);
    append(new_node);
}

void LinkedList::append(node* new_node) {
    // Your code here
    node* current_node = get_top();
    
    if (current_node == nullptr) {
        set_top(new_node);
    } else {
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void LinkedList::insert_data(int offset, int data) {
    // Your code here
    if (offset < 0) {
        return;
    }
    
    node* current_node = get_top();

    if (offset == 0) {
        node* new_node = init_node(data);
        new_node->next = current_node;
        set_top(new_node);
        return;
    }  
    
    int count = 0;
    while (current_node->next != nullptr && count < offset-1 ) {
        current_node = current_node->next;
        count++;
    }
    
    if (current_node == nullptr) {
        append_data(data);
        return;
    } else {
        node* new_node = init_node(data);
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

void LinkedList::insert(int offset, node* new_node) {
  // Your code here
    if (offset < 0) {
        return;
    }
    
    node* current_node = get_top();

    if (offset == 0) {
        new_node->next = current_node;
        set_top(new_node);
        return;
    }  
    
    int count = 0;
    while (current_node->next != nullptr && count < offset-1 ) {
        current_node = current_node->next;
        count++;
    }
    
    if (current_node == nullptr) {
        append(new_node);
        return;
    } else {
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

void LinkedList::remove(int offset) {
    // Your code here
    if (offset < 0) {
        return;
    }

    node* current_node = get_top();

    if (offset == 0) {
        node* next_node = current_node->next;
        set_top(next_node);
        delete(current_node);
        return;
    }

    int count = 0;
    node* previous_node = get_top();
    while (current_node->next != nullptr && count != offset) {
        previous_node = current_node;
        current_node = current_node->next;
        count++;
    }

    if (current_node == nullptr) {
        return;
    } else {
        previous_node->next = current_node->next;
        delete(current_node);
    }
}

int LinkedList::size() {
    int ret = 0;
    // Your code here
    node* current_node = get_top();
    while (current_node != nullptr) {
        ret++;
        current_node = current_node->next;
    }
    return ret;
}

bool LinkedList::contains(int data) {
    bool ret = false;
    // Your code here
    node* current_node = get_top();
    while (current_node != nullptr) {
        if (current_node->data == data) {
            ret = true;
        }
        current_node = current_node->next;
    }
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }
