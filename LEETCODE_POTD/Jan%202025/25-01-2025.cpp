// problem -> https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/submissions/1520334121/?envType=daily-question&envId=2025-01-25


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        vector<pair<int,int>>nums;
        int n=arr.size(),group=0;
        for(int i=0;i<n;i++)    nums.push_back({arr[i],i});
        sort(nums.begin(),nums.end());
        cout<<endl;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>graph;
        unordered_map<int,int>gp;
        int i=0;
        while(i<n)
        {
            if(!gp[nums[i].second])  
            {
                gp[nums[i].second]=++group;
                graph[group].push(nums[i].first);
            }
            int currgp=gp[nums[i].second];
            int prev_val=nums[i].first;
            int prev_idx=nums[i].second;
            i++;
            while(i<n)
            {
                if(abs(prev_val-nums[i].first)<=limit && !gp[nums[i].second])
                {
                    gp[nums[i].second]=currgp;
                    graph[currgp].push(nums[i].first);
                    prev_val=nums[i].first;
                    prev_idx=nums[i].second;
                    i++;
                }
                else    break;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            int currgp=gp[i];
            arr[i]=graph[currgp].top();
            graph[currgp].pop();
        }
        return arr;
    }
};
