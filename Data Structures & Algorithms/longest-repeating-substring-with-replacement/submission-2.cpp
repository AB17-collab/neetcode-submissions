class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> ump;
        int left = 0;
        int n = s.size();
        int maxFreq = 0;
        int res = 0;
        for(int right = 0;right<n;right++){
            ump[s[right]]++;
            maxFreq = max(maxFreq,ump[s[right]]);
            if((right-left+1)-maxFreq > k){
                ump[s[left]]--;
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};
