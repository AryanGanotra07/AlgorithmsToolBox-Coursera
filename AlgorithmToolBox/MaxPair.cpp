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
	
	int max_index2 = -1;
	int n = numbers.size();
	int max_index1 = -1;
	for(int i=0 ; i<n ;++i) {
		if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
			max_index1 = i;
	}
	for (int j=0; j<n; ++j) {
		if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) 
			max_index2 = j;

	}

	return ((long long) numbers[max_index1])*numbers[max_index2];
	

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
