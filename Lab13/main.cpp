#include <iostream>
using namespace std;
#define M 25
#define N 4
void submultimi(int sum, int k, int rest, bool x[], int w[]) {

	x[k] = true;
	if (sum + w[k] == M) {
		cout << "\nResult: ";
		for (int i = 0; i <= k; i++) {
			cout << x[i] << " ";
		}
	}
	else {
		if (sum + w[k] + w[k + 1] <= M) {
			submultimi(sum + w[k], k + 1, rest - w[k], x, w);
		}
        /*
		if (sum + rest - w[k] >= M and sum + w[k + 1] <= M) {
			x[k] = 0;
			submultimi(sum, k + 1, rest - w[k], x, w);
		}
        */
	}
    if (sum + rest - w[k] >= M and sum + w[k + 1] <= M) {
			x[k] = 0;
			submultimi(sum, k + 1, rest - w[k], x, w);
		}
}
int main() {
	bool x[N] = { false };
	int w[] = { 4, 7, 11, 14 };
	int r = 0;
	for (int i = 0; i < sizeof(w) / sizeof(w[0]); i++) {
		r += w[i];
	}
	submultimi(0, 0, r, x, w);
	return 0;
}
