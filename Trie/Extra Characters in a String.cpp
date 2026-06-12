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
    int minExtraChar(string s, vector<string>& dictionary) {
        root = new Trie();
        int n = dictionary.size();
        for(int i = 0; i<n; i++){
            insert(dictionary[i]);
        }
        int sz = s.size();
        vector<int> dp(sz+1, 0);
        // dp[i] -> the min used characters upto i
        for(int i = sz-1; i>=0; i--){
            dp[i] = 1+dp[i+1];
            Trie *curr = root;
            for(int j = i; j<sz; j++){
                int idx = s[j] - 'a';
                if(curr->child[idx] == NULL){
                    break;
                }
                curr = curr->child[idx];
                if(curr->isEnd){
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
