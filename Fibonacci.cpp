#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define ll long long;

int fibonacciNaive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciNaive(n-1) + fibonacciNaive(n-2);
}


int fibonacci(int n) {
 vector<int> numbers(n+1, 0);
 numbers[0] = 0;
 numbers[1] = 1;
 for(int i=2; i<=n;i++) {
     numbers[i] = numbers[i-1] + numbers[i-2];
 }
 return numbers[n];
}


void test_solution() {
    assert(fibonacci(3) == 2);
    assert(fibonacci(10) == 55);
    for (int i=0 ;i< 20 ;++i) {
        assert(fibonacci(i) == fibonacciNaive(i));
    }
}

int main() {
    int n;
    cin >> n;
    // test_solution();
    cout << fibonacci(n) << '\n';
    return 0;
}