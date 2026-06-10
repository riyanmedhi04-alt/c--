class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(string s, int start){
        if(start == s.size()){
            ans.push_back(v);
            return;
        }
        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){
                v.push_back(s.substr(start, end-start+1));
                dfs(s, end+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
