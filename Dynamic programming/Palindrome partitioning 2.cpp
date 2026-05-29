class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        // ----------------------------------------------------
        // pal[i][j] = true if substring s[i...j] is a palindrome
        // ----------------------------------------------------
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Gap DP for palindrome preprocessing
        //
        // gap = j - i
        //
        // gap = 0 => length 1 substrings
        // gap = 1 => length 2 substrings
        // gap = 2 => length 3 substrings
        // ...
        //
        // We process smaller substrings first because
        // pal[i][j] depends on pal[i+1][j-1].
        //
        for(int gap = 0; gap < n; gap++) {

            for(int i = 0; i + gap < n; i++) {

                int j = i + gap;

                // ----------------------------
                // Length = 1
                // Every single character
                // is a palindrome.
                // ----------------------------
                if(gap == 0) {

                    pal[i][j] = true;

                }

                // ----------------------------
                // Length = 2
                //
                // "aa" -> palindrome
                // "ab" -> not palindrome
                // ----------------------------
                else if(gap == 1) {

                    pal[i][j] = (s[i] == s[j]);

                }

                // ----------------------------
                // Length >= 3
                //
                // Example:
                // "racecar"
                //
                // It is palindrome iff:
                //
                // 1) First and last characters match
                // 2) Inside substring is palindrome
                //
                // s[i] == s[j]
                // &&
                // pal[i+1][j-1]
                // ----------------------------
                else {

                    pal[i][j] =
                        (s[i] == s[j] && pal[i+1][j-1]);

                }
            }
        }


        // ----------------------------------------------------
        // cut[i]
        //
        // Minimum cuts needed for prefix:
        //
        // s[0...i]
        //
        // Example:
        //
        // s = "aab"
        //
        // cut[0] = 0   ("a")
        // cut[1] = 0   ("aa")
        // cut[2] = 1   ("aa|b")
        // ----------------------------------------------------
        vector<int> cut(n);

        for(int i = 0; i < n; i++) {

            // ------------------------------------
            // If whole prefix s[0...i]
            // is already a palindrome,
            // no cuts are needed.
            // ------------------------------------
            if(pal[0][i]) {

                cut[i] = 0;
                continue;

            }

            // Start with a very large answer.
            cut[i] = INT_MAX;

            // ------------------------------------
            // Try every possible starting point
            // of the LAST palindrome block.
            //
            // Suppose:
            //
            // s[0...j-1] | s[j...i]
            //
            // If s[j...i] is palindrome,
            // then:
            //
            // answer =
            // cuts for left part
            // +
            // one new cut
            //
            // cut[j-1] + 1
            // ------------------------------------
            for(int j = 1; j <= i; j++) {

                if(pal[j][i]) {

                    cut[i] =
                        min(cut[i],
                            cut[j-1] + 1);

                }
            }
        }

        return cut[n-1];
    }
};
