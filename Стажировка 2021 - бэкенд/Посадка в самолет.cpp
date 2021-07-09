#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

void Print(vector<string>& arr) {
	for (string& line : arr) {
		cout << line << endl;
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> seats(n);
	cin.get();

	for (int i = 0; i < n; ++i) {
		string line;
		getline(cin, line);

		seats[i] = move(line);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num_pas;
		string side, location;
		cin >> num_pas >> side >> location;

		if (side == "left") {
			if (location == "aisle") {
				bool flag = false;
				for (int k = 0; k < seats.size(); ++k) {
					string& line = seats[k];
					int counter = 0;

					for (int s = 2; s > 2 - num_pas; s--) {
						if (line[s] == '.')
							counter++;
					}

					if (counter != num_pas)
						continue;
					else {
						flag = true;
						cout << "Passengers can take seats:";
						char c = 'C' - num_pas;
						for (int j = 0; j < num_pas; ++j) {
							cout << ' ' << k + 1 << ++c;
						}
						cout << endl;

						for (int s = 2; s > 2 - num_pas; s--) {
							line[s] = 'X';
						}

						Print(seats);

						for (int s = 2; s > 2 - num_pas; s--) {
							line[s] = '#';
						}
						break;
					}
				}

				if (!flag)
					cout << "Cannot fulfill passengers requirements\n";
			}
			else if (location == "window") {
				bool flag = false;
				for (int k = 0; k < seats.size(); ++k) {
					string& line = seats[k];
					int counter = 0;
					for (int s = 0; s < num_pas; s++) {
						if (line[s] == '.')
							counter++;
					}

					if (counter != num_pas)
						continue;
					else {
						flag = true;
						cout << "Passengers can take seats:";
						char c = 'A' - 1;
						for (int j = 0; j < num_pas; ++j) {
							cout << ' ' << k + 1 << ++c;
						}
						cout << endl;

						for (int s = 0; s < num_pas; s++) {
							line[s] = 'X';
						}

						Print(seats);

						for (int s = 0; s < num_pas; s++) {
							line[s] = '#';
						}
						break;
					}
				}
				
				if (!flag)
					cout << "Cannot fulfill passengers requirements\n";
			}
		}
		else if (side == "right") {
			if (location == "aisle") {
				bool flag = false;
				for (int k = 0; k < seats.size(); ++k) {
					string& line = seats[k];
					int counter = 0;
					for (int s = 4; s < 4 + num_pas; s++) {
						if (line[s] == '.')
							counter++;
					}

					if (counter != num_pas)
						continue;
					else {
						flag = true;
						cout << "Passengers can take seats:";
						char c = 'D' - 1;
						for (int j = 0; j < num_pas; ++j) {
							cout << ' ' << k + 1 << ++c;
						}
						cout << endl;

						for (int s = 4; s < 4 + num_pas; s++) {
							line[s] = 'X';
						}

						Print(seats);

						for (int s = 4; s < 4 + num_pas; s++) {
							line[s] = '#';
						}
						break;
					}
				}

				if (!flag)
					cout << "Cannot fulfill passengers requirements\n";
			}
			else if (location == "window") {
				bool flag = false;
				for (int k = 0; k < seats.size(); ++k) {
					string& line = seats[k];
					int counter = 0;
					for (int s = 6; s > 6 - num_pas; s--) {
						if (line[s] == '.')
							counter++;
					}

					if (counter != num_pas)
						continue;
					else {
						flag = true;
						cout << "Passengers can take seats:";
						char c = 'F' - num_pas;
						for (int j = 0; j < num_pas; ++j) {
							cout << ' ' << k + 1 << ++c;
						}
						cout << endl;

						for (int s = 6; s > 6 - num_pas; s--) {
							line[s] = 'X';
						}

						Print(seats);

						for (int s = 6; s > 6 - num_pas; s--) {
							line[s] = '#';
						}
						break;
					}
				}

				if (!flag)
					cout << "Cannot fulfill passengers requirements\n";
			}
		}
	}


	return 0;
}