/*  
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where N is number of Nodes in Linked-List.
*/

bool detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    //  Slow Pointer - This will be incremented by 1 Nodes.
    Node *slow = head;
    //  Fast Pointer  - This will be incremented by 2 Nodes.
    Node *fast = head->next;
    
    while (slow != fast)
    {
        //  We reached the end of the List and haven't found any Cycle.
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    //  We found a Cycle.
    return true;
}
