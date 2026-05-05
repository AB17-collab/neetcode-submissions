class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> ump;
        int n = s.size();
        int i = -1;
        int j = -1;
        int res = 0;
        while(true){
            //acquire
            bool f1 = false;
            bool f2 = false;
            while(i<n-1){
                f1 = true;
                i++;
                if(ump.find(s[i])==ump.end()){
                    ump[s[i]] = 1;
                }
                else{
                    ump[s[i]]++;
                }
                if(ump[s[i]]==2)
                    break;
                else{
                    res = max(res,i-j);
                }
            }
            while(j<i){
                f2 = true;
                j++;
                ump[s[j]]--;
                if(ump[s[j]]==1)
                    break;
            }

            if(!f1 && !f2)
                break;
        }
        return res;
    }
};
