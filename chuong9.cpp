#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo một nút mới
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Hàm chèn một giá trị vào cây nhị phân
Node* insert(Node* root, int data) {
    // Nếu cây rỗng, trả về một nút mới
    if (root == nullptr) {
        return newNode(data);
    }

    // Nếu giá trị nhỏ hơn gốc, chèn vào cây con bên trái
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Nếu giá trị lớn hơn gốc, chèn vào cây con bên phải
    else {
        root->right = insert(root->right, data);
    }

    // Trả về gốc của cây đã chèn
    return root;
}

// Hàm tìm kiếm nhị phân trong cây nhị phân
bool binarySearch(Node* root, int key) {
    // Nếu cây rỗng hoặc đã tìm thấy khóa
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    // Tìm trong cây con bên trái nếu khóa nhỏ hơn
    if (key < root->data) {
        return binarySearch(root->left, key);
    }

    // Tìm trong cây con bên phải nếu khóa lớn hơn
    return binarySearch(root->right, key);
}

// Hàm duyệt cây theo thứ tự LNR để kiểm tra nội dung cây
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Chèn các phần tử vào cây
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    // In cây theo thứ tự LNR
    cout << "Cay nhi phan theo thu tu LNR (inorder): ";
    inorder(root);
    cout << endl;

    // Tìm kiếm trong cây
    int key = 5;
    if (binarySearch(root, key)) {
        cout << "Tim thay gia tri " << key << " trong cay." << endl;
    } else {
        cout << "Khog tim thay gia tri  " << key << " trong cay." << endl;
    }

    return 0;
}