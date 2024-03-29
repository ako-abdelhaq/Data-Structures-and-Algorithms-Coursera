#include <iostream>

int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 2; i < n + 1; ++i) {
        int tmp_previous = previous % 10;
        previous = current % 10;
        current = (tmp_previous + current)%10;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    return 0;
   }
