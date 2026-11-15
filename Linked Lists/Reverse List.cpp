
class Solution {
	public:
	Node* reverseList(Node* head) {
		Node*previous = NULL;
		Node*current = head;
		Node*nextnode = NULL;
		
		while (current != NULL)
			{
			nextnode = current->next;
			current->next = previous;
			previous = current;
			current = nextnode;
		}
		
		head = previous;
		
		return head;
		
	}
};
