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
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        int m = wordDict.size();
        for(int i = 0; i<m; i++){
            insert(wordDict[i]);
        }
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        int start = 0;
        for(int i = 0; i<n; i++){
            if(!dp[i]){
                continue;
            }
            Trie *curr = root;
            for(int j = i; j<n; j++){
                int idx = s[j] - 'a';
                if(curr->child[idx] == NULL){
                    break;
                }
                curr = curr->child[idx];
                if(curr->isEnd){
                    dp[j+1] = true;
                }
            }
        }
        return dp[n];
    }
};
