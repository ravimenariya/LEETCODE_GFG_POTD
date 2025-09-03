class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* prev=head;
        while(head)
        {
            Node* next=head->next;
            head->next=head->prev;
            head->prev=next;
            prev=head;
            head=next;
        }
        return prev;
    }
};
