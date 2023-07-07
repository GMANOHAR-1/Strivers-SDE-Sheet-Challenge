/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    where N is the number of elements in the array.
*/

#include <iostream>
#include <vector>
#include <queue>

void findMedian(int arr[], int n)
{
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> higherHalf;

    int median;

    // The variable size is the size of the current stream
    for(int size=1; size<=n; size++)
    {
        if(!lowerHalf.empty() && lowerHalf.top() > arr[size-1])
        {	
            // Insert ARR[size-1] in lowerHalf
            lowerHalf.push(arr[size-1]);

            if(lowerHalf.size() > higherHalf.size() + 1)
            {	
                // Insert the top element of lowerHalf into higherHalf
                higherHalf.push(lowerHalf.top());
                lowerHalf.pop();
            }
        }
        else
        {
            higherHalf.push(arr[size-1]);

            if(higherHalf.size() > lowerHalf.size() + 1)
            {	
                // Insert the top element of higherHalf into lowerHalf
                lowerHalf.push(higherHalf.top());
                higherHalf.pop();
            }
        }
		
        // Check if size is odd
        if(size%2 == 1)
        {	
            if(higherHalf.size() > lowerHalf.size())
            {
                median = higherHalf.top();
            }
            else
            {
                median = lowerHalf.top();
            }
        }
        else
        {
            median = (lowerHalf.top() + higherHalf.top())/2;
        }
		
        // Print the variable median
        cout << median << " ";
    }
}

