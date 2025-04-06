# best case O(n log n)
# worst cast O(n squared)

numbers = [2, 3, 2, 5, 7, 8, 9]


def quick_sort(values):
    if len(values) <= 1:
        return values
    less_than_pivot = []
    greater_than_pivot = []
    pivot = values[0] # pick a pivot at random to improve big O
    # divide and conquer:
    for value in values[1:]:
        if value <= pivot:
            less_than_pivot.append(value)
        else:
            greater_than_pivot.append(value)
    return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)


print(numbers)
sorted_numbers = quick_sort(numbers)
print(sorted_numbers)

numbers.sort()
print(numbers)