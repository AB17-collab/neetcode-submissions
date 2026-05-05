class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        for(int i=0;i<n;i++){
            int len = strs[i].size();
            res += to_string(len)+"/:"+strs[i];
        }
        return res;
    }
    vector<string> decode(string s) {
        int k = s.size();
        int i = 0;
        vector<string> result;
        while(i<k){
            int j = 0;
            if(s[i]>='0'&&s[i]<='9'){
                while(s[i]>='0'&&s[i]<='9'){
                    j = j*10 + (s[i]-'0');
                    i++;
                }
            }
            i += 2;
            string temp = "";
            while(j>0){
                temp += s[i];
                j--;
                i++;
            }
            result.push_back(temp);
        }
        return result;
    }
};
