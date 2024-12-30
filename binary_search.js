function binary_search(list, target) {
    let first = 0;
    let last = list.length - 1;

    while (first <= last) {
        let midpoint = Math.floor((first + last)/2);
        // console.log(midpoint)
        if (list[midpoint] === target) {
            return midpoint;
        } else if (list[midpoint] < target) {
            first = midpoint + 1;
        } else {
            last = midpoint - 1;
        } 
    }
    return 'None';
};



function verify(number) {
    if (number === 'None') {
        console.log('target not found in list')
    }
    else {
        console.log('target found at index:', number)
    }
};

const numbers = [1,2,3,4,5,6,7,8];

const result = binary_search(numbers, 4);
verify(result);