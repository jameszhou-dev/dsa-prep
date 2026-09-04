def quickSort(arr, start, end):
    if (start < end):
        partition_idx = partition(arr, start, end)
        quickSort(arr, partition_idx+1, end);
        quickSort(arr, start, partition_idx-1)

def partition(arr, start, end):
    i = start-1
    pivot = arr[end]
    for j in range(start, end):
        if (arr[j]<=pivot):
            i+=1
            arr[i], arr[j] = arr[j], arr[i]
    i+=1
    arr[i], arr[end] = arr[end], arr[i]
    return i
