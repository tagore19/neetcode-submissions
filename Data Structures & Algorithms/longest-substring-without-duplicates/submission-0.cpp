class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxL = 0;
        int  j = 0;
        unordered_set<char> mp;
        for(int i = 0;i<n;i++){
            
            while(mp.count(s[i])){
                mp.erase(s[j]);
                j++;
            }
            mp.insert(s[i]);

            maxL = max(maxL,i-j+1);
        }
        return maxL;
        
    }
};
