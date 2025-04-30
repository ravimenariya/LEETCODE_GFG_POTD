class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* fast=head;
        Node* slow=head;
        bool loop=false;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                loop=true;
                break;
            }
        }
        if(!loop)   return 0;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        int ans=1;
        fast=fast->next;
        while(fast!=slow)
        {
            ans++;
            fast=fast->next;
        }
        return ans;
    }
};
