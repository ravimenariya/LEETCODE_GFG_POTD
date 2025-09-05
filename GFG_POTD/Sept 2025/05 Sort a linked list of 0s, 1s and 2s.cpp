class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        Node *zeroD = new Node(0), *oneD = new Node(0), *twoD = new Node(0);
        Node *zero = zeroD, *one = oneD, *two = twoD;

        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = oneD->next ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        Node* newHead = zeroD->next;

        return newHead;
    }
};
