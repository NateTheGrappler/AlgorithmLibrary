import random
import time
unsortedList = []

minVal = int(input("Min: "))
maxMax = int(input("Max: "))
n = int(input("Number of elements: "))

for i in range(0, n):
    unsortedList.append(random.randint(minVal, maxMax))


def insertionSort(bucket):
    n = len(bucket)
    for i in range(1, n):
        key = bucket[i]
        j = i-1
        while(j>=0 and bucket[j] > key):
            bucket[j+1] = bucket[j]
            j -= 1
        bucket[j+1] = key

def bucketSort(arr):
    n = len(arr)
    buckets = [[] for element in range(n)]

    arrMin = min(arr)
    arrMax = max(arr)

    for num in arr:
        normalized = (num - arrMin) / (arrMax - arrMin)
        bi = int(normalized * n)
        if bi == n:
            bi = n - 1
        buckets[bi].append(num)

    for bucket in buckets:
        insertionSort(bucket)
    
    index = 0
    for bucket in buckets:
        for num in bucket:
            arr[index] = num
            index += 1
    return arr


startTime = time.perf_counter()

#print(bucketSort(unsortedList))
bucketSort(unsortedList)
endTime = time.perf_counter()
totalTime = endTime-startTime

print(f"Total Elapsed time is {totalTime:.4f}")