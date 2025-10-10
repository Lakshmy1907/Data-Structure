#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Node {
 char data;
 struct Node *left;
 struct Node *right;
} Node;
typedef struct StackNode {
 Node *treeNode;
 struct StackNode *next;
} StackNode;
void push(StackNode **top, Node *treeNode) {
 StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
 if (newNode == NULL) {
 perror("Memory allocation failed");
 exit(EXIT_FAILURE);
 }
 newNode->treeNode = treeNode;
 newNode->next = *top;
 *top = newNode;
}
Node *pop(StackNode **top) {
 if (*top == NULL) {
 return NULL;
 }
 StackNode *temp = *top;
 Node *treeNode = temp->treeNode;
 *top = temp->next;
 free(temp);
 return treeNode;
}
Node *newNode(char data) {
 Node *node = (Node *)malloc(sizeof(Node));
 if (node == NULL) {
 perror("Memory allocation failed");
 exit(EXIT_FAILURE);}
node->data = data;
 node->left = NULL;
 node->right = NULL;
 return node;
}
int precedence(char op) {
 switch (op) {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 case '^':
 return 3;
 default:
 return 0;
 }
}
Node *buildExpressionTree(char *infix) {
 StackNode *operandStack = NULL;
 StackNode *operatorStack = NULL;
 for (int i = 0; infix[i] != '\0'; i++) {
 char c = infix[i];
 if (isalnum(c)) {
 push(&operandStack, newNode(c));
 } else if (c == '(') {
 push(&operatorStack, newNode(c));
 } else if (c == ')') {
 while (operatorStack != NULL && operatorStack->treeNode->data != 
'(') {
 Node *opNode = pop(&operatorStack);
 opNode->right = pop(&operandStack);
 opNode->left = pop(&operandStack);
 push(&operandStack, opNode);
 }
 pop(&operatorStack);
 } else if (precedence(c) > 0) {
 while (operatorStack != NULL && operatorStack->treeNode->data != 
'(' &&
 precedence(operatorStack->treeNode->data) >= precedence(c)) {
 Node *opNode = pop(&operatorStack);
opNode->right = pop(&operandStack);
 opNode->left = pop(&operandStack);
 push(&operandStack, opNode);
 }
 push(&operatorStack, newNode(c));
 }
 }
 while (operatorStack != NULL) {
 Node *opNode = pop(&operatorStack);
 opNode->right = pop(&operandStack);
 opNode->left = pop(&operandStack);
 push(&operandStack, opNode);
 }
 return pop(&operandStack);
}
void postOrderTraversal(Node *root) {
 if (root == NULL) {
 return;
 }
 postOrderTraversal(root->left);
 postOrderTraversal(root->right);
 printf("%c", root->data);
}
int main() {
 char infixExpression[100];
 printf("Enter an infix expression: ");
 fgets(infixExpression, sizeof(infixExpression), stdin);
 infixExpression[strcspn(infixExpression, "\n")] = 0;
 Node *root = buildExpressionTree(infixExpression);
printf("Postfix expression: ");
 postOrderTraversal(root);
 printf("\n");
 return 0;
}