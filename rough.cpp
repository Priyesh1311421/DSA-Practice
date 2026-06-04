// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> a(n + 1);

//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//         }

//         vector<int> o;

//         int f = 0;
//         for (int i = n; i >= 1; i--) {

//             long long cur = a[i];

//             if (f) cur = -cur;
//             if (cur > 0) {
//                 o.push_back(i);
//                 f ^= 1;
//             }
//         }

//         cout << o.size() << endl;

//         for (int x : o) {
//             cout << x << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> all(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> all[i];
        nth_element(all.begin(), all.begin() + n - 1, all.end());
        
        cout << all[n - 1] << endl;
    }
    
    return 0;
}