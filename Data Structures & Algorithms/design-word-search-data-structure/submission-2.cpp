class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int i = c - 'a';
            if(curr->children[i]==nullptr){
                curr->children[i] = new TrieNode;
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    bool searchHelper(string word,int index,TrieNode* curr){
        if(curr==nullptr)
            return false;
        
        if(index == word.length())
            return curr->endOfWord;
        
        char c = word[index];
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(curr->children[i]!=nullptr){
                    if(searchHelper(word,index+1,curr->children[i]))
                        return true;
                }
            }
            return false;
        }
        else{
            int i = c - 'a';
            if(curr->children[i]==nullptr)
                return false;
            else
                return searchHelper(word,index+1,curr->children[i]);
        }
    }
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};
