class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>v1(n,0);
        vector<int>v2(n,0);
        int count=(boxes[0]=='1')?1:0;
        for(int i=1;i<n;i++)
        {
            v1[i]=v1[i-1]+count;
            if(boxes[i]=='1')   count++;
        }
        count=(boxes[n-1]=='1')?1:0;
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=v2[i+1]+count;
            if(boxes[i]=='1')   count++;
        }
        for(int i=0;i<n;i++)
            v1[i]+=v2[i];
        return v1;
    }
};
