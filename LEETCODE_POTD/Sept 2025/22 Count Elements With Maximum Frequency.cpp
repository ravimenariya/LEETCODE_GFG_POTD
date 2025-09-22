class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int max_freq=0,count=0;
        for(int i:nums)
        {
            freq[i]++;
            if(freq[i]>max_freq)
            {
                max_freq=freq[i];
                count=1;
            }
            else if(freq[i]==max_freq)  count++;
        }
        return count*max_freq;
    }
};
