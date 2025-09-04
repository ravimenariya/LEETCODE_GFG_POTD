class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* temp=head;
        Node* prevtemphead=nullptr;
        head=nullptr;
        while(temp)
        {
            int t=k;
            Node* temphead=temp;
            Node* prev=nullptr;
            while(temp && t--)
            {
                Node* next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
            }
            if(!head)   head=prev;
            else  {
                prevtemphead->next=prev;
            }
            prevtemphead=temphead;
        }
        return head;
    }
};
