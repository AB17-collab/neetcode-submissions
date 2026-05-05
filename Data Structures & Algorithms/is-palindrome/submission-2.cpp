class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        string s2=s;
        int i = 0,j=s2.size()-1;
        while(i<j){
            if(!isalnum(s2[i])){
                i++;
                continue;
            }
            if(!isalnum(s2[j])){
                j--;
                continue;
            }
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};
