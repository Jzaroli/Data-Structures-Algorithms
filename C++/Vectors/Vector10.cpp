//  Vector10.cpp
//      <TODO: Describe the data structure here >
//
//  Author: Johann Zaroli
//  CU ID: joza4047
//  GitHub Username: Jzaroli

#include "Vector10.h"

Vector10::Vector10() {
    // YOUR CODE HERE
    for (int i = 0; i < 10; i++) {
        arr[i] = 0;
    };

    size = 0;
}

Vector10::~Vector10() {
  // You don't need to add anything here
}

// Implement this function first, since all tests use it.
int Vector10::value_at(int index) {
    return arr[index];
}

// Implement this function second, since most tests use it.
bool Vector10::push_back(int value) {
    if (size >= 10) {
        return false;
    } else {
        arr[size] = value;
        size ++;
        return true;
    }
}

int Vector10::count_empty() {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 0) {
            count ++;
        }
    }
    return count;
}

bool Vector10::search(int value) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

bool Vector10::remove(int index) {
    if (index >= 10) {
        return false;
    } else {
        arr[index] = 0;
        for (int i = index; i < 10; i++) {
            if (i == 10) {
                arr[i] = 0;
            } else {
                int plus_one = i + 1;
                arr[i] = arr[plus_one];
            }
        }   
        return true;
    }
}
