class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        // Initialize character counts
        vector<long long> mp(26, 0);
        for(char i: s) mp[i-'a']++;
        
        // Perform t transformations
        for(int i = 0; i < t; i++) {
            vector<long long> newMp(26, 0);
            
            // Process each character
            for(int j = 0; j < 26; j++) {
                if(mp[j] == 0) continue;
                
                if(j + 1 < 26) {
                    // Non-'z' character becomes next letter
                    newMp[j + 1] = (newMp[j + 1] + mp[j]) % mod;
                } else {
                    // 'z' becomes "ab"
                    newMp[0] = (newMp[0] + mp[j]) % mod;
                    newMp[1] = (newMp[1] + mp[j]) % mod;
                }
            }
            
            // Update counts for next iteration
            mp = newMp;
        }
        
        // Sum all character counts
        long long cnt = 0;
        for(int i = 0; i < 26; i++) {
            cnt = (cnt + mp[i]) % mod;
        }
        
        return cnt;
    }
};
