import random
import time
unsortedList = []

min = int(input("Min: "))
maxVal = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, maxVal))

def countingSort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0]*10

    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1
    
    for i in range(1, 10):
        count[i] += count[i-1]
    
    for i in range(n-1, -1, -1):
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1

    for i in range(n):
        arr[i] = output[i]

def radixSort(arr):
    if not arr:
        return arr
    
    max_num = max(arr)

    exp = 1
    while(max_num // exp > 0):
        countingSort(arr, exp)
        exp *= 10
    
    return arr


startTime = time.perf_counter()

#print(radixSort(unsortedList))
radixSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")

