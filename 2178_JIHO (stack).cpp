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
		cin >> arr[i]; //배열 초기화
	}
	
	s.push({ 0,0,1,0 });

	int run = 1;
	while (run == 1)
	{
		int a = s.top().x; 
		int b = s.top().y;
		int c = s.top().count;
		int d = s.top().stat;

		s.pop(); // 스스로는 정보만 전달하고 pop

		if (min > c) // 이동은 최적의 횟수보다 작은 경우에만 , 커지면 할 필요 없음
		{
			if (a - 1 >= 0) // 1 (위로)
			{
				if (arr[a - 1][b] == '1'&&d != 2)
				{
					s.push({ a - 1,b,c + 1,1 });
				}
			}
			if (a + 1 <= N - 1) // N-1은 arr상에선 실제로 N 좌표 
			{
				if (arr[a + 1][b] == '1'&&d != 1) // 2 (아래로)
				{
					s.push({ a + 1,b,c + 1,2 });
				}
			}
			if (b - 1 >= 0)//3 (좌로)
			{
				if (arr[a][b - 1] == '1'&&d != 4)
				{
					s.push({ a,b - 1,c + 1,3 });
				}
			}
			if (b + 1 <= M - 1)// M-1은 arr상에선 실제로 M
			{
				if (arr[a][b + 1] == '1'&&d != 3) // 4 (우로)
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
						min = s.top().count; // 지금의 카운트가 저장되어있음	
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