class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int,int>ump;
        ump[0]++;
        int total=0,count=0;
        for(string s:arr)
        {
            for(char c:s)
            {
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    total++;
                else    total--;
            }
            count+=ump[total];
            ump[total]++;
        }
        return count;
    }
};
