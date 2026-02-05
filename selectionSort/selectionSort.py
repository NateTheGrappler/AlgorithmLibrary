import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))

def selectionSort(unsortedArray):

    n = len(unsortedArray)
    
    for i in range(n-1):
        index = i
        for j in range(i, n):
            if(unsortedArray[j] < unsortedArray[index]):
                index = j
        
        temp = unsortedArray[i]
        unsortedArray[i] = unsortedArray[index]
        unsortedArray[index] = temp

    return unsortedArray


startTime = time.perf_counter()
#print(unsortedList)
selectionSort(unsortedList)

endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")