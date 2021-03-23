#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

typedef tm Date;

bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.tm_year, lhs.tm_mon, lhs.tm_mday} < 
		vector<int>{rhs.tm_year, rhs.tm_mon, rhs.tm_mday};
}

Date ParseDate(const string& str) {
	istringstream stream(str);
	
	string year, month, day;
	getline(stream, year, '-');
	getline(stream, month, '-');
	getline(stream, day);

	return {0, 0, 0, stoi(day, nullptr), stoi(month, nullptr) - 1, stoi(year, nullptr) - 1900 };
}

ostream& operator<<(ostream& os, const Date& date) {
	os << 1900 + date.tm_year << '-'
		<< setw(2) << setfill('0') << 1 + date.tm_mon << '-'
		<< setw(2) << setfill('0') << date.tm_mday;

	return os;
}

int main() {
	string command;
	getline(cin, command);
	string begin_s, end_s;
	cin >> begin_s >> end_s;

	Date begin = ParseDate(begin_s), end = ParseDate(end_s);

	time_t begin_time = mktime(&begin), end_time = mktime(&end);

	ostringstream output;
	long long counter = 0;

	if (command == "WEEK") {
		int wday = (begin.tm_wday + 6) % 7;
		Date first_begin = begin, first_end;
		begin.tm_mday += 6 - wday;
		time_t time_temp = mktime(&begin);
		localtime(&time_temp);

		first_end = min(begin, end);
		
		output << first_begin << ' ' << first_end << '\n';
		counter++;

		while (begin < end) {
			Date left, right;

			begin.tm_mday += 1;
			mktime(&begin);
			left = begin;

			begin.tm_mday += 6;
			mktime(&begin);
			right = min(begin, end);

			output << left << ' ' << right << '\n';
			cout << left << ' ' << right << '\n';
			counter++;
		}
	}
	else if (command == "MONTH") {
		Date first_begin = begin, first_end;
		begin.tm_mday = 0;
		begin.tm_mon += 1;
		mktime(&begin);

		first_end = min(begin, end);

		output << first_begin << ' ' << first_end << '\n';
		counter++;

		while (begin < end) {
			Date left, right;

			begin.tm_mday += 1;
			mktime(&begin);
			left = begin;

			begin.tm_mday = 0;
			begin.tm_mon += 1;
			mktime(&begin);
			right = min(begin, end);

			output << left << ' ' << right << '\n';
			counter++;
		}
	}
	else if (command == "QUARTER") {
		int month = begin.tm_mon;
		Date first_begin = begin, first_end;

		if (0 <= month && month < 3) {
			begin.tm_mday = 0;
			begin.tm_mon = 3;
			mktime(&begin);
		}
		else if (3 <= month && month < 6) {
			begin.tm_mday = 0;
			begin.tm_mon = 6;
			mktime(&begin);
		}
		else if (6 <= month && month < 9) {
			begin.tm_mday = 0;
			begin.tm_mon = 9;
			mktime(&begin);
		}
		else if (9 <= month && month < 12) {
			begin.tm_mday = 0;
			begin.tm_mon = 12;
			mktime(&begin);
		}

		first_end = min(begin, end);

		output << first_begin << ' ' << first_end << '\n';
		counter++;

		while (begin < end) {
			Date left, right;

			begin.tm_mday += 1;
			mktime(&begin);
			mktime(&begin);
			left = begin;

			begin.tm_mday = 0;
			begin.tm_mon += 3;
			mktime(&begin);
			mktime(&begin);
			right = min(begin, end);

			output << left << ' ' << right << '\n';
			//cout << counter++ << endl;
			cout << left << ' ' << right << '\n';
			counter++;
		}
	}
	else if (command == "YEAR") {
		Date first_begin = begin, first_end;
		begin.tm_mday = 0;
		begin.tm_mon = 0;
		begin.tm_year += 1;
		mktime(&begin);

		first_end = min(begin, end);

		output << first_begin << ' ' << first_end << '\n';
		counter++;

		while (begin < end) {
			Date left, right;

			begin.tm_mday += 1;
			mktime(&begin);
			left = begin;

			begin.tm_mday = 0;
			begin.tm_mon = 0;
			begin.tm_year += 1;
			mktime(&begin);
			right = min(begin, end);

			output << left << ' ' << right << '\n';
			counter++;
		}
	}
	else if (command == "LAST_SUNDAY_OF_YEAR") {
		Date first_begin = begin, first_end;

		begin.tm_mday = 0;
		begin.tm_mon = 0;
		begin.tm_year += 1;
		mktime(&begin);

		while (begin.tm_wday != 6) {
			begin.tm_mday -= 1;
			mktime(&begin);
		}

		first_end = min(begin, end);

		output << first_begin << ' ' << first_end << '\n';
		counter++;

		while (begin < end) {
			Date left, right;

			begin.tm_mday += 1;
			mktime(&begin);
			left = begin;

			begin.tm_mday = 0;
			begin.tm_mon = 0;
			begin.tm_year += 2;
			mktime(&begin);

			while (begin.tm_wday != 6) {
				begin.tm_mday -= 1;
				mktime(&begin);
			}
			right = min(begin, end);

			output << left << ' ' << right << '\n';
			cout << left << ' ' << right << '\n';
			counter++;
		}
	}

	cout << "I'm here\n";
	cout << counter << '\n';
	cout << output.str();

	return 0;
}