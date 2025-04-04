def merge_sort(list):
    """
    Sorts a list in ascending order
    Returns a new sorted list

    Divide: Find the midpoint of the list and divide into sublists
    Conquer: Recursively sort the sublists created in previous steps
    Combine: Merge the sorted sublists created in previous step

    The run time of the overall process is O(k n log n)
    Take linear space of 0(n)
    """

    if len(list) <= 1:
        return list
    
    left_half, right_half = split(list)
    left = merge_sort(left_half)
    right = merge_sort(right_half)
   
    return merge(left, right)


def split(list):
    """
    Divide the unsorted list at mipoint into sublists
    Return two sublists - left and right

    Takes overall O(k log n) time
    """

    mid = len(list)//2
    left = list[:mid]  # split actually takes O(k), can use recursive binary
    # search to solve this
    right = list[mid:]  # split actually takes O(k), can use recursive binary
    # search to solve this

    return left, right


def merge(left, right):
    """
    Merges two lists (arrays), sorting them in the process
    Return a new merged list

    Takes overall O(n) time
    """

    li = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]: 
            li.append(left[i])
            i += 1
        else:
            li.append(right[j])
            j += 1

    while i < len(left):
        li.append(left[i])
        i += 1

    while j < len(right):
        li.append(right[j])
        j += 1

    return li


# print(l)

def verify_sorted(list):
    n = len(list)

    if n == 0 or n == 1:
        return True

    return list[0] < list[1] and verify_sorted(list[1:])


alist = [54, 26, 62, 93, 77, 32, 44, 55, 20]
li = merge_sort(alist)
print(verify_sorted(alist))
print(verify_sorted(li))
