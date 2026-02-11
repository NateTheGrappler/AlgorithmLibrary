import random
import time
import math
unsortedList = []

minVal = int(input("Min: "))
maxVal = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(minVal, maxVal))

def introSort(arr):
    max_depth = 2 * math.floor(math.log2(len(arr)))
    introSortHelper(arr, 0, len(arr)-1, max_depth)
    return arr

def introSortHelper(arr, start, end, max_depth):
    size = end - start+1

    if(size<=16):
        insertion_sort(arr, start, end)
        return
    
    if(max_depth == 0):
        heapSort(arr, start, end)
        return

    pivot = partition(arr, start, end)
    introSortHelper(arr, start, pivot - 1, max_depth - 1)
    introSortHelper(arr, pivot + 1, end, max_depth - 1)

def partition(arr, start, end):
    mid = (start + end) // 2

    if(arr[mid] < arr[start]):
        arr[start], arr[mid] = arr[mid], arr[start]
    if(arr[end] < arr[start]):
        arr[start], arr[end] = arr[end], arr[start]
    if(arr[mid] < arr[end]):
        arr[mid], arr[end] = arr[end], arr[mid]

    pivot = arr[mid]
    arr[mid], arr[end - 1] = arr[end - 1], arr[mid]

    i = start
    j = end-2

    while True:
        i += 1
        while(arr[i] < pivot):
            i+=1
        
        j -= 1
        while(pivot < arr[j]):
            j -= 1
        
        if(i >= j):
            break 

        arr[i], arr[j] = arr[j], arr[i]
    
    arr[i], arr[end - 1] = arr[end - 1], arr[i]
    
    return i


def insertion_sort(arr, start, end):
    for i in range(start + 1, end + 1):
        key = arr[i]
        j = i - 1

        while(j >= start and arr[j]>key):
            arr[j+1] = arr[j]
            j-=1

        arr[j+1] = key

def heapSort(arr, start, end):
    n = end - start + 1

    for i in range(n//2 - 1, -1, -1):
        heapify(arr, i, n, start)
    
    for i in range(n-1, 0, -1):
        arr[start], arr[start+i] = arr[start+i], arr[start]
        heapify(arr, 0, i, start)

def heapify(arr, i, n, offset):
    largest = i
    left    = 2 * i + 1
    right   = 2 * i + 2

    if(left < n and arr[offset + left] > arr[offset + largest]):
        largest = left
    if(right < n and arr[offset + right] > arr[offset + largest]):
        largest = right

    if largest != i:
        arr[offset + i], arr[offset + largest] = arr[offset + largest], arr[offset + i]
        heapify(arr, largest, n, offset)

startTime = time.perf_counter()

#print(introSort(unsortedList))
introSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")