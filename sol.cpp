#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	// edge case 1: if 'n' and 'm' are equal, then output 0
	if (n == m) {
		cout << 0 << '\n';
		return 0;
	}
	// edge case 2: if 'm' is 0, then output 1
	if (m == 0) {
		cout << 1 << '\n';
		return 0;
	}
	// view the image in this repository for better understanding
	// mark all the even positions 'm' times
	vector<int> visited(n, true);
	for (int i = 0; i < n; i++) {
		if (m > 0 && (i + 1) % 2 == 0) {
			visited[i] = false;
			m--;
		}
	}
	// if 'm' is still not equal to 0, then mark the odd positions
	for (int i = n - 1; i >= 0; i--) {
		if (m > 0 && visited[i]) {
			visited[i] = false;
			m--;
		}
	}
	// count the sub-segments that contain true values
	int cnt = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (visited[i] && !visited[i + 1]) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
