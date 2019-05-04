#include <iostream>
using namespace std;

struct Tree {
	char left;
	char right;
};

Tree arr[27];

void preorder(char node)
{
	if (node == '.')
		return ;
	cout << node;
	preorder(arr[node].left);
	preorder(arr[node].right);
}
void inorder(char node)
{
	if (node == '.')
		return ;
	inorder(arr[node].left);
	cout << node;
	inorder(arr[node].right);
}
void postorder(char node)
{
	if (node == '.')
		return ;
	postorder(arr[node].left);
	postorder(arr[node].right);
	cout << node; 
}
int main()
{
	
	char tmpP, tmpL, tmpR;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmpP >> tmpL >> tmpR;
		arr[tmpP].left = tmpL;
		arr[tmpP].right = tmpR;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}