 

LinkedListNode<int> *reverse(LinkedListNode<int> *head) {

    // Creating node for remembering previous node in Linked List.
    LinkedListNode<int> *reverseHead = NULL;

    // Creating temporory node.
    LinkedListNode<int> *current = head;

    while (current != NULL) {

        LinkedListNode<int> *currentNext = current->next;
        current->next = reverseHead;
        reverseHead = current;
        current = currentNext;

    }

    // Return reverse Linked List.
    return reverseHead;

}

bool isPalindrome(LinkedListNode<int> *head) {

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *prev = head;

    // Find the middle node using TORTOISE-HARE-APPROACH.
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    /*
        Fast pointer would become NULL when there are even elements in the list and
        not NULL for odd elements. We need to skip the middle node for odd case.
    */
    if (fast != NULL) {
        slow = slow->next;
    }

    // When there is only one node in given Linked List.
    if (slow == NULL) {
        return true;
    }

    // Dividing Linked LIst in two part by pointing prev next to NULL.
    prev->next = NULL;

    // Now reverse the second half.
    LinkedListNode<int> *reverseHead = reverse(slow);

    // Iterate through both LinkedList and then compare it.
    while (head != NULL) {

        if (head->data != reverseHead->data) {
            return false;
        }
        reverseHead = reverseHead->next;
        head = head->next;

    }

    return true;

}
