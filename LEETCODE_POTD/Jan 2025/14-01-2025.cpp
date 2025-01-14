class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans(A.size());
        unordered_map<int,int>ump1;
        unordered_map<int,int>ump2;
        ans[0]=(A[0]==B[0])?1:0;
        ump1[A[0]]++;
        ump2[B[0]]++;
        for(int i=1;i<A.size();i++)
        {
            int a=ans[i-1];
            ump1[A[i]]++;
            ump2[B[i]]++;
            if(ump2[A[i]])  a++;
            if(A[i]!=B[i] && ump1[B[i]])  a++;
            ans[i]=a;
        }
        return ans;
    }
};
