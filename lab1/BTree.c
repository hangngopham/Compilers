#include "BTree.h"
#include "input_token.h"
struct BinaryTree
{
	DATA val; 
	struct BinaryTree* left;
	struct BinaryTree* right;
};
Tree LeafTree(DATA d) {
	Tree t;
	t = malloc(sizeof(Tree));
	t->val = d;
	t->left = NULL;
	t->right = NULL;
	return t;
}

Tree BTree(DATA d, Tree l, Tree r) {
	Tree t;
	t = malloc(sizeof(Tree));
	t->val = d;
	t->left = l;
	t->right = r;
	return t;
}

bool isLeaf(Tree root) {
	return root->left == NULL && root->right == NULL;
}	

DATA getData(Tree root) {
	return root->val;
}

Tree getLeft(Tree root) {
	return root->left;
}

Tree getRight(Tree root) {
	return root->right;
}

void in_order_traversal(Tree t) {
	if(isLeaf(t)) {
		printf("%d", t->val);
		return;
	}
	printf("(");
	in_order_traversal(t->left);
	if(t->val==Plus) { printf("+"); }
	else if(t->val==Minus) {printf("-");}
	else if(t->val==Mult) { printf("*");}
	else if(t->val==Divide) { printf("/");}
	else {printf("%c", t->val);}
	in_order_traversal(t->right);
	printf(")");
}

void post_order_traversal(Tree t) {
	if(isLeaf(t)) {
		printf("%d ", t->val);
		return;
	}
	post_order_traversal(t->left);
	post_order_traversal(t->right);
	if(t->val==Plus) { printf("+ "); }
	else if(t->val==Minus) {printf("- ");}
	else if(t->val==Mult) { printf("* ");}
	else if(t->val==Divide) { printf("/");}
	else {printf("%d ", t->val);}
}

int eval(Tree t) {
	if(isLeaf(t)) {return t->val;}
	int lval = eval(t->left);
	int rval = eval(t->right);
	if(t->val==Plus) { return lval+rval;}
	else if(t->val==Minus) { return lval-rval;}
	else if(t->val==Mult) { return lval*rval;}
	else if(t->val==Divide) { return lval/rval;}
}


