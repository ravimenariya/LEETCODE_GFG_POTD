class Solution {
  public:
     int maxSubarrayXOR(vector<int>& arr, int k) {
      int answer=INT_MIN, first=0, second=0, temp=0;
      
      while(second<arr.size())
      {   
         temp= temp^arr[second];
         
         if(second-first+1 ==k)
         {
            answer = max(temp,answer); 
             temp= temp^arr[first];
             first++;
         }
         second++; 
      }
      return answer;
        
    }
};
