class Solution {
  public:
    Node* mergeSort(Node* head) {
        vector<int>arr;
        Node* temp=head;
        while(temp)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        
        head=nullptr;
        for(int i:arr)
        {
            Node* p=new Node(i);
            if(!head)   head=p;
            else        temp->next=p;
            temp=p;
        }
        return head;
    }
};
