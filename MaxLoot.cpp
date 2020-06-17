#include<iostream>
#include <iomanip>
using namespace std;


double result(int v[], int w[], int N, int W) {
    double vw[N];
    double val = 0.0000;
    for (int i=0;i<N;++i) {
        vw[i] = double(v[i]) / double(w[i]);
    }
    
    for (int i= 0; i<N;++i) {
        int max = -1;
        int maxi = -1;
        for (int i=0; i<N;i++) {
            if (w[i] > 0 && (v[i]/w[i]) > max) {
                max = v[i]/double(w[i]);
                maxi = i;
            }
        }
        int a = min(w[maxi], W);
        val += a*vw[maxi];
        W -= a;
        w[maxi] = -1;
    } 
    double rounded = (val * 10000.0000)/10000.0000;

    return rounded;
    
}

int main() {
    int N, W;
    cin >> N >> W;
    int v[N], w[N];
    for (int i=0; i<N;++i) {
        cin >> v[i] >> w[i];
    }
    cout << std::fixed << std::setprecision(4) << result(v, w, N, W) << '\n';
    return 0;
}