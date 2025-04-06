"""
    Recursive case: when there are still elements in the list
    Base case: when there are no longer elements in the list
"""


def sum(numbers):
    if not numbers:
        return 0
    remaining_sum = sum(numbers[1:])
    return numbers[0] + remaining_sum


print(sum([1, 2, 7, 9]))
