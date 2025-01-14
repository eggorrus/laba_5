﻿#include <iostream>
#include <string>
#include <Windows.h>
#include <string.h>
#include <iomanip>

using namespace std;

const int marks = 5;


struct STUDENT
{
	string surname;
	string name;
	string dad_name;
	string group;
	int marks[marks];
};

struct group_stats
{
	string group_num;
	int badcount;
	int count;
};

struct good_stud
{
	string surname;
	string name;
	string dad_name;
	string group;
	double average;
};

int get_max_length(STUDENT students[], int N, int command) {
	int* symbols = new int[N];
	int maximum, sum=0;
		for (int i = 0; i < N; i++) {
			if (command == 1)
				symbols[i] = students[i].name.length() + students[i].surname.length() + students[i].dad_name.length() + 2;
			else if (command == 2)
				symbols[i] = students[i].group.length() + 2;
		}
		for (int i = 0; i < N; i++) {
			if (i == 0) maximum = symbols[i];
			else {
				if (symbols[i] > maximum)
					maximum = symbols[i];
			}
		}
	delete[] symbols;
	return maximum;
}

int get_max_length2(good_stud students[], int N, int command) {
	int* symbols = new int[N];
	int maximum, sum = 0;
	for (int i = 0; i < N; i++) {
		if (command == 1)
			symbols[i] = students[i].name.length() + students[i].surname.length() + students[i].dad_name.length() + 2;
		else if (command == 2)
			symbols[i] = students[i].group.length() + 2;
	}
	for (int i = 0; i < N; i++) {
		if (i == 0) maximum = symbols[i];
		else {
			if (symbols[i] > maximum)
				maximum = symbols[i];
		}
	}
	delete[] symbols;
	return maximum;
}

double average_mark(int marks[], int a) {
	double sum = 0;
	for (int i = 0; i < a; i++) {
		sum += marks[i];
	}
	return sum / (double)a;
}

void output_students1(STUDENT a[], int N) {
	for (int i = 0; i < N; i++) {
		cout << a[i].group << " - ";
		cout << a[i].surname << " ";
		cout << a[i].name << " ";
		cout << a[i].dad_name << ": ";
		for (int j = 0; j < marks - 1; j++) {
			cout << a[i].marks[j] << ", ";
		}
		cout << a[i].marks[marks - 1] << endl;
	}
}

void output_students2(good_stud good[], int N) {
	for (int i = 0; i < N; i++) {
		cout << good[i].group << ", ";
		cout << good[i].surname << " ";
		cout << good[i].name << " ";
		cout << good[i].dad_name << " - ";
		cout << good[i].average << endl;
	}
}

void sort_students(STUDENT a[], int N) {
	for (int i = 0; i < N-1; ++i) {
		for (int j = 0; j < N - i - 1; ++j) {
			if (a[j].group > a[j + 1].group) swap(a[j], a[j + 1]);
		}
	}
}

void sort_average(good_stud good[], int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (good[j].average < good[j + 1].average)
				swap(good[j], good[j + 1]);
		}
	}
}

/*void sort_average(STUDENT a[], double b[], int quantity) {
	for (int i = 0; i < quantity - 1; ++i) {
		for (int j = 0; j < quantity - i - 1; ++j) {
			if (b[j] < b[j + 1]) {
				swap(b[j], b[j + 1]);
				swap(a[j], a[j + 1]);
			}
		}
	}
}*/

static void to_null(STUDENT base[], int quantity) {
	for (int i = 0; i < quantity; i++) {
		base[i].surname = "no_name";
	}
}

STUDENT equal(STUDENT a, STUDENT b, int marks) {
	b.name = a.name;
	b.surname = a.surname;
	b.dad_name = a.dad_name;
	b.group = a.group;
	for (int i = 0; i < marks; i++) {
		b.marks[i] = a.marks[i];
	}
	return b;
}

int num_of_gr(STUDENT a[], int N) {
	int k = 0, num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i].group == a[j].group) k++;
		}
		if (k == 0) num++;
		k = 0;
	}
	return num;
}


void conform(int nums_of_gr, group_stats groups[]) {
	for (int i = 0; i < nums_of_gr - 1; ++i) {
		for (int j = 0; j < nums_of_gr - i - 1; ++j) {
			if (groups[j].badcount < groups[j+1].badcount) {
				swap(groups[j], groups[j + 1]);
			}
		}
	}
}

void final_output(int nums_of_gr, group_stats group[]) {
	for (int i = 0; i < nums_of_gr; i++) {
		cout << group[i].group_num << " - " << group[i].count << " - " << group[i].badcount << endl;
	}
}

void arr_to_null(group_stats a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i].group_num = "0";
	}
}

void arr_to_null1(group_stats groups[], int n) {
	for (int i = 0; i < n; i++) {
		groups[i].count = 0;
		groups[i].badcount = 0;
	}
}

void student_to_good(int good, STUDENT student[], good_stud goods[]) {
	for (int i = 0; i < good; i++) {
		goods[i].group = student[i].group;
		goods[i].name = student[i].name;
		goods[i].surname = student[i].surname;
		goods[i].dad_name = student[i].dad_name;
		double sum=0;
		for (int j = 0; j < marks; j++) {
			sum += student[i].marks[j];
		}
		goods[i].average = sum / marks;
	}
}

void uniq_search(STUDENT students[], int N, int nums_of_gr, group_stats group[]) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (students[i].group == students[j].group) k++;
		}
		if (k == 0) {
			for (int b = 0; b < nums_of_gr; b++) {
				if (group[b].group_num == to_string(0)) {
					group[b].group_num = students[i].group;
					break;
				}
			}
		}
		k = 0;
	}
}

void input_students(STUDENT students[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> students[i].surname;
		cin >> students[i].name;
		cin >> students[i].dad_name;
		cin >> students[i].group;
		for (int j = 0; j < marks; j++) {
			cin >> students[i].marks[j];
		}
	}
}

bool badmark_search(STUDENT students) {
	for (int i = 0; i < marks; i++) {
		if (students.marks[i] == 2)
			return true;
	}
	return false;
}

void counting_groups(int nums_of_gr, STUDENT students[], group_stats groups[], int N) {
	for (int i = 0; i < nums_of_gr; i++) {
		for (int j = 0; j < N; j++) {
			if (students[j].group == groups[i].group_num) {
				groups[i].count++;
				if (badmark_search(students[j])) groups[i].badcount++;
			}
		}
	}
}

void table1(STUDENT students[], int N) {
	cout <<setw(30)<< "Список студентов" << endl;
	cout << setfill('=') << setw(get_max_length(students, N, 1) + get_max_length(students, N, 2) + 27) << "=" << endl;
	cout << "" << setfill(' ') << "||" << setw((get_max_length(students, N, 2) / 2) + 4)<< "# группы" << setw((get_max_length(students, N, 2)/2) + 1) << "||" << setw((get_max_length(students, N, 1) / 2)+1) << "ФИО";
	cout << setw((get_max_length(students, N, 1) / 2)+2) << "||" << setw(9) << "Оценки" << setw(8) << "||" << endl;
	cout << setfill('=') << setw(get_max_length(students, N, 1) + get_max_length(students, N, 2) + 27) << "=" << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << "" << setfill(' ') << "||" << setw((get_max_length(students, N, 2) / 2) + 4) << students[i].group << setw((get_max_length(students, N, 2) / 2) + 2) << "||";
		cout << students[i].surname << " " << students[i].name << " " << students[i].dad_name << setw(get_max_length(students, N, 1) - students[i].surname.length() - students[i].name.length() - students[i].dad_name.length()) << "||";
		for (int j = 0; j < marks; j++)
			cout << "|" << students[i].marks[j] << "|";
		cout << "||" << endl;
	}
	cout << "" << setfill(' ') << "||" << setw((get_max_length(students, N, 2) / 2) + 4) << students[N-1].group << setw((get_max_length(students, N, 2) / 2) + 2) << "||";
	cout << students[N-1].surname << " " << students[N-1].name << " " << students[N-1].dad_name << setw(get_max_length(students, N, 1) - students[N-1].surname.length() - students[N-1].name.length() - students[N-1].dad_name.length()) << "||";
	for (int j = 0; j < marks; j++)
		cout << "|" << students[N-1].marks[j] << "|";
	cout << "||" << endl;
	cout << setfill('=') << setw(get_max_length(students, N, 1) + get_max_length(students, N, 2) + 27) << "=" << endl << "" << setfill(' ');
}

void table2(good_stud good[], int good_st, int N) {
	cout <<setw(30)<< "Список хорошистов" << endl;
	cout << setfill('=') << setw(get_max_length2(good, N, 1) + get_max_length2(good, N, 2) + 20) << "=" << endl;
	cout << "" << setfill(' ') << "||" << setw((get_max_length2(good, N, 2) / 2) + 4) << "# группы" << setw((get_max_length2(good, N, 2) / 2) + 1) << "||" << setw((get_max_length2(good, N, 1) / 2) + 1) << "ФИО";
	cout << setw((get_max_length2(good, N, 1) / 2) + 2) << "||" << "Ср.балл" << setw(3) << "||" << endl;
	for (int i = 0; i < good_st-1; i++) {
		cout << "||" << setw((get_max_length2(good, N, 2) / 2) + 4) << good[i].group << setw((get_max_length2(good, N, 2) / 2) + 2) << "||";
		cout << good[i].surname << " ";
		cout << good[i].name << " ";
		cout << good[i].dad_name << setw(get_max_length2(good, N, 1) - good[i].surname.length() - good[i].name.length() - good[i].dad_name.length()) << "||";
		cout << setw(7) << good[i].average;
		cout << setw(3) << "||" << endl;
	}
	cout << "||" << setw((get_max_length2(good, N, 2) / 2) + 4) << good[good_st - 1].group << setw((get_max_length2(good, N, 2) / 2) + 2) << "||";
	cout << good[good_st-1].surname << " ";
	cout << good[good_st - 1].name << " ";
	cout << good[good_st - 1].dad_name << setw(get_max_length2(good, N, 1) - good[good_st - 1].surname.length() - good[good_st - 1].name.length() - good[good_st - 1].dad_name.length()) << "||";
	cout << setw(7) << good[good_st - 1].average;
	cout << setw(3) << "||" << endl;
	cout << setfill('=') << setw(get_max_length2(good, N, 1) + get_max_length2(good, N, 2) + 20) << "=" << endl<<""<<setfill(' ');
}

void table3(int nums_of_gr, group_stats groups[]) {
	cout << setw(30) <<"Статистика групп" << endl;
	cout << setw(50) << "==================================================" << endl;
	cout << "||" << "# группы " << "|" << "Кол-во студентов " << "|" << "Кол-во двоечников " << "||" << endl;
	cout << setw(50) << "__________________________________________________" << endl;
	for (int i = 0; i < nums_of_gr - 1; i++) {
		cout << "||" << setw(6) << groups[i].group_num << setw(4) << "|" << setw(9) << groups[i].count << setw(9) << "|" << setw(10) << groups[i].badcount << setw(10) << "||" << endl;
	}
	cout << "||" << setw(6) << groups[nums_of_gr - 1].group_num << setw(4) << "|" << setw(9) << groups[nums_of_gr - 1].count << setw(9) << "|" << setw(10) << groups[nums_of_gr - 1].badcount << setw(10) << "||" << endl;
	cout << setw(50) << "==================================================" << endl;
}

bool is_good(STUDENT student) {
	if (average_mark(student.marks, marks) > 4.0) return true;
	else return false;
}

int main(int argc, char* argv[])
{
	bool is_human = false;
	if (argc <= 1 || strcmp(argv[1], "false") != 0)
		is_human = true;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	STUDENT* students;
	cin >> N;
	students = new STUDENT[N];
	input_students(students, N);
	sort_students(students, N);
	if (is_human) table1(students, N);
	else output_students1(students, N);
	STUDENT* good;
	good = new STUDENT[N];
	to_null(good, N);
	int good_st = 0;
	int bad = 0;
	for (int i = 0; i < N; i++) {
		if (is_good(students[i])) {
			good_st += 1;
			for (int j = 0; j < N; j++) {
				if (good[j].surname == "no_name") {
					good[j] = equal(students[i], good[j], marks);
					break;
				}
			}
		}
		else {
			bad++;
		}
	}
	if (bad != N) {
		good_stud* good_s = new good_stud[good_st];
		student_to_good(good_st, good, good_s);
		sort_average(good_s, good_st);
		if (is_human) table2(good_s, good_st, N);
		else output_students2(good_s, good_st);
		delete[] good_s;
	}
	else {
		if (is_human) cout << "Студентов с баллом выше 4.0 нет." << endl;
		else cout << "NO" << endl;
	}
	int nums_of_gr = num_of_gr(students, N);
	group_stats* groups = new group_stats[nums_of_gr];
	arr_to_null(groups, nums_of_gr);
	uniq_search(students, N, nums_of_gr, groups);
	arr_to_null1(groups, nums_of_gr);
	counting_groups(nums_of_gr, students, groups, N);
	conform(nums_of_gr, groups);
	if (is_human) table3(nums_of_gr, groups);
	else final_output(nums_of_gr, groups);
	delete[] groups;
	delete[] students;
	delete[] good;
}