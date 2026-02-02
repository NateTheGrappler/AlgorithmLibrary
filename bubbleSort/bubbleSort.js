const unsortedArray = [43, 30, 23, 8, 4, 17, 40, 19, 44, 49, 9, 38, 50, 39, 44, 23, 8, 6, 4, 28];

function bubbleSort(unsortedArray)
{
    let n = unsortedArray.length;
    for(let i = 0; i < n-1; i++)
    {
        for(let j = 0; j < n-i-1; j++)
        {
            if(unsortedArray[j] > unsortedArray[j+1])
            {
                let largerValue    = unsortedArray[j];
                let smallerValue   = unsortedArray[j+1];
                unsortedArray[j]   = smallerValue;
                unsortedArray[j+1] = largerValue;
            }
        }_
    }
    return unsortedArray
}

let sortedArray = bubbleSort(unsortedArray);
console.log(sortedArray);