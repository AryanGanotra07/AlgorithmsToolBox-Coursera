#include <iostream>
#include <string>


using std::string;
using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 

int editDist(const string &str1, const string &str2,  int m, int n) {
   
//     int d[n+1][m+1];
//     for (int i = 0;i<=n;++i) {
//         d[i][0] = i;
//         d[0][i] = i;
//     }
//     for (int j=1; j<=m ;j++) {
//         for (int i=1; i<=n ; i++) {
//             int insertion = d[i][j-1] +1;
//             int deletion = d[i-1][j] + 1;
//             int match = d[i-1][j-1];
//             int mismatch = d[i-1][j-1] + 1;
//             if(str1[i] == str2[j]) {
//                 d[i][j] = min(min(insertion,deletion), match);
//             }
//             else {
//                 d[i][j] = min(min(insertion, deletion), mismatch);
//             }
//         }
        
//     }
  
//   return d[n-1][m-1];

// If first string is empty, the only option is to 
    // insert all characters of second string into first 
    if (m == 0) 
        return n; 
  
    // If second string is empty, the only option is to 
    // remove all characters of first string 
    if (n == 0) 
        return m; 
  
    // If last characters of two strings are same, nothing 
    // much to do. Ignore last characters and get count for 
    // remaining strings. 
    if (str1[m - 1] == str2[n - 1]) 
        return editDist(str1, str2, m - 1, n - 1); 
  
    // If last characters are not same, consider all three 
    // operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take 
    // minimum of three values. 
    return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   ); 
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << editDist(str1, str2, str1.size(), str2.size()) << std::endl;
  return 0;
}
