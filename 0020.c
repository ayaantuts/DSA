// Implement BST
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define sn struct Node

sn {
	int data;
	sn *left, *right;
} *root = NULL;

void createBST() {
	int i, n, val;
	sn *newnode, *temp = root, *parent;
	printf("\nEnter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		newnode = (sn*) malloc (sizeof(sn));
		newnode->left = newnode->right = NULL;
		printf("\nEnter the data: ");
		scanf("%d", &val);
		newnode->data = val;
		if (!root) {
			root = newnode;
		}
		else {
			temp = root;
			while (temp != NULL) {
				parent = temp;
				if (temp->data > val)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (parent->data > val)
				parent->left = newnode;
			else
				parent->right = newnode;
		}
	}
}

void preorder(sn* temp) {
	if (temp != NULL) {
		printf("%d ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(sn* temp) {
	if (temp != NULL) {
		preorder(temp->left);
		printf("%d ", temp->data);
		preorder(temp->right);
	}
}

void postorder(sn* temp) {
	if (temp != NULL) {
		preorder(temp->left);
		preorder(temp->right);
		printf("%d ", temp->data);
	}
}

int main() {
	createBST();
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\n");
}

// Input:
// 6
// 10 2 12 0 8 11

// Output:
// Inorder: 2 0 8 10 12 11 
// Postorder: 2 0 8 12 11 10 
// Preorder: 10 2 0 8 12 11 

// Expected Output:
// Inorder: 0 2 8 10 11 12
// Postorder: 0 8 2 11 12 10
// Preorder: 10 2 0 8 12 11