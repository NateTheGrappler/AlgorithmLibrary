import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))

def quickSort(unsortedArray, start, end):

    if(end <= start): return unsortedArray

    pivot = partition(unsortedArray, start, end)
    quickSort(unsortedArray, start, pivot-1)
    quickSort(unsortedArray, pivot+1, end)

    return unsortedArray

def partition(array, start, end):
    pivot = array[end]
    i = start - 1

    for j in range(start, end):
        if(array[j] < pivot):
            i+=1
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
    i+=1
    temp = array[i]
    array[i] = array[end]
    array[end] = temp

    return i



startTime = time.perf_counter()

quickSort(unsortedList, 0, len(unsortedList)-1)

endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")