 

Node *findMiddle(Node *head) 
{
    // If head is null just return null
    if (head == NULL) 
    {
        return head;
    }
  
    if (head->next == NULL) 
    {
        return head;
    }
    
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
