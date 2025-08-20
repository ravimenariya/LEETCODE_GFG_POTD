class Solution {
  public:
    int getLPSLength(string str) {
        // Your code goes here
        int n=str.size(),j=0;
        vector<int> pi(n,0);

        for(int i=1;i<n;i++){
            while(j>0 && str[j]!=str[i])
                j=pi[j-1];
                
            if(str[i]==str[j])    j++;
            
            pi[i]=j;
        }
        return pi[n-1];
    }
};
