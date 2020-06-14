#include <iostream>
#include <vector>
using namespace std;

long long maxPair(const vector<int>& numbers) {
	long long result = 0;
	int n = numbers.size();
	for(int i=0;i<n;++i) {
		for(int j=i+1; j<n; ++j) {
			if (result < ((long long) numbers[i]) * numbers[j]) {
				result = ((long long) numbers[i]) * numbers[j];
			}
		}
	}
	return result;
	}

long long fastMaxPair(const vector<int>& numbers) {
	long long result1 = numbers[0];
	long long result2 = numbers[1];
	int max_index2 = 1;
	int n = numbers.size();
	int max_index1 = 0;
	for(int i=1 ; i<n ;++i) {
		if (numbers[i] > result1) {
			result1 = numbers[i];
			max_index1 = i;
		}
	}
	for (int i=0; i<n; ++i) {
		if ((numbers[i]!=result1) && (numbers[i] > result2)) {
			result2 = numbers[i];
			max_index2 = i;
		}

	}

	return ((long long) result1 ) *result2;
	

}

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i =0;i < n; ++i) {
		cin >> numbers[i];
	}
	long long result = fastMaxPair(numbers);
	cout << result << '\n' ;
	return 0;
}
