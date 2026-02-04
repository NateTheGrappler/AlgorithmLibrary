import random
import time
unsortedList = []

min = int(input("Min: "))
max = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(min, max))


def bogoSortCheck(unsortedList):
    for i in range(len(unsortedList)-1):
        if(unsortedList[i] > unsortedList[i+1]):
            return False
    return True

def bogoSort(unsortedList):

    while(not bogoSortCheck(unsortedList)):
        random.shuffle(unsortedList)
    
    return unsortedList


startTime = time.perf_counter()

print(bogoSort(unsortedList))

endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")