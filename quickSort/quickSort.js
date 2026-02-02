let unsortedArray = [2, 3, 5, 2, 1];

function quickSort(array, start, end)
{
    if(start >= end)
    {
        return array;
    }

    let pivot = partition(array, start, end);
    quickSort(array, start, pivot-1);
    quickSort(array, pivot+1, end)

    return array;
}
function partition(array, start, end)
{
    let pivot = array[end];
    let i = start - 1;

    for(let j = start; j<end; j++ )
    {
        if(pivot>array[j])
        {
            i++;
            let temp = array[i];
            array[i]=array[j];
            array[j] = temp;
        }
    }
    i++;
    let temp = array[i];
    array[i]=array[end];
    array[end] = temp;

    return i;
}
