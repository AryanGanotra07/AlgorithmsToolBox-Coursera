#include <iostream>
using namespace std;

int get_change(int m) {
  //write your code here
  int den[] = {1,3,4};
  int minNum[m+1];
  minNum[0] = 0;
  for (int i=1; i<=m ; ++i) {
    minNum[i] = INT32_MAX;
    for (int j=0; j<3 ;++j) {
      if (i >= den[j]) {
        int numCoins = minNum[i-den[j]] + 1;
        if (numCoins < minNum[i]) {
          minNum[i] = numCoins;
        }
      }
    }
  }
//   for (int i=0; i<=m ; ++i) {
//       cout << minNum[i] << endl;
//   }
  return minNum[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
