#include <iostream>
#include <stack>

using namespace std;

struct block
{
	int x;
	int y;
	int count; 
	int stat;
};

int main()
{
	int N, M;
	char arr[102][102];
	stack<struct block> s;
	int min = 10000;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; //�迭 �ʱ�ȭ
	}
	
	s.push({ 0,0,1,0 });

	int run = 1;
	while (run == 1)
	{
		int a = s.top().x; 
		int b = s.top().y;
		int c = s.top().count;
		int d = s.top().stat;

		s.pop(); // �����δ� ������ �����ϰ� pop

		if (min > c) // �̵��� ������ Ƚ������ ���� ��쿡�� , Ŀ���� �� �ʿ� ����
		{
			if (a - 1 >= 0) // 1 (����)
			{
				if (arr[a - 1][b] == '1'&&d != 2)
				{
					s.push({ a - 1,b,c + 1,1 });
				}
			}
			if (a + 1 <= N - 1) // N-1�� arr�󿡼� ������ N ��ǥ 
			{
				if (arr[a + 1][b] == '1'&&d != 1) // 2 (�Ʒ���)
				{
					s.push({ a + 1,b,c + 1,2 });
				}
			}
			if (b - 1 >= 0)//3 (�·�)
			{
				if (arr[a][b - 1] == '1'&&d != 4)
				{
					s.push({ a,b - 1,c + 1,3 });
				}
			}
			if (b + 1 <= M - 1)// M-1�� arr�󿡼� ������ M
			{
				if (arr[a][b + 1] == '1'&&d != 3) // 4 (���)
				{
					s.push({ a,b + 1,c + 1,4 });
				}
			}
			if (!s.empty())
			{
				if (s.top().x == N - 1 && s.top().y == M - 1)
				{
					//break;
					if (min >= s.top().count)
					{
						min = s.top().count; // ������ ī��Ʈ�� ����Ǿ�����	
					}
					s.pop();
				}
			}
			else
				break;
		}
		if (s.empty()==1)
			break;
	}

	cout << min<<'\n';

	return 0;
}