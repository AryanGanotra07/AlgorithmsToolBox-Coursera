#include<iostream>
using namespace std;

int result(int d, int m, int n, int s[]) {
    int res = 0;
    int curr = 0;
    int i = 0;
    while (curr < d && i < n) {
        int next = curr + m;
        // cout << next << s[i] << '\n';
        if (next < d && next < s[i]) {
            return -1;
        }
        while(i < n && next >= s[i]) {
            i += 1;
        }
        res+=1;
        curr = s[i-1];
        

    }

    return res;
}

int main() {
    int d;
    cin >> d;
    int m;
    cin >> m;
    int n;
    cin >> n;
    int s[n];
    for (int i=0; i<n ;++i) {
        cin >> s[i];
    }
    
    cout << result(d, m, n, s) << '\n';
    return 0;

}