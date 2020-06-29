#include <iostream>



long long get_fibonacci_sum_last(long long n) {
    long long remainder = n % 60;

    long long first = 0;
    long long second = 1;

    long long res = remainder;
    long long int sum = 1;

    for (int i = 1; i <remainder; i++) {
        res = (first + second)%10;
        first = second;
        second = res;
        sum = sum + res
    }

    return sum%10;
}

int main() {
//    for (int i = 2; i < 100; i++) {
//        std::cout << i << " : " << get_pisano_period(i) << std::endl;
//    }
//    return 0;
    long long n;
    std::cin >> n;
    std::cout << get_fibonacci_sum_last(n) << '\n';
    return 0;
}