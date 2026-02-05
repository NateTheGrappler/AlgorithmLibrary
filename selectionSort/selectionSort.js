function selectionSort(unsortedArray)
{
    let n = unsortedArray.length;
    for(let i = 0; i< n-1; i++)
    {
        let index = i;
        for(let j = i+1; j<n; j++)
        {
            if(unsortedArray[j] < unsortedArray[index])
            {
                index = j;
            }
        }
        let temp = unsortedArray[i];
        unsortedArray[i] = unsortedArray[index];
        unsortedArray[index] = temp;
    }
}