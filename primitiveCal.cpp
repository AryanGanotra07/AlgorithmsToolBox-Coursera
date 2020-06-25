#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> optimal_sequence_dp(int n) {
    std::vector<int> sequence(n+1);
    for (int i=1;i<=n;++i) {
        sequence[i] = sequence[i-1]+1;
        if (i%2 == 0) {
            sequence[i] = min(1 + sequence[i/2], sequence[i]);
        }
        else if (i%3 == 0) {
            sequence[i] = min(1 + sequence[i/3], sequence[i]);
        }
    }
    // cout << sequence[n-1] << endl;
    std::vector<int> result;
    while (n > 1) {
        result.push_back(n);
        if (sequence[n-1] ==sequence[n] - 1) {
            n = n -1;
        }
        else if (n%2 == 0 && sequence[n/2] == sequence[n] -1) {
            n = n/2;
        }
        else if (n%3 == 0 && sequence[n/3] == sequence[n]-1) {
            n = n/3;
        }
    }
    result.push_back(1);
    reverse(result.begin(), result.end());
    return result;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
