import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))

def insertionSort(arr):
    n = len(arr)

    if( n <= 1): return

    for i in range(1, n):
        key = arr[i]
        j = i-1

        while(j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -=1
        arr[j+1] = key

    return arr


startTime = time.perf_counter()

#print(insertionSort(unsortedList))
insertionSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")