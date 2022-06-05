#include <iostream>
using namespace std;

struct BstNode {
 int data;
 BstNode* left;
 BstNode* right;
};

BstNode* GetNewNode(int data){
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

BstNode* Insert(BstNode* root, int data){
  if (root == NULL) {
    root = GetNewNode(data);
  }
  else if (data <= root->data) {
    root->left = Insert(root->left, data);
  }
  else {
    root->right = Insert(root->right, data);
  }
  return root;
}

void InOrder(BstNode* root){
 if (root == NULL) return;
 InOrder(root->left);
 cout << root->data << " ";
 InOrder(root->right);
}

void PastOrder(BstNode* root){
 if (root == NULL) return;
 PastOrder(root->right);
 cout << root->data << " ";
 PastOrder(root->left);
}

int main() {
  BstNode* root = NULL;
  root = Insert(root, 8);
  root = Insert(root, 9);
  root = Insert(root, 4); 
  root = Insert(root, 7); 
  root = Insert(root, 11);
  root = Insert(root, 5);
  root = Insert(root, 10);
  root = Insert(root, 6);
  InOrder(root);
  cout << endl;
  PastOrder(root);
}
