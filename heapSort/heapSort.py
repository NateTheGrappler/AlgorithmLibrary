import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
num = int(input("Number of elements: "))

for i in range(0, num):
    unsortedList.append(random.randint(min, max))

def heapify(arr, n, i):
    largest = i

    left = 2 * i + 1
    right = 2 * i + 2

    if(left<n and arr[left] > arr[largest]):
        largest = left
    
    if(right<n and arr[right] > arr[largest]):
        largest = right

    if(largest != i):
        arr[i], arr[largest] = arr[largest], arr[i]

        heapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n -1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
    
    return arr

startTime = time.perf_counter()

#print(heapSort(unsortedList))
heapSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")