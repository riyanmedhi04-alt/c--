class Solution {
public:
    // will do it using memoization.
    // created a lcs function->
    int lcs(int m, int n, string &text1, string &text2, vector<vector<int>> &memo){
        // if value of that particular positions in two texts already stored i.e. the value in memo not -1 then just return the value stored ->
        if(memo[m][n] != -1){
            return memo[m][n];
        }
        // ELSE->
        // if m == 0 or n== 0 which means one of the two string iterations is over then just store its value as 0.
        if(m == 0 || n == 0){
            memo[m][n] = 0;
        }else{
            // if two characters of the two strings match then just store the value as 1 + lcs(). else call for maximum lcs value of each string after deceament of 1 in each string iteration ... store the value.
            if(text1[m-1] == text2[n-1]){
                memo[m][n] = 1+lcs(m-1,n-1,text1,text2,memo);
            }else{
                memo[m][n] = max(lcs(m-1,n,text1,text2,memo),lcs(m,n-1,text1,text2,memo));
            }
        }
        // just return the value.
        return memo[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // created a 2D 
        vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
        return lcs(m,n,text1,text2,memo);
    }
};
