unsortedArray = [43, 30, 23, 8, 4, 17, 40, 19, 44, 49, 9, 38, 50, 39, 44, 23, 8, 6, 4, 28]

def bubbleSort(arrayInput):
    n = len(arrayInput)
    for i in range(n-1):
        for j in range(n-i-1):
            if(arrayInput[j] > arrayInput[j+1]):
                largerValue = arrayInput[j]
                smallerValue = arrayInput[j+1]
                arrayInput[j] = smallerValue
                arrayInput[j+1] = largerValue
    return arrayInput


print(bubbleSort(unsortedArray))