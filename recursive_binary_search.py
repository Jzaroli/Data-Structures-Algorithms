def recursive_binary_search(list, target):
    if len(list) == 0:
        return False
    else:
        midpoint = len(list)//2

        if list[midpoint] == target:
            return True
        else: 
            if list[midpoint] < target:
                return recursive_binary_search(list[midpoint+1:], target)
                # The end is specified by the lack of value after the colon
            else:
                return recursive_binary_search(list[:midpoint], target)
                # The beginning is specified by the lack of value before the colon


def verify(result):
    print("target found:", result)

numbers = [1,2,3,4,5,6,7,8]

result = recursive_binary_search(numbers, 12)
verify(result)

result = recursive_binary_search(numbers, 6)
verify(result)

#A recursive function is one that calls itself
#python has a maximum recursive depth and prefers iterative solutions