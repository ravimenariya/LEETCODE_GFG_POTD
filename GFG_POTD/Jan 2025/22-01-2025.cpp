class Solution {
    Node* reverse(Node* head)
    {
        Node* p=head->next;
        head->next=nullptr;
        while(p)
        {
            Node* temp=head;
            head=p;
            p=p->next;
            head->next=temp;
        }
        return head;
    }
    
  public:
    Node* addTwoLists(Node* l1, Node* l2) {
        int carry=0;
        Node *start = nullptr;
        Node *temp2 = nullptr;
        
        // revrse linked list
        l1=reverse(l1);
        l2=reverse(l2);
        
        while(l1!=nullptr || l2!=nullptr)
        {
            int sum=(l1 ? l1->data :0) + (l2? l2->data :0) +carry;
             
             Node *temp=new Node(sum%10);
             if(start==nullptr)
                start=temp;
            else
                temp2->next=temp;
            
            carry=sum/10;
            temp2=temp;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if(carry)
        {
            Node *temp=new Node(carry);
            temp2->next=temp;
        }
        start=reverse(start);
        while(start->data==0)
        {
            start=start->next;
        }
        return start;
    }
};
