class Solution {
    Node* reverse(Node* head){
        Node *prev = nullptr;
        Node *curr = head;
        Node *nextTemp = nullptr;
        
        while (curr != nullptr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        int n=0;
        Node* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        int k=ceil(n/2.0);
        temp=head;
        while(k--)  temp=temp->next;
        temp=reverse(temp);
        
        while(head && temp){
            if(temp->data!=head->data)  return false;
            temp=temp->next;
            head=head->next;
        }
        return true;
    }
};
