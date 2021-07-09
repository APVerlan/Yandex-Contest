#include <iostream>
#include <string>
#include <valarray>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

const double delta = 10e-10;
using namespace std;

bool EqualToZero(double d) {
	if (d > 0 && d - delta < 0) return true;
	else if (d < 0 && d + delta > 0) return true;
	else if (d + delta > 0 && d - delta < 0) return true;
	else return false;
}
int main() {
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	vector<valarray<double>> matrix(2, valarray<double>(3));
	
	matrix[0][0] = a;
	matrix[0][1] = b;
	matrix[0][2] = e;
	matrix[1][0] = c;
	matrix[1][1] = d;
	matrix[1][2] = f;

	double det = a * d - c * b;
	if ((EqualToZero(a) && EqualToZero(b) && !EqualToZero(e)) || (EqualToZero(c) && EqualToZero(d) && !EqualToZero(f)))
		cout << 0;
	else if (EqualToZero(a) && EqualToZero(b) && EqualToZero(f) && EqualToZero(c) && EqualToZero(d) && EqualToZero(e))
		cout << 5;
	else if (!EqualToZero(det) ) {
		cout << 2 << ' ' << (EqualToZero((e * d - b * f) / det) ? 0 : (e * d - b * f) / det)
			<< ' ' << (EqualToZero((a * f - c * e) / det) ? 0 : (a * f - c * e) / det);
	} else {
		if (EqualToZero(a) && EqualToZero(b))
			swap(matrix[0], matrix[1]);

		if (!EqualToZero(matrix[0][0])) {
			matrix[1] -= matrix[1][0] / matrix[0][0] * matrix[0];

			if (EqualToZero(matrix[1][0]) && EqualToZero(matrix[1][1]) && EqualToZero(matrix[1][2])) {
				if (!EqualToZero(matrix[0][1])) {
					cout << 1 << ' ' << - matrix[0][0] / matrix[0][1] << ' ' << matrix[0][2] / matrix[0][1];
				}
				else {
					cout << 3 << ' ' << matrix[0][2] / matrix[0][0];
				}
			}
			else if (EqualToZero(matrix[1][0]) && EqualToZero(matrix[1][1]) && !EqualToZero(matrix[1][2])) {
				cout << 0;
			}
		}
		else {
			matrix[1] -= matrix[1][1] / matrix[0][1] * matrix[0];

			if (EqualToZero(matrix[1][0]) && EqualToZero(matrix[1][1]) && EqualToZero(matrix[1][2])) {
					cout << 4 << ' ' << matrix[0][2] / matrix[0][1];
			}
			else if (EqualToZero(matrix[1][0]) && EqualToZero(matrix[1][1]) && !EqualToZero(matrix[1][2])) {
				cout << 0;
			}
		}
	}

	return 0;
}