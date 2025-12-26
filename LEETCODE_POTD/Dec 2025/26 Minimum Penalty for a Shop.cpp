class Solution {
public:
    int bestClosingTime(string customers) {
        int n=0,y=0,j,penalty=INT_MAX;
        for(char&c:customers)   if(c=='Y')  y++;
        for(int i=0;i<customers.size();i++){
            if((n+y)<penalty){
                penalty=n+y;
                j=i;
            }
            if(customers[i]=='Y')   y--;
            else  n++;
        }
        if((n+y)<penalty)   return customers.size();
        return j;
    }
};
