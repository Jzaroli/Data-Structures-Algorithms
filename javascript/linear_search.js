function linear_search(list, target) {
    for(let i = 0; i < list.length; i++) {
        if (list[i] === target) 
            return i;
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

const numbers = [0,1,2,3,4,5,6,7,8,9,10];

const result = linear_search(numbers, 12);
verify(result);