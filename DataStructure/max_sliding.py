# python3

from collections import deque 
  
# A Deque (Double ended queue) based  
# method for printing maximum element  
# of all subarrays of size k  
def printMax(arr, n, k): 
      
    """ Create a Double Ended Queue, Qi that  
    will store indexes of array elements.  
    The queue will store indexes of useful  
    elements in every window and it will 
    maintain decreasing order of values from 
    front to rear in Qi, i.e., arr[Qi.front[]] 
    to arr[Qi.rear()] are sorted in decreasing 
    order"""
    Qi = deque() 
      
    # Process first k (or first window)  
    # elements of array 
    for i in range(k): 
        
        # For every element, the previous  
        # smaller elements are useless 
        # so remove them from Qi 
        while Qi and arr[i] >= arr[Qi[-1]] : 
            Qi.pop() 
          
        # Add new element at rear of queue 
        Qi.append(i); 
          
    # Process rest of the elements, i.e.  
    # from arr[k] to arr[n-1] 
    for i in range(k, n): 
          
        # The element at the front of the 
        # queue is the largest element of 
        # previous window, so print it 
        print(str(arr[Qi[0]]) + " ", end = "") 
          
        # Remove the elements which are  
        # out of this window 
        while Qi and Qi[0] <= i-k: 
              
            # remove from front of deque 
            Qi.popleft()  
          
        # Remove all elements smaller than 
        # the currently being added element  
        # (Remove useless elements) 
        while Qi and arr[i] >= arr[Qi[-1]] : 
            Qi.pop() 
          
        # Add current element at the rear of Qi 
        Qi.append(i) 
      
    # Print the maximum element of last window 
    print(str(arr[Qi[0]])) 
      


def max_sliding_window_naive(sequence, m):
    maximums = []
    for i in range(len(sequence) - m + 1):
        maximums.append(max(sequence[i:i + m]))

    return maximums

if __name__ == '__main__':
    n = int(input())
    input_sequence = [int(i) for i in input().split()]
    assert len(input_sequence) == n
    window_size = int(input())
    printMax(input_sequence, len(input_sequence), window_size)

