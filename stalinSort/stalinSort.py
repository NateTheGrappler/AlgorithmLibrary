import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))

def stalinSort(arr):

    if not arr:
        return []
    
    sorted_list = [arr[0]]
    
    for i in range(1, len(arr)):
        if arr[i] >= sorted_list[-1]:
            sorted_list.append(arr[i])
    
    return sorted_list


startTime = time.perf_counter()
print(unsortedList)
print(stalinSort(unsortedList))
#stalinSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")