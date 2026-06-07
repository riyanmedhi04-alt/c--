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

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Trie();
        int m = dictionary.size();
        for(int i = 0; i<m; i++){
            insert(dictionary[i]);
        }
        string s = "";
        int sz = sentence.size();
        int start = 0, end = 0;

        for(int i = 0; i<sz; i++){
            if(sentence[i] == ' '){
                s += " ";
                continue;
            }
            if(i != 0 && i<=end){
                continue;
            }
            start = i;
            int curr = i;
            int n = 0;
            while(curr<sz && sentence[curr] != ' '){
                n++;
                if(curr +1 == sz-1){
                    n++;
                    break;
                }
                curr++;
            }
            end = n+start-1;
            string word = sentence.substr(start,n);
            bool done = false;

            Trie *now = root;
            for(int j = 0; j<n; j++){
                int idx = word[j] - 'a';
                if(now->child[idx] == NULL){
                    s += word;
                    done = true;
                    break;
                }
                now = now->child[idx];
                if(now->isEnd){
                    string word1 = word.substr(0, j+1);
                    s += word1;
                    done = true;
                    break;
                }

            }
            if(!done){
                s += word;
            }
            
        }
        return s;
    }
};
