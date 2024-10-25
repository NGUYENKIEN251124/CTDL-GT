#include <iostream>

using namespace std;

// Hàm đệ quy tính giai thừa
int factorial(int n) {
    if (n == 0) return 1; // Điều kiện cơ bản
    return n * factorial(n - 1); // Đệ quy
}

// Hàm đệ quy tính số hạng Fibonacci
int F(int n) {
    if (n == 0) return 0; // Điều kiện cơ bản
    if (n == 1) return 1; // Điều kiện cơ bản
    return F(n - 1) + F(n - 2); // Đệ quy
}

int main() {
    // Tính giai thừa cho n = 4
    int n = 4;
    cout << n << "! = " << factorial(n) << endl; // In ra 4!

    // Tính số hạng Fibonacci cho n = 4
    cout << "F(" << n << ") = " << F(n) << endl; // In ra F(4)

    return 0;
}

