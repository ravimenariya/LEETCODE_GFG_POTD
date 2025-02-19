
// Problem -> https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        auto compare= [](Node* a,Node* b){ return a->data > b->data; };
        priority_queue<Node*,vector<Node*>,decltype(compare)>pq(compare);
        
        for(auto n:arr)
            pq.push(n);

        Node* head=pq.top();
        if(pq.top()->next)  pq.push(pq.top()->next);
        pq.pop();
        Node* temp=head;

        while(!pq.empty())
        {
            temp->next=pq.top();
            if(pq.top()->next)  pq.push(pq.top()->next);
            pq.pop();
            temp=temp->next;
        }
        return head;
    }
};
