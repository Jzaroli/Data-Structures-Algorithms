def binary_search(list, target):
    first = 0
    last = len(list) -1

    while first <= last:
        midpoint = (first + last)//2
        #The // is the floor division operator which will round down the number to the nearest integer, ex: 0+7/2 = 3.5; or 0+7//2 = 3
        if list[midpoint] == target:
            return midpoint
        elif list[midpoint] < target:
            first = midpoint + 1
        else:
            last = midpoint - 1

    return None

def verify(index):
    if index is not None:
        print("target found at index: ", index)
    else:
        print("target not found in list")

numbers = [0,1,2,3,4,5,6,7,8]

result = binary_search(numbers, 2)
verify(result)
