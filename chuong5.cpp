#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết đơn
struct Node {
    int info;       // Giá trị trong nút
    Node* next;     // Con trỏ đến nút tiếp theo
};

// Thủ tục thêm một nút mới vào cuối danh sách
void insertAtEnd(Node*& P, int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->next = nullptr; // Nút mới sẽ là nút cuối

    if (P == nullptr) {
        // Nếu danh sách rỗng, nút mới sẽ là nút đầu tiên
        P = newNode;
    } else {
        // Duyệt danh sách để tìm nút cuối
        Node* temp = P;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Gắn nút mới vào cuối
        temp->next = newNode;
    }
}

// Hàm in danh sách
void printList(Node* P) {
    Node* temp = P;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Thủ tục xóa một nút có giá trị info = x
void deleteNode(Node*& P, int x) {
    // Kiểm tra nếu danh sách rỗng
    if (P == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    // Xử lý trường hợp nút đầu tiên có info = x
    if (P->info == x) {
        Node* temp = P;
        P = P->next;  // Cập nhật P để bỏ qua nút đầu tiên
        delete temp;  // Giải phóng bộ nhớ của nút đầu tiên
        return;
    }

    // Duyệt danh sách để tìm nút có info = x
    Node* temp = P;
    Node* prev = nullptr;
    while (temp != nullptr && temp->info != x) {
        prev = temp;       // Lưu lại nút trước nút cần xóa
        temp = temp->next; // Tiến tới nút tiếp theo
    }

    // Nếu không tìm thấy x
    if (temp == nullptr) {
        cout << "khong tim thay nut co gia tri " << x << endl;
        return;
    }

    // Bỏ qua nút có info = x
    prev->next = temp->next;
    delete temp;  // Giải phóng bộ nhớ của nút bị xóa
}

int main() {
    Node* P = nullptr;  // Danh sách ban đầu rỗng

    // Thêm các phần tử vào cuối danh sách
    insertAtEnd(P, 10);
    insertAtEnd(P, 20);
    insertAtEnd(P, 30);
    insertAtEnd(P, 40);

    // In danh sách sau khi thêm
    cout << "Danh sach sau khi them cac phan tu: ";
    printList(P);

    // Xóa phần tử có giá trị info = 20
    deleteNode(P, 20);

    // In danh sách sau khi xóa phần tử có giá trị 20
    cout << "Danh sach sau khi xoa phan tu co gia tri bang 20: ";
    printList(P);

    // Xóa phần tử không tồn tại
    deleteNode(P, 50);

    return 0;
}

