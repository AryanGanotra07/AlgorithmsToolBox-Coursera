#include<iostream>
using namespace std;

int show(int a[]) 
{ 
    for(int i = 0; i < 3; ++i) 
        cout << a[i] << " "; 
    return 0;
} 



int result(int n, int a[], int b[]) {
    // int num = sizeof(a) / sizeof(a[0]);
    sort(a, a+n, greater<int>());
    sort(b, b+n, greater<int>());
    // cout << show(a) << endl;
    // cout << show(b) << endl;
    int res = 0;
    for(int i=0;i<n;++i) {
        res+=a[i]*b[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n] , b[n];
    for (int i=0;i<n;++i) {
        cin >> a[i];
    }
    for (int i=0 ;i<n;++i) {
        cin >> b[i];
    }
    cout << result(n, a, b) << '\n';
    return 0;
}