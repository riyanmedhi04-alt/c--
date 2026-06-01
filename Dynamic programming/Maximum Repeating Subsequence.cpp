class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n1 = sequence.size();
        int n2 = word.size();
        // dp[i] -> number of consecutive copies of word ending at index i.
        vector<int> dp(n1+1);
        dp[0] = 0;
        for(int i = 1; i<=n1; i++){
            if(sequence[i-1] == word[n2-1] && i-n2 >= 0){
                string s1 = sequence.substr((i-n2), n2);
                // if we find a i where sequence[i] == last char of word then we will see if a slice of string from sequence ending at i and length as same as word is same as word if its same
                // then dp[i] = 1 + dp[i-n2] -> which is basically the stored value for a char at (len of word) to the left of i.
                if(s1 == word){
                    dp[i] = 1+dp[i-n2];
                }else{
                    // else dp[i] = 0.
                    dp[i] = 0;
                }
            }else{
                dp[i] = 0;
            }
        }
        // look for the maximum dp 
        int ans = 0;
        for(int i = 0; i<=n1; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
