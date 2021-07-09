#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

enum class UNITS {g, kg, l, ml, cnt, tens};

struct Value {
	int value;
	string unit;
};

Value operator*(const Value val, int n) { return { val.value * n, val.unit }; }

Value operator+(const Value lhs, const Value rhs) {
	if (lhs.unit == rhs.unit)
		return { lhs.value + rhs.value, lhs.unit };

	if (lhs.unit == "g" || lhs.unit == "kg") {
		if (lhs.unit > rhs.unit)
			return { lhs.value + rhs.value * 1000, lhs.unit };
		else return { lhs.value * 1000 + rhs.value, rhs.unit};
	}

	if (lhs.unit == "l" || lhs.unit == "ml") {
		if (lhs.unit > rhs.unit)
			return { lhs.value + rhs.value * 1000, lhs.unit };
		else return { lhs.value * 1000 + rhs.value, rhs.unit };
	}

	if (lhs.unit == "cnt" || lhs.unit == "tens") {
		if (lhs.unit > rhs.unit)
			return { lhs.value + rhs.value * 10, lhs.unit };
		else return { lhs.value * 10 + rhs.value, rhs.unit };
	}

}

struct Charact {
	float pr, f, ch, fv;
};

Charact operator*(const Charact val, int n) { return { val.pr * n, val.f * n,
	val.ch * n, val.fv * n };
}

Charact operator+(const Charact lhs, const Charact rhs) {
	return { lhs.pr + rhs.pr, lhs.f + rhs.f,
	lhs.ch + rhs.ch, lhs.fv + rhs.fv };
}

struct IngrPrice {
	string name;
	int price;
	int value;
	string unit;
};

struct IngrCharact {
	string name;
	int value;
	string unit;
	Charact charact;
};

struct Element {
	string name;
	string unit;
	int value;
};

int main() {
	int n;
	cin >> n;

	unordered_map<string, vector<Element>> dishes;
	unordered_map<string, int> number_dishes;
	
	for (int i = 0; i < n; ++i) {
		string name;
		int num, num_elements;
		cin >> name >> num >> num_elements;

		number_dishes[name] = num;

		for (int i = 0; i < num_elements; ++i) {
			string name_element, unit;
			int value;
			cin >> name_element >> value >> unit;

			dishes[name].push_back({ name_element, unit, value });
		}
	}

	unordered_map<string, IngrPrice> ingr_to_price;
	unordered_map<string, IngrCharact> ingr_to_charact;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, unit;
		int price, value;
		cin >> name >> price >> value >> unit;

		ingr_to_price[name] = {name, price, value, unit};
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, unit;
		int value;
		float pr, f, ch, fv;
		cin >> name >> value >> unit 
			>> pr >> f >> ch >> fv;

		ingr_to_charact[name] = { name, value, unit, {pr, f, ch, fv} };
	}

	unordered_map<string, Charact> dish_char;
	unordered_map<string, Value> ingr_count;

	for (auto& pr : dishes ) {
		for (auto& ingridient : pr.second) {
			Value val = { ingridient.value, ingridient.unit };
			if (!ingr_count.count(ingridient.name))
				ingr_count[ingridient.name] = val * number_dishes[pr.first];
			else ingr_count[ingridient.name] = ingr_count[ingridient.name] + val * number_dishes[pr.first];

			
			if (!dish_char.count(pr.first))
				dish_char[pr.first] = ingr_to_charact[ingridient.name].charact;
			else dish_char[pr.first] = dish_char[pr.first] + ingr_to_charact[ingridient.name].charact;
		}

		//dish_char[pr.first] = dish_char[pr.first] * number_dishes[pr.first];
	}

	int total_cost = 0;
	unordered_map<string, int> total_ingr_count;
	for (auto& pr : ingr_count) {
		int count;
		if (pr.second.unit == ingr_to_price[pr.first].unit) {
			int c = pr.second.value / ingr_to_price[pr.first].value;
			count = (pr.second.value % ingr_to_price[pr.first].value) ? c + 1 : c;
		}
		else {
			string unit = ingr_to_price[pr.first].unit, unit_ingr = pr.second.unit;
			if (unit == "g" || unit == "kg") {
				if (unit > unit_ingr) {
					int val = pr.second.value;
					int c = val * 1000 / ingr_to_price[pr.first].value;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
				else {
					int val = pr.second.value ;
					int c = val / 1000 / ingr_to_price[pr.first].value;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
					
			}

			if (unit == "l" || unit == "ml") {
				if (unit > unit_ingr) {
					int val = pr.second.value;
					int c = val * 1000 / ingr_to_price[pr.first].value;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
				else {
					int val = pr.second.value;
					int c = val / ingr_to_price[pr.first].value / 1000;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
			}

			if (unit == "cnt" || unit == "tens") {
				if (unit > unit_ingr) {
					int val = pr.second.value ;
					int c = val * 10 / ingr_to_price[pr.first].value;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
				else {
					int val = pr.second.value ;
					int c = val / 10 / ingr_to_price[pr.first].value;
					count = (val % ingr_to_price[pr.first].value) ? c + 1 : c;
				}
			}
		}
		
		total_ingr_count[pr.first] = count;
		total_cost += count * ingr_to_price[pr.first].price;
	}

	cout << total_cost << endl;
	for (auto p : total_ingr_count) {
		cout << p.first << ' ' << p.second << endl;
	}
	for (auto p : dish_char) {
		cout << p.first << ' ' << p.second.pr << ' ' << p.second.f
			<< ' ' << p.second.ch << ' ' << p.second.fv << endl;
	}

	return 0;
}