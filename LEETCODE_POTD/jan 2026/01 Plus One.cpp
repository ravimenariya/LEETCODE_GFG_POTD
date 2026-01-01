class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1,i=digits.size()-1;
        while(carry && i>=0){
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
            i--;
        }
        if(carry)   digits.insert(digits.begin(),carry);
        return digits;
    }
};
