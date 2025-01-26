
// problem -> https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
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
        if(f)   return ;
        fast=head;
        
        if(slow==fast)
        {
            while(slow->next!=fast)
            {
                slow=slow->next;
            }
            slow->next=nullptr;
            return;
        }
        
        Node* prev=slow;
        while(fast!=slow)
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=nullptr;
        return;
    }
};
