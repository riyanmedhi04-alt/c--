class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        
        ugly.push_back(1);

        int p2 = 0, p3 = 0, p5 = 0;

        for(int i = 1; i < n; i++) {

            int next2 = ugly[p2] * 2;
            int next3 = ugly[p3] * 3;
            int next5 = ugly[p5] * 5;

            int u = min(next2, min(next3, next5));

            ugly.push_back(u);

            if(u == next2) p2++;
            if(u == next3) p3++;
            if(u == next5) p5++;
        }

        return ugly[n - 1];
    }
};
