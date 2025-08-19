#include <iostream>
using namespace std;

int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        int remainder = n % 10;
        reversed = reversed * 10 + remainder;  // Build the reversed number
        n = n / 10;
    }
    return reversed;
}

int main() {
    int n = 562;
    cout << "The integer is: " << n << endl;
    cout << "The reverse is: " << reverse(n) << endl;
    return 0;
}
