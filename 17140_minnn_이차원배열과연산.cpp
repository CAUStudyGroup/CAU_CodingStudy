#include <cstdio>
#include <vector>
using namespace std;
int a[101][101];
int cnt[101];
int row = 3, col = 3;
int r, c, k;

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int time = 0;
	do {
		if (a[r][c] == k) {
			printf("%d\n", time);
			return 0;
		}
		time++;
		int max_count=0;
		vector <vector <int>> ans;
		if (row >= col) {
			for (int i = 1; i <= row; i++) {
				for (int j = 1; j <= col; j++) {
					cnt[a[i][j]]++;
				}
				for (int j = 1; j <= 100; j++) {
					if (cnt[j] != 0) {
						ans[i].push_back(j);printf("5");
						ans[i].push_back(cnt[j]); printf("6");
					}
				}
				
				for (int j = 0; j <= ans.size(); j++) {
					printf("%d ", ans[0][j]);
				}
				for (int j = 1; j < ans[i].size() / 2; j++) {
					for (int k = j; k <= ans[i].size() / 2; k++) {
						if (ans[i][j*2] > ans[i][k*2]) {
							int tmp = ans[i][j*2];
							ans[i][j * 2] = ans[i][k * 2];
							ans[i][k * 2] = tmp;
							tmp = ans[i][j * 2-1];
							ans[i][j * 2-1] = ans[i][k * 2-1];
							ans[i][k * 2-1] = tmp;
						}
					}	
				}
			}
		}/*
		for (int i = 0; i <= ans.size(); i++) {
			for (int j = 0; j <= ans[i].size(); j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		
		else {

		}*/
		memset(cnt, 0, sizeof(cnt));
	} while (1);
	return 0;
}