/*
    Time complexity: O(Q*N)
    For each push operation O(N); O(1) for all other operations.

    Space complexity: O(N)

    where Q is the number of queries, N denotes the maximum number of elements in the queue.
*/

#include <queue>

class Stack {
   public:
    queue<int> *q1;

    // Constructor.
    Stack() {  
        q1 = new queue<int>();
    }

    int getSize() {
        // Return the size of the queue 'q1'.
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {
        // Get the size of the queue.
        int size = q1->size();  
        // Enqueue the  new data to the queue.
        q1->push(data);         

        // Make the new data front of the queue.
        for (int i = 0; i < size; i++)  
        {
            q1->push(q1->front());
            q1->pop();
        }
    }

    int pop() {
        // If empty, return -1.
        if (isEmpty()) {  
            return -1;
        }

        // Simply dequeue from the queue q1.
        int ans = q1->front();  
        q1->pop();
        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        int ans = q1->front();

        return ans;
    }
};
