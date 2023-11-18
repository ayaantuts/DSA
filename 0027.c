// Create Expressions Tree from Postfix Expression
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <malloc.h>
#define SIZE 40
#define sn struct Node
char infix[SIZE], postfix[SIZE], postS[SIZE];
sn* stack[SIZE];
int top = -1, postT = -1;

sn {
	int data;
	sn *left, *right;
} *root = NULL;

void push(sn* node) {
	if (top == SIZE - 1) {
		printf("\nStack overflow!\n");
	}
	else {
		top++;
		stack[top] = node;
	}
}

int getPrio(char x) {
	if (x == '(')
		return 0;
	else if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/' || x == '%')
		return 2;
	else if (x == '^')
		return 3;
	else
		return 4;
}

void infix2postfix() {
	int i = 0, j = 0;
	while (infix[i] != '\0') {
		if (infix[i] == '(') {
			postS[++postT] = infix[i];
		}
		else if (isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}
		else if (infix[i] == ')') {
			while (postS[postT] != '(') {
				postfix[j++] = postS[postT--];
			}
			postT--;
		}
		else {
			if (getPrio(infix[i]) > getPrio(postS[postT])) {
				postS[++postT] = infix[i];
			}
			else {
				while (postT > -1 && getPrio(infix[i]) <= getPrio(postS[postT])) {
					postfix[j++] = postS[postT--];
				}
				postS[++postT] = infix[i];
			}
		}
		i++;
	}
	while (postT != -1) {
		postfix[j++] = postS[postT--];
	}
	postfix[j] = '\0';
}

sn* pop() {
	sn* x = NULL;
	if (top == -1) {
		printf("\nStack underflow\n");
	}
	else {
		x = stack[top];
		top--;
	}
	return x;
}

sn* createNode(int data) {
	sn* newnode = (sn*) malloc (sizeof(sn));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

sn* createTree() {
	int i = 0;
	sn *op1, *op2, *curr;
	char x;
	while (postfix[i] != '\0') {
		x = postfix[i];
		if (isalnum(x))
			push(createNode(x));
		else {
			curr = createNode(x);
			op2 = pop();
			op1 = pop();
			curr->left = op1;
			curr->right = op2;
			push(curr);
		}
		i++;
	}
	return pop();
}

void inorder(sn* temp) {
	if (temp) {
		inorder(temp->left);
		printf("%c ", temp->data);
		inorder(temp->right);
	}
}

void preorder(sn* temp) {
	if (temp) {
		printf("%c ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(sn* temp) {
	if (temp) {
		postorder(temp->left);
		postorder(temp->right);
		printf("%c ", temp->data);
	}
}

int main() {
	printf("\nEnter infix expression: ");
	scanf("%s", infix);
	infix2postfix();
	printf("\nPostfix expression: %s", postfix);
	root = createTree();
	printf("\nTree created:");
	printf("\nInorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	return 0;
}