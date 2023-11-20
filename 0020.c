// Implementation of Binary Search Tree
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define sn struct Node

sn {
	int data;
	sn *left, *right;
} *root;

void create() {
	int i, n, data;
	sn *newnode, *temp, *parent;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		newnode = (sn*) malloc (sizeof(sn));
		printf("\nEnter the data: ");
		scanf("%d", &data);
		newnode->data = data;
		newnode->left = newnode->right = NULL;
		parent = temp = root;
		if (!root)
			root = newnode;

		else {
			while (temp) {
				parent = temp;
				if (temp->data > data)
					temp = temp->left;

				else
					temp = temp->right;
			}
			if (parent->data > data)
				parent->left = newnode;
			else
				parent->right = newnode;
		}
	}
}

void insert() {
	sn* newnode = (sn*) malloc (sizeof(sn)), *temp, *parent;
	int data;
	printf("\nEnter the data: ");
	scanf("%d", &data);
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	parent = temp = root;
	if (!root)
		root = newnode;

	else {
		while (temp) {
			parent = temp;
			if (temp->data > data)
				temp = temp->left;

			else
				temp = temp->right;
		}
		if (parent->data > data)
			parent->left = newnode;
		else
			parent->right = newnode;
	}
}

void deleteNode() {
	int data;
	sn *temp, *del, *parent, *pred;
	printf("\nEnter the data of node to be deleted: ");
	scanf("%d", &data);
	parent = temp = root;
	while (temp && temp->data != data) {
		parent = temp;
		if (temp->data > data)
			temp = temp->left;

		else
			temp = temp->right;
	}
	if (!temp)
		printf("\nNode not found!");
	else {
		if (!temp->left && !temp->right) {
			if (parent->left == temp)
				parent->left = NULL;
			else
				parent->right = NULL;
			
		}
		else if (!temp->right) {
			if (parent->left == temp)
				parent->left = temp->left;
			else
				parent->right = temp->left;
		}
		else if (!temp->left) {
			if (parent->left == temp)
				parent->left = temp->right;
			else
				parent->right = temp->right;
		}
		else {
			parent = temp;
			pred = temp->left;
			while (pred->right) {
				parent = pred;
				pred = pred->right;
			}
			parent->right = pred->left;
			temp->data = pred->data;
			temp = pred;
		}
		free(temp);
	}
}

void mirror(sn* temp) {
	sn* t1;
	if (!temp) {
		mirror(temp->left);
		mirror(temp->right);
		t1 = temp->left;
		temp->left = temp->right;
		temp->right = t1;
	}
}

int totalNodes(sn* temp) {
	if (!temp)
		return 0;
	else
		return totalNodes(temp->left) + totalNodes(temp->right) + 1;
}

int internalNodes(sn* temp) {
	if (!temp)
		return 0;
	else if (!temp->left && !temp->right)
		return 1;
	else
		return internalNodes(temp->left) + internalNodes(temp->right);
}

int externalNodes() {
	return totalNodes(root) - internalNodes(root);
}

void preOrder(sn* temp) {
	if (temp) {
		printf("%d ", temp->data);
		preOrder(temp->left);
		preOrder(temp->right);
	}
}

void inOrder(sn* temp) {
	if (temp) {
		inOrder(temp->left);
		printf("%d ", temp->data);
		inOrder(temp->right);
	}
}

void postOrder(sn* temp) {
	if (temp) {
		postOrder(temp->left);
		postOrder(temp->right);
		printf("%d ", temp->data);
	}
}

int main() {
	int choice;
	root = NULL;
	// clrscr();
	create();
	do {
		printf("\n1. Insert\n2. Delete\n3. Preorder\n4. Inorder\n5. Postorder\n6. Mirror\n7. Count Internal\n8. Count External\n9. Count Total\n10. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				insert();
				break;
			case 2:
				deleteNode();
				break;
			case 3:
				preOrder(root);
				break;
			case 4:
				inOrder(root);
				break;
			case 5:
				postOrder(root);
				break;
			case 6:
				mirror(root);
				break;
			case 7:
				printf("\nThe number of internal nodes are: %d", internalNodes(root));
				break;
			case 8:
				printf("\nThe number of external nodes are: %d", externalNodes());
				break;
			case 9:
				printf("\nThe number of total nodes are: %d", totalNodes(root));
				break;
			case 10:
				break;
			default:
				printf("Invalid choice");
				choice = 10;
		}
	} while (choice != 10);
	// getch();
	return 0;
}