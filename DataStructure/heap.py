# python3

def heapify(swaps,arr, n, i): 
  
    largest = i; # Initialize largest as root 
    l = 2 * i + 1; # left = 2*i + 1 
    r = 2 * i + 2; # right = 2*i + 2 
  
    # If left child is larger than root 
    if l < n and arr[l] < arr[largest]: 
        largest = l; 
  
    # If right child is larger than largest so far 
    if r < n and arr[r] < arr[largest]: 
        largest = r; 
  
    # If largest is not root 
    if largest != i: 
        swaps.append((i,largest))
        arr[i], arr[largest] = arr[largest], arr[i]; 
  
        # Recursively heapify the affected sub-tree 
        heapify(swaps,arr, n, largest);

def buildHeap(arr, n): 
  
    # Index of last non-leaf node 
    startIdx = n // 2 - 1; 
    swaps = []
  
    # Perform reverse level order traversal 
    # from last non-leaf node and heapify 
    # each node 
    for i in range(startIdx, -1, -1): 
        heapify(swaps,arr, n, i); 
    return swaps



def build_heap(data):
    """Build a heap from ``data`` inplace.

    Returns a sequence of swaps performed by the algorithm.
    """
    # The following naive implementation just sorts the given sequence
    # using selection sort algorithm and saves the resulting sequence
    # of swaps. This turns the given array into a heap, but in the worst
    # case gives a quadratic number of swaps.
    #
    # TODO: replace by a more efficient implementation
    swaps = []
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            if data[i] > data[j]:
                swaps.append((i, j))
                data[i], data[j] = data[j], data[i]
    return swaps


def main():
    n = int(input())
    data = list(map(int, input().split()))
    assert len(data) == n

    swaps = buildHeap(data, n)
    #print(data)
    


    print(len(swaps))
    for i, j in swaps:
        print(i, j)


if __name__ == "__main__":
    main()
