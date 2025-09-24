class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        long long numerator=num,denominator=deno;
        long long quotient=numerator/denominator;
        long long remainder=numerator%denominator;
        string ans=to_string(quotient);
        if(!remainder )  return ans;
        if(denominator<0)   {
            denominator*=(-1);
            if(!quotient && remainder>=0 )   ans="-"+ans;
        }
        
        if(remainder<0) {
            remainder*=(-1);
            if(!quotient && deno>=0)   ans="-"+ans;
        }
        ans+=".";

        int i=1;
        string after="";
        unordered_map<long long,int>ump;
        while(remainder)
        {
            if(ump[remainder])
            {
                int j=0;
                while(j<(ump[remainder]-1)) 
                    ans+=after[j++];
                ans+="(";
                while(j<after.size()) 
                    ans+=after[j++];
                ans+=")";

                return ans;
            }
            ump[remainder]=i;
            remainder*=10;
            while(remainder<denominator)    
            {
                remainder*=10;
                after+="0";
                i++;
            }
            after+=to_string(remainder/denominator);
            remainder%=denominator;
            i++;
        }

        return ans+after;
    }
};
