#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int d[a.size()+1][b.size()+1];
  for (int i=0;i<=a.size();i++){
      d[i][0] = 0;
  }
  for (int j=0; j<=b.size() ;j++) {
      d[0][j] = 0;
  }
  
  for (int i=1;i<=a.size();i++) {
      for (int j=1;j<=b.size(); j++) {
          if (i == 0 || j==0) {
              d[i][j]= 0;
          }
          else if (a[i-1] == b[j-1]) {
            //   std::cout << "\n" << "Doing this"<< '\n';
            //   std::cout << a[i] << " " << b[j];
              d[i][j] = 1 + d[i-1][j-1];
              
          }
          else {
            //   std::cout<< "\n" << "doing that" << "\n";
              d[i][j] = std::max(d[i-1][j], d[i][j-1]);
          }
      }
  }

  return d[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
