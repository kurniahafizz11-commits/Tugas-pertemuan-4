#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* tambah (Node* root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;

        return root;
    }

    // inputan lebih besar dari data root
    if (data < root->data) {
        root->kiri = tambah(root->kiri, data);
    }

    // inputan lebih kecil dari data root
    if (data > root->data) {
        root->kanan = tambah(root->kanan, data);
    }
    return root;
}

//PRE-ORDER
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

//IN-ORDER
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

//POST-ORDER
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main () {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0=stop) : ";
    cin >> angka;

    while (angka != 0) {
        root = tambah(root, angka);
        cin >> angka;
    }

    cout << "Pre Order : ";
    preOrder(root);

    cout << endl;

    cout << "In Order : ";
    inOrder(root);

    cout << endl;

    cout << "Post Order : ";
    postOrder(root);

    cout << endl;
    return 0;
}