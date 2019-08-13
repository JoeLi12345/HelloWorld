#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	int n;
	fin >> n;
	vector < vector <int> > shifts(n, vector <int>(2, 0));
	for (int i = 0; i < n; i++) {
		fin >> shifts[i][0] >> shifts[i][1];
	}
	vector <int> time(1002, 0);
	for (int i = 0; i < n; i++) {
		for (int j = shifts[i][0]; j < shifts[i][1]; j++) {
			time[j]++;
		}
	}
	int tot = 0;
	for (int i = 0; i < 1002; i++) {
		if (time[i] > 0) {
			tot++;
		}
	}
	vector <int> firetime(n, 0);
	for (int i = 0; i < n; i++) {
		firetime[i] = tot;
	}
	for (int i = 0; i < n; i++) {
		for (int j = shifts[i][0]; j < shifts[i][1]; j++) {
			if (time[j] - 1 == 0) {
				firetime[i]--;
			}
		}
	}
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (firetime[i] >= max) {
			max = firetime[i];
		}
	}
	fout << max;
}
