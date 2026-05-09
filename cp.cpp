#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i =0; i<n; i++){
            cin >> v[i];
        }
        unordered_set<long long> s;
        s.insert(0);
        bool isValid = false;
        long long b = 0;
        for(int i = 0; i<n; i++){
            if(i%2 == 0){
                b += -v[i];
            }else{
                b += v[i];
            }
            if(s.find(b) != s.end()){
                isValid = true;
                break;
            }
            s.insert(b);
        }
        if(isValid){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}