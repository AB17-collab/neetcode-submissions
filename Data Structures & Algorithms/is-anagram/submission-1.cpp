class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            if(ump.find(t[j])!=ump.end())
                ump[t[j]]--;
            else{
                ump[t[j]]++;
            }
        }
        for(auto k: ump){
            if(k.second!=0)
                return false;
        }
        return true;
    }
};
