
/*
problem -> https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

*/

class Solution {
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    
    void addnum(int n)
    {
        if(left.empty() || n<=left.top())    left.push(n);
        else    right.push(n);
        
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double median()
    {
        if(left.size()>right.size())    return left.top();
        return (left.top()+right.top())/2.0;
    }
    
    
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        vector<double>ans;
        for(int i:arr)
        {
            addnum(i);
            ans.push_back(median());
        }
        return ans;
    }
};
