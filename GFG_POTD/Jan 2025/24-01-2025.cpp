// problem -> https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)  return true;
        }
        return false;
    }
};
