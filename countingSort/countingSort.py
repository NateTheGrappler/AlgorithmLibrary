import random
import time
unsortedList = []

min = int(input("Min: "))
maxVal = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, maxVal))

def countingSort(arr):
    if(not arr): return []

    n = len(arr)
    largestVal = max(arr)
    countArray = [0] * (largestVal + 1)

    for value in arr:
        countArray[value] += 1

    for i in range(1, largestVal+1):
        countArray[i] += countArray[i-1]

    ans = [0] * n
    for i in range(n-1, -1, -1):
        v = arr[i]
        ans[countArray[v]-1] = v
        countArray[v] -= 1

    return ans

startTime = time.perf_counter()

#print(countingSort(unsortedList))
countingSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")