 

Node *firstNode(Node *head)
{
	if (head == NULL)
	{
		// Empty linked list.
		return NULL;
	}

	// Slow Pointer - This will be incremented by 1 Nodes
	Node *slow = head;

	// Fast Pointer - This will be incremented by 2 Nodes
	Node *fast = head;

	do
	{
		if (fast && fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			// Fast pointer reached the end of the list.
			return NULL;
		}

		slow = slow->next;
	} while (fast != slow);

	slow = head;

	// To track the position of node.
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
