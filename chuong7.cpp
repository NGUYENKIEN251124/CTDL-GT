#include <iostream>
using namespace std;

int main() {
    // Số đỉnh của đồ thị
    const int V = 5;

    // Ma trận kề
    int adjMatrix[V][V] = {
        {0, 1, 1, 1, 1},  // Đỉnh 1 kề với các đỉnh 2, 3, 4, 5
        {1, 0, 1, 0, 0},  // Đỉnh 2 kề với các đỉnh 1, 3
        {1, 1, 0, 1, 0},  // Đỉnh 3 kề với các đỉnh 1, 2, 4
        {1, 0, 1, 0, 1},  // Đỉnh 4 kề với các đỉnh 1, 3, 5
        {1, 0, 0, 1, 0}   // Đỉnh 5 kề với các đỉnh 1, 4
    };

    // Xuất ma trận kề
    cout << "Ma tran can ke:" << endl;
    for (int i = 0; i < V; i++) {  // Vòng lặp qua các hàng
        for (int j = 0; j < V; j++) {  // Vòng lặp qua các cột
            cout << adjMatrix[i][j] << " ";  // In ra phần tử của ma trận
        }
        cout << endl;  // Xuống dòng sau khi in xong một hàng
    }

    return 0;
}