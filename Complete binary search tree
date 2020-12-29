#include<iostream>
#include<math.h>
using namespace std;
struct node{
	node *left;
	node* right;
	int data;
	
};

class cbt{
 node* root;
   
public:
	cbt() { root = NULL; }

  node* get_node() { return root; }

  int find_height(node* r) {
    if (r == NULL)

      return 0;

    else {
      int lheight = find_height(r->left) + 1;

      int rheight = find_height(r->right) + 1;

      if (lheight > rheight) {
        return lheight;
      } else {
        return rheight;
      }  // returns maximum height
    }
  }

  node* newNode(int key) {
    node* temp1 = new node;
    temp1->data = key;
    temp1->left = temp1->right = NULL;

    return temp1;
  }

  int countNumNodes(node* root) {
    if (root == NULL)
      return 0;
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
  }
bool isTreeFull(node* head) {
  return head && countNumNodes(head) == (1 << find_height(head)) - 1;
}

void CBT_inseration(int data) {
  root = insert(root, data);
}

node* insert(node* head, int data) {
  node* ptr = newNode(data);
  if (head == NULL) {
    head = ptr;
  } else {
    int leftCount = countNumNodes(head->left);
    int rightCount = countNumNodes(head->right);
    if (leftCount == rightCount) {
      head->left = insert(head->left, data);
    } else {
      if (isTreeFull(head->left)) {
        head->right = insert(head->right, data);
      } else {
        head->left = insert(head->left, data);
      }
    }
  }
  return head;
}



void print(node* root) {
    if (root == NULL)
      return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
  }
};
int main() {
  cbt obj;
  node* r = NULL;
  obj.CBT_inseration(4);
  obj.CBT_inseration(3);
  obj.CBT_inseration(5);
  obj.CBT_inseration(6);
  obj.CBT_inseration(8);
  obj.print(obj.get_node());
  return 0;
}
