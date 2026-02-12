function stalinSort(arr)
{
    if(arr.length === 0) {return [];}

    let sorted_list = [arr[0]];
    
    for(let i = 1; i < arr.length; i++)
    {
        if(arr[i] >= sorted_list[sorted_list.length - 1])
        {
            sorted_list.push(arr[i]);
        }
    }
    return sorted_list;
}