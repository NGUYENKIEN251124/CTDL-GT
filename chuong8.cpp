#include <iostream>
using namespace std;

// Hàm hoán đổi 2 phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân chia mảng và trả về chỉ số của pivot sau khi phân chia
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1);     // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;  // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Hàm thực hiện thuật toán sắp xếp nhanh
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Chỉ số của pivot sau khi phân chia
        int pi = partition(arr, low, high);

        // Sắp xếp các phần tử trước và sau pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {17, 4, 2, 9, 30, 1, 5, 26, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}