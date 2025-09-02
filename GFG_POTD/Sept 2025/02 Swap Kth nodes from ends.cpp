/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* swapKth(Node* head, int k) {
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        
        if (k > n) return head;
        if (2 * k - 1 == n) return head;
        
        Node* front_prev = nullptr;
        Node* front = head;
        for (int i = 1; i < k; i++) {
            front_prev = front;
            front = front->next;
        }
        
        Node* back_prev = nullptr;
        Node* back = head;
        for (int i = 1; i < n - k + 1; i++) {
            back_prev = back;
            back = back->next;
        }
        
        if (front_prev) {
            front_prev->next = back;
        } else {
            head = back;
        }
        
        if (back_prev) {
            back_prev->next = front;
        } else {
            head = front;
        }
        
        Node* temp_next = front->next;
        front->next = back->next;
        back->next = temp_next;
        
        return head;
    }
};
