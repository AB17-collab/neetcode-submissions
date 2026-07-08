class TrieNode {
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode() {
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(string j,int i){
        TrieNode* curr = this;
        curr->refs++;
        for(char c: j){
            int ind = c - 'a';
            if(curr->children[ind]==nullptr){
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
            curr->refs++;
        }
        curr->idx = i;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++){
            root->addWord(words[i],i);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,root,words,i,j,res);
            }
        }

        return res;
    }
    void dfs(vector<vector<char>> &board,TrieNode* node,vector<string>& words,int r,int c,vector<string>& ans){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]=='*' || !node->children[board[r][c]-'a'])
            return;
        
        char temp = board[r][c];
        board[r][c] = '*';
        TrieNode* prev = node;
        node = node->children[temp-'a'];
        if(node->idx!=-1){
            ans.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if(!node->refs){
                prev->children[temp-'a'] = nullptr;
                board[r][c] = temp;
                return;
            }
        }

        dfs(board,node,words,r+1,c,ans);
        dfs(board,node,words,r-1,c,ans);
        dfs(board,node,words,r,c+1,ans);
        dfs(board,node,words,r,c-1,ans);
        
        board[r][c] = temp;
    }
};
