# Arrays are good at accessing data with O(1), but not as good as adding and deleting O(n)

new_list = [1,2,3]
result = new_list[0] 
print(result) # accesses 0-indexed value in new_list
print(new_list) # prints out the whole array

# Arrays are quick for accessing data, but slow for seaching, given that it uses linear search

# Using the in operator:
if 1 in new_list: print(True)

# Using a For loop:
for n in new_list:
    if n == 1:
        print (True)
        break
    else:
        print(False)
        break

# You can insert a new value at the start of the array or append it to the end of the array

numbers = [] # print(len(numbers)) = 0
numbers.append(2) # print(len(numbers)) = 1
numbers.append(200) # print(len(numbers)) = 2

# Python has an "ammortized constant space complexity"

numbers2 = []
numbers2.extend([4,5,6]) #print(len(numbers2)) = 3
# runtime of O(k), where k equals the number of extensions

# Delete operations have a 0(n), or linear runtime