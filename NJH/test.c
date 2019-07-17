#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#define NUM 50000
#define LAST 1000
#define RAND_NUM 1000

typedef struct TreeNode {
	int id;  //학번을 기준으로 이진 탐색 트리를 만들기
	char name[11];//이름
	char phone[12];//전화번호(-기호까지 포함X)
	struct TreeNode * left;
	struct TreeNode * right;
}TreeNode;

int n = 0;
int num_n = 0;//재귀 호출을 다루기 위해서 전역변수를 사용
int before_id;
int is_first = 0;
int is_error = 0;

//중위 순회하기:재귀적으로 구현
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
		else {//처음 print하는게 아니고서야 전부다 비교할 필요가 있다.
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
TreeNode* search(TreeNode *root, int key) {//반복적인 탐색
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
	return NULL;//탐색에 실패했을 경우 NULL반환
}

//이진탐색트리:삽입
void insert_node(TreeNode** proot, TreeNode*new_node) {
	TreeNode *p, *t;//p:부모노드,t:현재노드
	t = *proot;
	p = NULL;
	//탐색을 먼저 수행(어디에 위치해야하는가?)
	while (t!=NULL)
	{
		if (new_node->id == t->id) return;//중복되는 데이터는 그냥 무시하도록 하자
		p = t;//parent를 저장후 밑으로 내려오도록 하자
		if (new_node->id < t->id) t = t->left;
		else t = t->right;
	}
	//key가 트리 안에 없으므로 삽입 가능
	new_node->right = NULL;
	new_node->left = NULL;
	//부모 노드와 링크 연결
	if (p != NULL) {
		if (new_node->id < p->id) {
			p->left = new_node;
		}
		else {
			p->right = new_node;
		}
	}
	else {
		*proot = new_node;//공백 노드인 경우
	}
}


//랜덤한 데이터 NUM명분 만들기
void make_data(TreeNode** proot, int last_tree[]) {
	int		idnum1, idnum2, year, id;
	char name[11];
	char phone[12];
	int phone1, phone2;
	int i, j;
	int num = 0;
	for (i = 0; i < NUM; i++) {
		// 학번 만들기
		year = rand() % 7 + 2013;
		idnum1 = rand() % 1000;
		idnum2 = rand() % 100;
		id = year * 100000 + idnum1 * 100 + idnum2;
		//이름 만들기
		for (j = 0; j < 10; j++) {
			name[j] = rand() % 26 + 'A';
		}
		name[j] = 0;//null문자
					//전화번호 만들기(-까지 포함해서 만들것)
		phone1 = rand() % 10000;
		phone2 = rand() % 10000;
		sprintf(phone, "010%04d%04d", phone1, phone2);
		//printf("making(%d) %d %s:%s\n", n+1,id,name,phone);///////////////////////////////////check code
		//노드 만들기
		TreeNode * new_node = (TreeNode *)malloc(sizeof(TreeNode));
		new_node->id = id;
		strcpy(new_node->name, name);
		strcpy(new_node->phone, phone);
		insert_node(proot, new_node);

		//해당 노드에 맞는 곳에 위치하도록 
		if ((NUM - i - 1) <= LAST) {
			last_tree[num] = id;
			num++;
		}
		n++;
	}
}

/////////////////////////////////////////////////////////////////
void main() {
	TreeNode * root=NULL;//5만명분
	//malloc을 이용해서 할당해보도록 하자.
	int *last_tree = malloc(sizeof(int*)*LAST);
	int * random_id = malloc(sizeof(int*)*RAND_NUM);
	//int last_tree[LAST];//가장 마지막에 생성된 1000명의 학번만 저장
	//int random_id[RAND_NUM];//randoem한 학번을 만들고 저장
	int i, key;
	int year, idnum1, idnum2, num;
	TreeNode * node;
	make_data(&root, last_tree);
	//중위순회하기
	printf("Step1.중위 순회하기\n");
	inorder(root);
	printf("Step2.데이터 탐색하기\n");
	for (i = 0; i < LAST; i++) {
		key = last_tree[i];
		node = search(root, key);
		if (node == NULL) {//탐색에 실패했을 경우(사실 이경우는 없을것이다.)
			printf("%04d. %d (없음)\n", i + 1, key);
		}
		else {
			printf("%04d. %d %s\n", i + 1, key, node->name);
		}
	}
	printf("Step3.랜덤한 학번으로 검색하기\n");
	//랜덤한 학번만들기
	for (i = 0; i < RAND_NUM; i++) {
		// 학번 만들기
		year = rand() % 7 + 2013;
		idnum1 = rand() % 1000;
		idnum2 = rand() % 100;
		random_id[i] = year * 100000 + idnum1 * 100 + idnum2;
	}
	//랜덤한 학번 검색하기
	num = 0;
	for (i = 0; i < RAND_NUM; i++) {
		key = random_id[i];
		node = search(root, key);
		if (node == NULL) {//탐색에 실패했을 경우(사실 이경우는 있을 수 있을 것이다.)
			printf("%04d. %d (없음)\n", i + 1, key);
		}
		else {
			printf("%04d. %d %s\n", i + 1, key, node->name);
			num++;
		}
	}
	printf("총 %d개 발견\n", num);

}

