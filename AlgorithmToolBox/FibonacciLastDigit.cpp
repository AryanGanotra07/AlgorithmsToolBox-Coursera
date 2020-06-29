#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define ll long long;

int fibonacci(int n) {
    int f = 0;
    int s = 1;
    int l;
    for (int i=2;i<=n;i++) {
        int t = f;
        f = s;
        s = t + s;
    }
    return s%10;

}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';
    return 0;
}