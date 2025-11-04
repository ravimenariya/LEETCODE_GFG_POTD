class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int>freq;
        set<pair<int,int>>st;// freq,num
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<k-1;i++)
        {
            st.erase({freq[nums[i]],nums[i]});
            freq[nums[i]]++;
            st.insert({freq[nums[i]],nums[i]});
        }

        for(int i=k-1;i<n;i++)
        {
            st.erase({freq[nums[i]],nums[i]});
            freq[nums[i]]++;
            st.insert({freq[nums[i]],nums[i]});

            int sum=0,j=0;
            auto it=st.rbegin();
            while(j<x && it!=st.rend())
            {
                sum+=(int)(*it).first*(int)(*it).second;
                it++;
                j++;
            }
            
            ans.push_back(sum);
            st.erase({freq[nums[i-(k-1)]],nums[i-(k-1)]});
            freq[nums[i-(k-1)]]--;
            if(freq[nums[i-(k-1)]])
                st.insert({freq[nums[i-(k-1)]],nums[i-(k-1)]});
        }
        return ans;
    }
};
