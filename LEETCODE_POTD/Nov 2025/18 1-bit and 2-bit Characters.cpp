class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        for(int i=0;i<n;i++)
        {
            if(bits[i]==1)
            {
                if((i+2)>=n) return false;
                i++;
            }
        }
        return true;
    }
};
