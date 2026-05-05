class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> temp(strs.size());
        unordered_map<string,vector<string>> ump;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            temp[i] = s;
            if(ump.find(temp[i])!=ump.end()){
                ump[temp[i]].push_back(strs[i]);
            } 
            else
                ump[temp[i]] = {strs[i]};
        }
        for(auto k:ump){
            result.push_back(k.second);
        }
        return result;
    }
};
