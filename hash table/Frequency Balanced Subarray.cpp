class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        for(int i = 0; i<n; i++){
            unordered_map<int,int> m; // to store the freq of the values
            unordered_map<int,int> m1; // to store the freq of the freq of the values !!
            for(int j = i; j<n; j++){
                int val = nums[j];
                int old_freq = m[val];
                int new_freq = old_freq +1;
                if(old_freq > 0){
                    m1[old_freq]--;
                    if(m1[old_freq] == 0){
                        m1.erase(old_freq); // erase this if one of the freq is ended to keep m1 uptodate.
                    }
                }
                m[val] = new_freq;
                m1[new_freq]++;
                if(m1.size() == 1){
                    if(m.size() == 1){
                        len = max(len, j-i+1);
                    }
                }else if(m1.size() == 2){
                    auto it = m1.begin();
                    int a = it->first;
                    int b = (++it)->first;
                    if(a == 2*b || b == 2*a){
                        len = max(len, j-i+1);
                    }
                }else{
                    continue;
                }
        
            }
        }
        return len;
    }
};
