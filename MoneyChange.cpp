#include <iostream>
using namespace std;

int total(int m) {
    int d[] = {10, 5, 1};
    int s = 0;
    for (int i=0; i<3; ++i) {
        s+=m/d[i];
        m = m%d[i];
    }
    return s;

    
}

int main() {
    int m;
    cin >> m;
    cout << total(m) << '\n';
    return 0;
}