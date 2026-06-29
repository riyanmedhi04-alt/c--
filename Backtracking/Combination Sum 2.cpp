class Solution {
public:
    void solve(vector<vector<int>> &v, vector<int> x, vector<int> &candidates, int sum, int i, int target){
        if(sum == target){
            v.push_back(x);
            return;
        }
        if(i == candidates.size() || sum > target){
            return;
        }
        if(sum + candidates[i] <= target){
            x.push_back(candidates[i]);
            solve(v,x,candidates,sum+candidates[i], i+1, target);
            x.pop_back();
        }
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        solve(v,x,candidates,sum,i+1,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> x;
        sort(candidates.begin(),candidates.end());
        solve(v,x,candidates,0,0,target);
        return v;
    }
};
