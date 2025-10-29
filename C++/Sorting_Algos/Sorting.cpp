//  <TODO : Add standard assignment information here>
//

#include "Sorting.h"
#include <cstdlib> 
#include <iostream>

using namespace std;

/*
  Please refer to sorting.h for documentation on each function.

   + ------ N O T E: -- Big scary warning! -----------------------------\
   |                                                                    |
   |    We clearly can't use unit testing to ensure that you're         |
   |    actually implementing the correct algorithm. I suppose we could |
   |    write some complicated static analysis checker. But it is       |
   |    easier to just look at it with our eyeballs.                    |
   |                                                                    |
   |    After the assignment is due, we will look at the most recent    |
   |    version of your implementation that got the highest score and   |
   |    make sure you're not doing something sneaky like using a        |
   |    standard library call to sort a vector.                         |
   |                                                                    |
   |    Anyone caught doing this (even though it is kinda funny) will   |
   |    be given 0 points on the assignment.                            |
   |                                                                    |
   `--------------------------------------------------------------------/
*/

// Helper function made for you - just run disp(your_data) to print to console.
void disp(vector<int> const& numbers) {
  if (numbers.size() == 0) {
    cout << "No data" << endl;
    return;
  }
  for (auto const v : numbers) {
    cout << " " << v;
  }
  cout << endl;
}

void quicksort(vector<int>& data, int low_idx, int high_idx) {
    // TODO
    // Handles base case
    if (high_idx <= low_idx) {
        return;
    }

    // Partition the data within the array.
    int low_end_idx = quicksort_partition(data, low_idx, high_idx);
    // Recursively sort low partition and high partition
    quicksort(data, low_idx, low_end_idx);
    quicksort(data, low_end_idx + 1, high_idx);
}

int quicksort_partition(vector<int>& data, int low_idx, int high_idx) {
    // TODO
    // Pick middle element as pivot
    int midpoint = low_idx + (high_idx - low_idx) / 2;
    int pivot = data[midpoint];

    bool done = false;

    while (!done) {
        //Increment low_idx while number[low_idx] < pivot
        while (data[low_idx] < pivot) {
            low_idx += 1;
        }

        //Decrement high_idx while pivot < data[high_idx]
        while (pivot < data[high_idx]) {
            high_idx -= 1;
        }

        //If zero or one elements remain, then all numbers are partitioned. return high_idx.
        if (low_idx >= high_idx) {
            done = true;
        } else {
            //Swap data[low_idx] and data[high_idx]
            int temp = data[low_idx];
            data[low_idx] = data[high_idx];
            data[high_idx] = temp;

            //Update low_idx and high_idx
            low_idx += 1;
            high_idx -= 1;
        }
    }
    return high_idx;
}

void bubblesort(vector<int>& data) {
    // TODO
    int vec_size = data.size();
    for (int i = 0; i < vec_size - 1; i++) {
        for (int j = 0; j < vec_size - i - 1; j++) {
            if (data[j] > data [j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void mergesort(vector<int>& data) {
    // TODO
    if (data.size() <= 1) {
        return;
    }
    
    int middle = data.size() / 2; // Finds middle
    
    vector<int> left = vector<int>(data.begin(), data.begin() + middle); // Left side
    vector<int> right = vector<int>(data.begin() + middle, data.end()); // Right side

    // Recursive calls
    mergesort(left);
    mergesort(right);

    merge(left, right, data);
}

void merge(vector<int>& left, vector<int>& right, vector<int>& result) {
    // TODO
    vector<int> temp_merge; // temp vector

    int i = 0;
    int j = 0;
    
    int left_size = left.size(); // avoids warnings on build
    int right_size = right.size(); // avoids warnings on build

    while (i < left_size && j < right_size){
        if (left[i] <= right[j]) {
            temp_merge.push_back(left[i]);
            i++;
        } else {
            temp_merge.push_back(right[j]);
            j++;
        }
    }

    // if left is not empty
    while (i < left_size) {
        temp_merge.push_back(left[i]);
        i++;
    }

    // if right is not empty
    while (j < right_size) {
        temp_merge.push_back(right[j]);
        j++;
    }

    // copies over to data, passed by reference in mergesort
    result = temp_merge;
}

void mystery_sort(vector<int>& data) {
    // I chose to implement Radix sort

    // Initializes 2d vector for buckets
    vector<vector<int>> buckets(10); 

    // Gets size of data
    int data_size = data.size();
    
    // Finds the max length in number of digits
    int max_digits = radix_get_max_length(data, data_size);

    // Start with the least significant digit
    int pow_ten = 1;
    for (int digit_i = 0; digit_i < max_digits; digit_i++) {
        // Passes values to buckets
        for (int i = 0; i < data_size; i++) {
            int bucket_i = abs(data[i] / pow_ten) % 10;
            buckets[bucket_i].push_back(data[i]);
        }

        // Copies values back to original vector
        int copy_back_i = 0;
        for (int i = 0; i < 10; i++) {
            int bucket_size = buckets[i].size(); // avoids warning on build
            for (int j = 0; j < bucket_size; j++) {
                data[copy_back_i] = buckets[i][j];
                copy_back_i = copy_back_i + 1;
            }
        }
        
        // Increment pow_ten
        pow_ten = 10 * pow_ten;
        // Clears bucket
        int bucket_size = buckets.size(); // avoids warning on build
        for (int i = 0; i < bucket_size; i++) {
            buckets[i].clear();
        }
    }
}

// Returns the max lnegh in mumber of digits out of all the elements in the array
int radix_get_max_length(vector<int>& data, int data_size) {
    int max_digits = 0;
    for (int i = 0; i < data_size; i++) {
        int digit_count = radix_get_length(data[i]);
        if (digit_count > max_digits) {
            max_digits = digit_count;
        }
    }
    return max_digits;
}

// Returns the length, in number of digits, of value
int radix_get_length(int value) {
    if (value == 0) {
        return 1;
    }

    int digits = 0;
    
    while (value != 0) {
        digits = digits + 1;
        value = value / 10;
    }
    return digits;
}
