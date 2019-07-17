#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#define NUM 50000
#define LAST 1000
#define RAND_NUM 1000

typedef struct TreeNode {
	int id;  //�й��� �������� ���� Ž�� Ʈ���� �����
	char name[11];//�̸�
	char phone[12];//��ȭ��ȣ(-��ȣ���� ����X)
	struct TreeNode * left;
	struct TreeNode * right;
}TreeNode;

int n = 0;
int num_n = 0;//��� ȣ���� �ٷ�� ���ؼ� ���������� ���
int before_id;
int is_first = 0;
int is_error = 0;

//���� ��ȸ�ϱ�:��������� ����
void inorder(TreeNode * root) {
	TreeNode * p = root;
	if (p != NULL) {
		inorder(p->left);
		if (is_first == 0) {
			++num_n;
			before_id=p->id;
			printf("%d\n", p->id);
			is_first = 1;
		}
		else {//ó�� print�ϴ°� �ƴϰ��� ���δ� ���� �ʿ䰡 �ִ�.
			++num_n;
			printf("%d", p->id);
			if (before_id >= p->id) {
				is_error = 1;
				printf("  (ER)\n");
			}
			else {
				printf("  (OK)\n");
			}
			before_id = p->id;
		}
		inorder(p->right);
	}
}
TreeNode* search(TreeNode *root, int key) {//�ݺ����� Ž��
	TreeNode * node = root;
	while (node != NULL) {
		if (key == node->id) return node;
		else if (key < node->id) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return NULL;//Ž���� �������� ��� NULL��ȯ
}

//����Ž��Ʈ��:����
void insert_node(TreeNode** proot, TreeNode*new_node) {
	TreeNode *p, *t;//p:�θ���,t:������
	t = *proot;
	p = NULL;
	//Ž���� ���� ����(��� ��ġ�ؾ��ϴ°�?)
	while (t!=NULL)
	{
		if (new_node->id == t->id) return;//�ߺ��Ǵ� �����ʹ� �׳� �����ϵ��� ����
		p = t;//parent�� ������ ������ ���������� ����
		if (new_node->id < t->id) t = t->left;
		else t = t->right;
	}
	//key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	new_node->right = NULL;
	new_node->left = NULL;
	//�θ� ���� ��ũ ����
	if (p != NULL) {
		if (new_node->id < p->id) {
			p->left = new_node;
		}
		else {
			p->right = new_node;
		}
	}
	else {
		*proot = new_node;//���� ����� ���
	}
}


//������ ������ NUM��� �����
void make_data(TreeNode** proot, int last_tree[]) {
	int		idnum1, idnum2, year, id;
	char name[11];
	char phone[12];
	int phone1, phone2;
	int i, j;
	int num = 0;
	for (i = 0; i < NUM; i++) {
		// �й� �����
		year = rand() % 7 + 2013;
		idnum1 = rand() % 1000;
		idnum2 = rand() % 100;
		id = year * 100000 + idnum1 * 100 + idnum2;
		//�̸� �����
		for (j = 0; j < 10; j++) {
			name[j] = rand() % 26 + 'A';
		}
		name[j] = 0;//null����
					//��ȭ��ȣ �����(-���� �����ؼ� �����)
		phone1 = rand() % 10000;
		phone2 = rand() % 10000;
		sprintf(phone, "010%04d%04d", phone1, phone2);
		//printf("making(%d) %d %s:%s\n", n+1,id,name,phone);///////////////////////////////////check code
		//��� �����
		TreeNode * new_node = (TreeNode *)malloc(sizeof(TreeNode));
		new_node->id = id;
		strcpy(new_node->name, name);
		strcpy(new_node->phone, phone);
		insert_node(proot, new_node);

		//�ش� ��忡 �´� ���� ��ġ�ϵ��� 
		if ((NUM - i - 1) <= LAST) {
			last_tree[num] = id;
			num++;
		}
		n++;
	}
}

/////////////////////////////////////////////////////////////////
void main() {
	TreeNode * root=NULL;//5�����
	//malloc�� �̿��ؼ� �Ҵ��غ����� ����.
	int *last_tree = malloc(sizeof(int*)*LAST);
	int * random_id = malloc(sizeof(int*)*RAND_NUM);
	//int last_tree[LAST];//���� �������� ������ 1000���� �й��� ����
	//int random_id[RAND_NUM];//randoem�� �й��� ����� ����
	int i, key;
	int year, idnum1, idnum2, num;
	TreeNode * node;
	make_data(&root, last_tree);
	//������ȸ�ϱ�
	printf("Step1.���� ��ȸ�ϱ�\n");
	inorder(root);
	printf("Step2.������ Ž���ϱ�\n");
	for (i = 0; i < LAST; i++) {
		key = last_tree[i];
		node = search(root, key);
		if (node == NULL) {//Ž���� �������� ���(��� �̰��� �������̴�.)
			printf("%04d. %d (����)\n", i + 1, key);
		}
		else {
			printf("%04d. %d %s\n", i + 1, key, node->name);
		}
	}
	printf("Step3.������ �й����� �˻��ϱ�\n");
	//������ �й������
	for (i = 0; i < RAND_NUM; i++) {
		// �й� �����
		year = rand() % 7 + 2013;
		idnum1 = rand() % 1000;
		idnum2 = rand() % 100;
		random_id[i] = year * 100000 + idnum1 * 100 + idnum2;
	}
	//������ �й� �˻��ϱ�
	num = 0;
	for (i = 0; i < RAND_NUM; i++) {
		key = random_id[i];
		node = search(root, key);
		if (node == NULL) {//Ž���� �������� ���(��� �̰��� ���� �� ���� ���̴�.)
			printf("%04d. %d (����)\n", i + 1, key);
		}
		else {
			printf("%04d. %d %s\n", i + 1, key, node->name);
			num++;
		}
	}
	printf("�� %d�� �߰�\n", num);

}

