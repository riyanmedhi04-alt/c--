class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int,vector<long long>> m;
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        for(auto &x : m){
            vector<long long> v = x.second;
            int m = v.size();
            long long pref = 0, suff = 0;
            vector<long long> prefix(m), sufix(m);
            for(int i = 0; i<m; i++){
                prefix[i] = (v[i]*i - pref);
                pref += v[i];
            }
            for(int i = m-1; i>= 0; i--){
                sufix[i] = suff - v[i]*(m-1-i);
                suff += v[i];
            }
            for(int i = 0; i<m; i++){
                ans[v[i]] = prefix[i] + sufix[i];
            }
        }
        return ans;
    }
};
