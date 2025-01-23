// problem -> https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

class Solution {
    
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* start=nullptr;
        Node* last;
        Node* p=head;
        unordered_map<Node*,Node*>ump;
        while(p)
        {
            Node* temp=new Node(p->data);
            ump[p]=temp;
            if(!start)  start=temp;
            else    last->next=temp;
            last=temp;
            p=p->next;
        }
        last=start;
        p=head;
        
        while(last)
        {
            if(p->random)
            {
                if(ump[p->random])
                {
                    last->random=ump[p->random];
                }
                else
                {
                    Node* temp=new Node(p->random->data);
                    last->random=temp;
                    ump[p->random]=temp;
                }
            }
            else
            {
                last->random=nullptr;
            }
            last=last->next;
            p=p->next;
        }
        return start;
    }
};
