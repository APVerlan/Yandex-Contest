#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class BankTransactionSystem {
public:
	void Deposit(const string& name, int sum) { db[name] += sum; }
	void Withdraw(const string& name, int sum) { db[name] -= sum; }
	long long Balance(const string& name) const { return db.at(name); }
	
	void Transfer(const string& from, const string& to, int sum) {
		db[from] -= sum;
		db[to] += sum;
	}
	void Income(int p) {
		for (auto& [key, val] : db) {
			if (val > 0)
				val += (val * p) / 100;
		}
	}

	bool InSystem(const string& name) { return db.count(name); }

private:
	unordered_map<string, long long> db;
};

int main() {
	int n;
	string op;

	BankTransactionSystem sys;

	while (cin >> op) { 
		if (op == "DEPOSIT") {
			int sum;
			string name;

			cin >> name >> sum;
			sys.Deposit(name, sum);
		}
		else if (op == "INCOME") {
			int p;
			cin >> p;

			sys.Income(p);
		}
		else if (op == "BALANCE") {
			string name;
			cin >> name;
			if (sys.InSystem(name))
				cout << sys.Balance(name) << endl;
			else cout << "ERROR\n";
		}
		else if (op == "TRANSFER") {
			string from, to;
			int sum;
			cin >> from >> to >> sum;

			sys.Transfer(from, to, sum);
		}
		else if (op == "WITHDRAW") {
			int sum;
			string name;

			cin >> name >> sum;
			sys.Withdraw(name, sum);
		}
	}


	return 0;
}