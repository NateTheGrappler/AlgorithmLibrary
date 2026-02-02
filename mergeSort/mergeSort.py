import time
import random

#unsortedList = [50, 11, 23, 3, 38, 39, 0, 7, 0, 15, 6, 9, 16, 25, 30, 41, 30, 29, 23, 39, 20, 18, 20, 20, 5, 13, 5, 9, 10, 6]
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))


def mergeSort(unsortedList):
    if(len(unsortedList) <= 1):
        return unsortedList
    
    mid = len(unsortedList) // 2
    left_half = unsortedList[:mid]
    right_half = unsortedList[mid:]

    left_half = mergeSort(left_half)
    right_half = mergeSort(right_half)

    return mergeSortHelp(left_half, right_half)

def mergeSortHelp(left_half, right_half):
    result = []
    i = j = 0

    while(i < len(left_half) and j < len(right_half) ):

        if(left_half[i] < right_half[j]):
            result.append(left_half[i])
            i += 1
        else:
            result.append(right_half[j])
            j += 1

    result.extend(left_half[i:])
    result.extend(right_half[j:])

    return result


startTime = time.perf_counter()

mergeSort(unsortedList)

endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")