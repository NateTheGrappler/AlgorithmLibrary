import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))

def shellSort(arr):
    n = len(arr)
    gap = n // 2

    while( gap > 0):

        for i in range(gap, n):

            temp = arr[i]
            j = i

            while(j >= gap and arr[j-gap] > temp):
                arr[j] = arr[j - gap]
                j-=gap
            arr[j] = temp

        gap = gap // 2
    return arr

startTime = time.perf_counter()

#print(shellSort(unsortedList))
shellSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")