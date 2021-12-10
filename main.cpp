#include <iostream>
#include <cstring>
#include <vector>
#define red vector<int>

using namespace std;

vector<red> redovi = {};
int n, m, q;
int loop[1005][1005];
int save[1005][1005];
int res[5000000];

int rek(int a, int b) {
	if (save[a][b] != 0) {
		return save[a][b] - 1;
	}
	if (loop[a][b]) {
		save[a][b] = 1;
		return 0;
	}
	loop[a][b] = 1;
	if (a == b) {
		save[a][b] = 2;
		return 1;
	}
	for (red r : redovi) {
		if (rek(r[a - 1], b)) {
			save[a][b] = 2;
			return 1;
		}
	}
	save[a][b] = 1;
	return 0;
}

int main(void) {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		red r = {};
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			r.push_back(a);
		}
		redovi.push_back(r);
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		res[i] = rek(a, b);
		memset(loop, 0, sizeof loop);
	}
	for (int i = 0; i < q; i++) {
		if (res[i]) {
			cout << "DA\n";
		}
		else {
			cout << "NE\n";
		}
	}
	return 0;
}
