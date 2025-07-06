class FindSumPairs {
    vector<int>n1,n2;
    unordered_map<int,int>freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for(int i:nums2)    freq[i]++;
    }
    
    void add(int index, int val) {
        freq[n2[index]]--;
        n2[index]+=val;
        freq[n2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i:n1)
        {
            int f=tot-i;
            ans+=freq[f];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
