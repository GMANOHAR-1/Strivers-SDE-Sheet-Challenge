/*
    Time Complexity: O(n * n * k)
    Space complexity: O(n * k)

    Where 'n' denotes the size of the linked list and 'k' is the average number of child nodes for each of the n nodes.
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *first, Node *second)
{

    // If the first is NULL return second
    if (first == NULL)
    {
        second->next = nullptr;
        return second;
    }

    // If the second is NULL return first
    if (second == NULL)
    {
        first->next = nullptr;
        return first;
    }

    Node *merged = NULL;

    if (first->data < second->data)
    {
        merged = first;
        merged->child = merge(first->child, second);
    }
    else
    {
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recur on next node
    head->next = flattenLinkedList(head->next);

    // Merge with the current
    head = merge(head, head->next);

    return head;
}
