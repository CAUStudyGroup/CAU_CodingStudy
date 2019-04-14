#include <iostream>
#include <queue>

using namespace std;

int visit[102][102];

struct block
{
	int x;
	int y;
	int count; 
};

int main()
{
	int N, M;
	char arr[102][102];
	queue<struct block> q;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; //�迭 �ʱ�ȭ
	}

	q.push({ 0,0,1 });
	visit[0][0] = 1; // ����

	while (1)
	{	//�湮 ���� �ʾҰ� ���� �� �� �ִ� ��� //1
		if (q.front().x > 0 && visit[q.front().x-1][q.front().y]!=1) 
		{
			if (arr[q.front().x - 1][q.front().y] == '1')
			{
				q.push({ q.front().x - 1,q.front().y,q.front().count + 1 });
				visit[q.front().x - 1][q.front().y] = 1;
			}
		}
		//�湮 ���� �ʾҰ� �Ʒ��� �� �� �ִ� ��� //2
		if (q.front().x+1 <=N-1 && visit[q.front().x+1][q.front().y] != 1)
		{
			if (arr[q.front().x + 1][q.front().y] == '1')
			{
				q.push({ q.front().x + 1,q.front().y,q.front().count + 1 });
				visit[q.front().x + 1][q.front().y] = 1;
			}
		}
		// �湮 ���� �ʾҰ� �·� �� �� �ִ� ��� //3
		if (q.front().y > 0 && visit[q.front().x][q.front().y-1] != 1)
		{
			if (arr[q.front().x][q.front().y - 1] == '1')
			{
				q.push({ q.front().x,q.front().y - 1,q.front().count + 1 });
				visit[q.front().x][q.front().y - 1] = 1;
			}
		}
		// �湮 ���� �ʾҰ� ��� �� �� �ִ� ��� //4
		if (q.front().y+1 <=M-1 && visit[q.front().x][q.front().y+1] != 1)
		{
			if (arr[q.front().x][q.front().y + 1] == '1')
			{
				q.push({ q.front().x,q.front().y + 1,q.front().count + 1 });
				visit[q.front().x][q.front().y + 1] = 1;
			}
		}

		if (q.front().x == N - 1 && q.front().y == M - 1)
			break;

		q.pop();

	}
	cout << q.front().count;
	return 0;
}