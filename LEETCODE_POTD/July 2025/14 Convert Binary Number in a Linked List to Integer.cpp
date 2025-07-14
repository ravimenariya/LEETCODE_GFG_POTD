class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s="";
        while(head)
        {
            if(head->val==1)    s+='1';
            else                s+='0';
            head=head->next;
        }
        int num=0,n=s.size()-1;
        for(int i=n;i>=0;i--)  if(s[i]=='1')  num+=(1<<(n-i));
        return num;
    }
};
