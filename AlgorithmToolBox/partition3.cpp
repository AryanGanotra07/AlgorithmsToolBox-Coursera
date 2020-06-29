#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int isSubsetSum (vector<int> &arr, int n, int sum)  
{  
    // Base Cases  
    if (sum == 0)  
        return 1;  
    if (n == 0 && sum != 0)  
        return 0;  
  
    // If last element is greater than sum, then  
    // ignore it  
    if (arr[n-1] > sum)  
       return isSubsetSum (arr, n-1, sum);  
  
    /* else, check if sum can be obtained by any of  
        the following  
        (a) including the last element  
        (b) excluding the last element  
    */
    return isSubsetSum (arr, n-1, sum) ||  
        isSubsetSum (arr, n-1, sum-arr[n-1]);  
}  
  

int partition3(vector<int> &A) {
  int sum = 0;  
    for (int i = 0; i < A.size(); i++)  
    sum += A[i];  
  
    // If sum is odd, there cannot be two subsets  
    // with equal sum  
    if (sum%3 != 0)  
    return 0;  
  
    // Find if there is subset with sum equal to  
    // half of total sum  
    return isSubsetSum (A, A.size(), sum/3);
}

int partition3Dp(vector<int> &arr) {
    int sum = 0;  
    int i, j;  
    int n = arr.size();
      
    // Calculate sum of all elements  
    for (i = 0; i < n; i++)  
    sum += arr[i];  
      
    if (sum % 3 != 0)  
    return false;  
      
    bool part[sum / 3 + 1][n + 1];  
      
    // initialize top row as true  
    for (i = 0; i <= n; i++)  
    part[0][i] = true;  
          
    // initialize leftmost column,  
    // except part[0][0], as 0  
    for (i = 1; i <= sum / 3; i++)  
    part[i][0] = false;  
      
    // Fill the partition table in botton up manner  
    for (i = 1; i <= sum / 3; i++)  
    {  
        for (j = 1; j <= n; j++)  
        {  
            part[i][j] = part[i][j - 1];  
            if (i >= arr[j - 1])  
            part[i][j] = part[i][j] ||  
                         part[i - arr[j - 1]][j - 1];  
        }      
    }  
      
    /* // uncomment this part to print table  
    for (i = 0; i <= sum/2; i++)  
    {  
    for (j = 0; j <= n; j++)  
        cout<<part[i][j];  
    cout<<endl;  
    } */
    bool ans = part[sum / 3][n];
    if (ans) {
        return 1;
    }
    return 0;
    
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3Dp(A) << '\n';
}
