function mergeSort(list) {
    // If the list contains 0 or 1 , it is already sorted
    if (list.length <= 1) {
        return list
    }

    // Split the list into two halves
    const {firstHalf, secondHalf } = splitArray(list)

    // Recursively sort both halves:
    const left = mergeSort(firstHalf)
    const right = mergeSort(secondHalf)

    // Merge the sorted halves back together:
    return merge(left, right)

}

// Find the midpoint to split the array into two halves and returns them
function splitArray(array) {
    const midpoint = Math.floor(array.length / 2)

    const firstHalf = array.slice(0, midpoint)
    const secondHalf = array.slice(midpoint)

    return {firstHalf, secondHalf}

}

function merge(left, right) {
    let l = []
    // Initialize pointers for both left and right arrays.
    let i = 0
    let j = 0

    while (i < left.length && j < right.length) {
        // If the current element in the left array is smaller, add it to the result.
        if (left[i] < right [j]) {
            l.push(left[i])
            i += 1
        // Otherwise, add the current element in the right array to the result.
        } else {
            l.push(right[j])
            j += 1
        }
    }

    // Add any remaining elements from the left array to the result.
    while (i < left.length) {
        l.push(left[i])
        i += 1
    }
    
    // Add any remaining elements from the right array to the result.
    while (j < right.length) {
        l.push(right[j])
        j += 1
    }
    return l;
}

const alist = [54, 26, 62, 93, 77, 32, 44, 55, 20]
const l = mergeSort(alist)

console.log(l)

