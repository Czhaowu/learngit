#include <iostream>
#include <algorithm>
#define maxn 300010
using namespace std;
int n, x;
int v[40] = { 0 };
int f[40][maxn] = { {0} };

int main()
{
	cin >> n >> x;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	int y = sum - x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= y; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) {
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i]);
			}
		}
	}
	int r = sum - f[n][y];
	cout << r << endl;
	return 0;
}