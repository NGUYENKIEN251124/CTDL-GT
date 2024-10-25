#include <iostream>
#include <stack>

using namespace std;

int main() {
    int number = 100;
    stack<int> binaryStack;

    // Chuyển đổi số nguyên sang nhị phân
    while (number > 0) {
        binaryStack.push(number % 2);  // Đẩy phần dư vào stack
        number /= 2;                    // Cập nhật số
    }

    // Xuất kết quả từ stack
    cout << "So nhi phan cua 100 la: ";
    while (!binaryStack.empty()) {
        cout << binaryStack.top();      // Lấy giá trị từ đỉnh stack
        binaryStack.pop();              // Pop giá trị
    }
    cout << endl;

    return 0;
}