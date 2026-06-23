class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        map<char,int> freq;
        for(int i = 0; i<m; i++){
            freq[tasks[i]]++;
        }
        int fmax = 0;
        char ch;
        for(auto x : freq){
            fmax = max(fmax, x.second);
            if(fmax == x.second){
                ch = x.first;
            }
        }
        int gaps = fmax-1;
        int emp_slots = gaps*n;
        for(auto x : freq){
            if(x.first == ch){
                continue;
            }
            if(x.second < fmax){
                emp_slots -= x.second;
            }else{
                emp_slots -= x.second-1;
            }
        }
        int idles = 0;
        if(emp_slots < 0){
            idles = 0;
        }else{
            idles = emp_slots;
        }
        return m+idles;
    }
};
