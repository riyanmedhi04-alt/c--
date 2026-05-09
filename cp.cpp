///*
 * Codeforces 1915E - Alternating Subarray Balance
 *
 * PROBLEM SUMMARY:
 * Given an array, find if any subarray [l, r] exists where the sum of
 * elements at odd positions (within the subarray) equals the sum of
 * elements at even positions (within the subarray).
 *
 * KEY OBSERVATION:
 * The condition "odd-position sum == even-position sum" is equivalent to
 * the alternating sum of the subarray being zero:
 *   a[l] - a[l+1] + a[l+2] - a[l+3] + ... = 0
 *
 * APPROACH: Prefix Alternating Sum + Hash Set
 *
 * Define prefix alternating sum:
 *   b[0] = 0
 *   b[i] = -a[0] + a[1] - a[2] + ... +/- a[i-1]
 *
 * Then the alternating sum of subarray [l, r] = b[r+1] - b[l]  (up to sign)
 * This equals zero iff b[r+1] == b[l].
 *
 * So the problem reduces to:
 *   "Does any prefix sum value appear twice?"
 * which we check using an unordered_set in O(1) average per element.
 *
 * WHY INSERT 0 FIRST:
 * b[0] = 0 represents the empty prefix. If b[i] == 0 for any i,
 * it means subarray [0, i-1] already has alternating sum = 0.
 * Inserting 0 at the start handles this case automatically.
 *
 * WHY CUSTOM HASH:
 * unordered_set uses a default hash vulnerable to adversarial inputs,
 * causing O(n) per lookup in worst case → O(n^2) total.
 * A custom hash scrambles bits to prevent collision attacks.
 *
 * TIME COMPLEXITY  : O(n) average per test case
 * SPACE COMPLEXITY : O(n) per test case
 *///
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