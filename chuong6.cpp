#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Định nghĩa cấu trúc cho một nút trong cây
struct Node {
    string data;      // Giá trị của nút (toán tử hoặc toán hạng)
    Node* left;      // Con trỏ đến nút con bên trái
    Node* right;     // Con trỏ đến nút con bên phải

    Node(string value) : data(value), left(nullptr), right(nullptr) {}
};

// Hàm duyệt cây theo thứ tự trước (Pre-order)
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " "; // Thăm nút gốc
    preOrder(root->left);       // Duyệt cây con bên trái
    preOrder(root->right);      // Duyệt cây con bên phải
}

// Hàm duyệt cây theo thứ tự giữa (In-order)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);        // Duyệt cây con bên trái
    cout << root->data << " ";  // Thăm nút gốc
    inOrder(root->right);       // Duyệt cây con bên phải
}

// Hàm duyệt cây theo thứ tự sau (Post-order)
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);      // Duyệt cây con bên trái
    postOrder(root->right);     // Duyệt cây con bên phải
    cout << root->data << " ";  // Thăm nút gốc
}

int main() {
    // Xây dựng cây cho biểu thức a * (b + c) / (e * f)
    Node* root1 = new Node("/"); // Gốc của cây
    root1->left = new Node("*");
    root1->right = new Node("*");

    root1->left->left = new Node("a");
    root1->left->right = new Node("+");
    root1->left->right->left = new Node("b");
    root1->left->right->right = new Node("c");

    root1->right->left = new Node("e");
    root1->right->right = new Node("f");

    // Xây dựng cây cho biểu thức (x1^x2)^(x1^x)
    Node* root2 = new Node("^");
    root2->left = new Node("^");
    root2->right = new Node("x");

    root2->left->left = new Node("x1");
    root2->left->right = new Node("x2");

    // Duyệt cây đầu tiên
    cout << "Duyet cay bieu thuc a * (b + c) / (e * f):" << endl;
    cout << "Duyet truoc (Pre-order): ";
    preOrder(root1);
    cout << endl;

    cout << "Duyet giua (In-order): ";
    inOrder(root1);
    cout << endl;

    cout << "Duyet sau (Post-order): ";
    postOrder(root1);
    cout << endl;

    cout << endl;

    // Duyệt cây thứ hai
    cout << "Duyet cay bieu thuc (x1^x2)^(x1^x):" << endl;
    cout << "Duyet truoc (Pre-order): ";
    preOrder(root2);
    cout << endl;

    cout << "Duyet giua (In-order): ";
    inOrder(root2);
    cout << endl;

    cout << "Duyet sau (Post-order): ";
    postOrder(root2);
    cout << endl;

    // Giải phóng bộ nhớ
    delete root1->left->right->right; // c
    delete root1->left->right->left; // b
    delete root1->left->right; // +
    delete root1->left->right; // +
    delete root1->left->right; // +
    delete root1->left->left; // a
    delete root1->left; // *
    delete root1->right->right; // f
    delete root1->right->left; // e
    delete root1->right; // *
    delete root1; // /

    delete root2->left->right; // x2
    delete root2->left->left; // x1
    delete root2->left; // ^
    delete root2->right; // x
    delete root2; // ^

    return 0;
}
