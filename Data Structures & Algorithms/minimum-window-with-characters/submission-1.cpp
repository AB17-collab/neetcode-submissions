class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tgtFreq;
        for(int i=0;i<t.size();i++){
            tgtFreq[t[i]]++;
        }
        int left = 0,right = 0;
        int formed = 0;
        unordered_map<char,int> windowFreq;
        int n = s.size();
        int k = tgtFreq.size();
        int minLen = INT_MAX;
        int minLeft = 0;
        while(right<n){
            windowFreq[s[right]]++;

            if(tgtFreq.count(s[right]) && (tgtFreq[s[right]]==windowFreq[s[right]])){
                formed++;
            }

            while(left<=right && formed==k){
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    minLeft = left;
                }

                windowFreq[s[left]]--;
                
                if(tgtFreq.count(s[left]) && windowFreq[s[left]]<tgtFreq[s[left]])
                    formed--;
                
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?"":s.substr(minLeft,minLen);
    }
};
