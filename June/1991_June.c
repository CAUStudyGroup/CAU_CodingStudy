#include <stdio.h>
#include <malloc.h>
typedef char Data;
typedef struct _btreeNode {
	Data data;
	struct _btreeNode *left;
	struct _btreeNode *right;
}BTreeNode;
void InorderTraverse(BTreeNode * bt) {
	if (NULL == bt)
		return;
	InorderTraverse(bt->left);
	printf("%c", bt->data);
	InorderTraverse(bt->right);
}
void PreorderTraverse(BTreeNode * bt) {
	if (NULL == bt)
		return;
	printf("%c", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
void PostorderTraverse(BTreeNode * bt) {
	if (NULL == bt)
		return;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%c", bt->data);
}
BTreeNode * MakeBTreeNode(void) {
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	return nd;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	if (NULL != main->left) {
		free(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
	if (NULL != main->right) {
		free(main->right);
	}
	main->right = sub;
}
BTreeNode *trees[26];
int main() {
	int i, T;
	char input1, input2, input3;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		trees[i] = (BTreeNode*)malloc(sizeof(BTreeNode));
		trees[i]->left = NULL;
		trees[i]->right = NULL;
	}
	getchar();
	for (i = 0; i < T; i++) {
		scanf("%c %c %c", &input1, &input2, &input3);
		int idx1, idx2, idx3;
		idx1 = input1 - 'A';
		idx2 = input2 - 'A';
		idx3 = input3 - 'A';
		if ('.' != input1)
			trees[idx1]->data = input1;
		if ('.' != input2)
			trees[idx2]->data = input2;
		if ('.' != input3)
			trees[idx3]->data = input3;

		if ('.' != input1 && '.' != input2)
			MakeLeftSubTree(trees[idx1], trees[idx2]);
		if ('.' != input1 && '.' != input3)
			MakeRightSubTree(trees[idx1], trees[idx3]);
		getchar();
	}
	PreorderTraverse(trees[0]);
	putchar('\n');
	InorderTraverse(trees[0]);
	putchar('\n');
	PostorderTraverse(trees[0]);
	for (i = 0; i < T; i++) {
		free(trees[i]);
	}
	return 0;
}