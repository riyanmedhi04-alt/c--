class Solution {
public:
    struct Trie{
    bool isEnd;
    Trie *child[26];
    Trie(){
        isEnd = false;
        for(int i = 0; i<26; i++){
            child[i] = NULL;
        }
    }
    };
    Trie *root;
    void insert(string word){
        Trie *curr = root;
        for(int i = 0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if(curr->child[idx] == NULL){
                curr->child[idx] = new Trie();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
    bool search(string word){
        Trie *curr = root;
        for(int i = 0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if(curr->child[idx] == NULL){
                return false;
            }
            curr = curr->child[idx];
        }
        return curr->isEnd;
    }
    bool dfs(int i, Trie *curr, int cnt, string word){
        if(i == word.size()){
            if(cnt <= 2 && curr->isEnd){
                return true;
            }else{
                return false;
            }
        }
        if(cnt>2){
            return false;
        }
        int idx = word[i] - 'a';
            for(int c = 0; c<26; c++){
                if(c == idx){
                    if(curr->child[idx]){
                        if(dfs(i+1, curr->child[idx],cnt,word)){
                            return true;
                        }
                    }else{
                        continue;
                    }
                }
                if(curr->child[c]){
                    if (dfs(i+1, curr->child[c], cnt+1, word)){
                        return true;
                    }
                }
            }
            return false;
        
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        root = new Trie();
        for(int i = 0; i<dictionary.size(); i++){
            insert(dictionary[i]);
        }
        vector<string> v;
        int n = queries.size();
        for(int i = 0; i<n; i++){
            int sz = queries[i].size();
            string word = queries[i];
            Trie *curr = root;
            if(dfs(0, curr, 0, word)){
                v.push_back(word);
            }
        }
        return v;
    }
};
