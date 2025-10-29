#include "PriorityQueue.h"

#include <iostream>
using namespace std;
// Implement this after defining struct in .h file
pq* init_priority_queue() {
    // TODO
    pq* ret(new pq);
    return ret;
}

string peek_pq(pq*& queue) {
    // TODO
    if (queue->pq_vector.empty()) {
        return "";
    } else {
        string str = queue->pq_vector[0].data;
        return str;
    };
}

void insert_pq(pq*& queue, string text, float priority) {
    // TODO
    
    // Initializes new node then inserts node at the end of the vector
    pq_node node = {text, priority};
    queue->pq_vector.push_back(node);

    // Calculates the index of the new, inserted node
    int node_index = queue->pq_vector.size() - 1;
    
    while (node_index > 0) {
        // Calculates parent index location
        int parent_index = (node_index - 1) / 2;
        // exits if the value of the new node's priority is smaller or equal to its parent
        if (queue->pq_vector[node_index].priority <= queue->pq_vector[parent_index].priority) {
            return;
        } else {
            // Copies node values
            pq_node temp_node = queue->pq_vector[node_index];
            queue->pq_vector[node_index] = queue->pq_vector[parent_index]; // Percolates new node up
            queue->pq_vector[parent_index] = temp_node; // Percolates parent node down
            node_index = parent_index; // Swaps index for the loop to continue with percolate up process
        }
    }
    return;
}

string remove_pq(pq*& queue) {
    // TODO
    if (queue->pq_vector.empty()) {
        return "";
    }

    // Calculates intial size of vector
    int size = queue->pq_vector.size();
    
    // Part 1
    // Swap the last node with the first
    
    string to_return = queue->pq_vector[0].data; // Functions needs to return string/data of node deleted
    queue->pq_vector[0] = queue->pq_vector[size-1]; // Removes root node by swapping with last
    queue->pq_vector.pop_back(); // Removes last node
    size--; // Reduces size for part 2

    // Part 2
    // Percolate down and sort vector:
    
    int node_index = 0; // node index set to 0
    int child_index = 2 * node_index + 1; // calculates child index
    int value =  queue->pq_vector[node_index].priority; // Stores priority of node at current root

    while (child_index < size) {
        int max_value = value; // Initialize max value same as intial root node's after deletion
        int max_index = -1; 
        
        // Finds the max among the node and all the node's children:
        // The loop checks the 3 associated parent/child indexes with i < 2
        // Looks only  atexisting values, omitting those beyond the end of the vector w/ i + child_index < size
        for (int i = 0; i < 2 && i + child_index < size; i++) {
            if (queue->pq_vector[i + child_index].priority > max_value) {
                max_value = queue->pq_vector[i + child_index].priority;
                max_index = i + child_index;
            }
        }

        if (max_value == value) {
            return to_return; 
        } else {
            pq_node temp_node = queue->pq_vector[node_index];
            
            // Percolates high priority child node up that needs to become parent node
            queue->pq_vector[node_index] = queue->pq_vector[max_index]; 
            
            queue->pq_vector[max_index] = temp_node; // Percolates lower priority node down
            
            node_index = max_index; // Sets the node_index value to be equal to the node that was moved down
            child_index = 2 * node_index + 1; // Resets the child index based on the new node_index
        }
    }

    return to_return; // Returns deleted value when finished
    
}
