class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // created a 2D array of size m+1 * n+1, to store the edit distances.
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // the first row and columns are filled such that if one of the word gets empty then we return the rem length of the other word {basically stored valued according to the index(1) values of the characters}->
        for(int i = 0; i<m+1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j<n+1; j++){
            dp[0][j] = j;
        }
        // loop through the 2D array->
        // if the characters of both strings same move on to next char and store that particular cell with the same no. of ops in the previous diagonal cell, ELSE 3 possibilities and we take the min of them->
        // 1) dp[i-1][j] -> if we delete the char of word1
        // 2) dp[i][j-1] -> if we add a char to word1
        // 3) dp[i-1][j-1] -> if we replace the current element in word1 with suitable char.
        // extra add one since we performed the ops and the called the next possibility.
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        // return the last cell of the grid which is the ans.
        return dp[m][n];
    }
};
