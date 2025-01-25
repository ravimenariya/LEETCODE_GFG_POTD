
// problem -> https://geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node* fast = head;
        Node* slow=head;
        int f=1;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)  
            {
                f=0;
                break;
            }
        }
        if(f)   return nullptr;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
