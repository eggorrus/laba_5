#include <iostream>
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

void output_students2(STUDENT a[], int N, double average[]) {
	for (int i = 0; i < N; i++) {
		cout << a[i].group << ", ";
		cout << a[i].surname << " ";
		cout << a[i].name << " ";
		cout << a[i].dad_name << " - ";
		cout << average[i] << endl;
	}
}

void sort_students(STUDENT a[], int N) {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - i - 1; ++j) {
			if (a[j].group > a[j + 1].group) swap(a[j], a[j + 1]);
		}
	}
}

void sort_average(STUDENT a[], double b[], int quantity) {
	for (int i = 0; i < quantity - 1; ++i) {
		for (int j = 0; j < quantity - i - 1; ++j) {
			if (b[j] < b[j + 1]) {
				swap(b[j], b[j + 1]);
				swap(a[j], a[j + 1]);
			}
		}
	}
}

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

bool pass(double N) {
	if (N >= 4.0) return true;
	else return false;
}



void conform(int nums_of_gr, string a[], int b[], int badcount[]) {
	for (int i = 0; i < nums_of_gr - 1; ++i) {
		for (int j = 0; j < nums_of_gr - i - 1; ++j) {
			if (badcount[j] < badcount[j + 1]) {
				swap(badcount[j], badcount[j + 1]);
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
			}
		}
	}
}

void final_output(int nums_of_gr, string a[], int b[], int badcount[]){
	for (int i = 0; i < nums_of_gr; i++) {
		cout << a[i] << " - " << b[i] << " - " << badcount[i] << endl;
	}
}

void counting_groups(int nums_of_gr, STUDENT students[], string a[], int b[], int badcount[], int N) {
	for (int i = 0; i < nums_of_gr; i++) {
		for (int j = 0; j < N; j++) {
			if (students[j].group == a[i]) {
				b[i]++;
				if (!pass(average_mark(students[j].marks, marks))) badcount[i]++;
			}
		}
	}
}

void arr_to_null(string a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = "0";
	}
}

void arr_to_null1(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
}


void uniq_search(STUDENT students[], int N, int nums_of_gr, string a[]) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (students[i].group == students[j].group) k++;
		}
		if (k == 0) {
			for (int b = 0; b < nums_of_gr; b++) {
				if (a[b] == to_string(0)) {
					a[b] = students[i].group;
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

void table1(STUDENT students[], int N) {
	cout << setw(48)<<"Список студентов" << endl;
	cout << setw(80) << "================================================================================" << endl;
	cout << "||" << "# группы |" << " ФИО студента" <<setw(35)<<" |" <<"Успеваемость" << setw(8)<<"||" << endl;
	cout << setw(80) << "________________________________________________________________________________" << endl;
	for (int i = 0; i < N; i++) {
		cout << "||" << students[i].group << setw(6)<<"|";
		cout << students[i].surname << " ";
		cout << students[i].name << " ";
		cout << students[i].dad_name << setw(49 - size(students[i].name) - size(students[i].surname) - size(students[i].dad_name) - 3);
		cout << "|" << students[i].marks[0];
		for (int j = 1; j < marks-1; j++) {
			cout << "||" << students[i].marks[j];
		}
		cout <<"||"<< students[i].marks[marks - 1] << "|";
		cout << setw(6) << "||" << endl;
	}
	cout << setw(80) << "================================================================================" << endl;
}

void table2(STUDENT students[], int good_st, double averages[]) {
	string a;
	cout <<endl<< setw(33) << "Список хорошистов" << endl;
	cout << setw(70) << "=====================================================================" << endl;
	cout << "||" << "# группы |" << " ФИО студента" << setw(25) << " |" << "Средний балл" << setw(8) << "||" << endl;
	cout << setw(70) << "_____________________________________________________________________" << endl;
	for (int i = 0; i < good_st-1; i++) {
		cout << "||" << students[i].group << setw(6) << "|";
		cout << students[i].surname << " ";
		cout << students[i].name << " ";
		cout << students[i].dad_name << setw(39 - size(students[i].name) - size(students[i].surname) - size(students[i].dad_name) - 3);
		cout << "|" << setw(10) << averages[i];
		a = to_string(averages[i]);
		cout << setw(18 - size(a)) << "||" << endl;
	}
	cout << "||" << students[good_st-1].group << setw(6) << "|";
	cout << students[good_st - 1].surname << " ";
	cout << students[good_st - 1].name << " ";
	cout << students[good_st-1].dad_name << setw(39 - size(students[good_st-1].name) - size(students[good_st - 1].surname) - size(students[good_st - 1].dad_name) - 3);
	cout << "|" << setw(10) << averages[good_st - 1];
	a = to_string(averages[good_st - 1]);
	cout << setw(18 - size(a)) << "||" << endl;
	cout << setw(70) << "=====================================================================" << endl;
}

void table3(int nums_of_gr, string a[], int b[], int badcount[]) {
	cout << setw(30) <<"Статистика групп" << endl;
	cout << setw(50) << "==================================================" << endl;
	cout << "||" << "# группы " << "|" << "Кол-во студентов " << "|" << "Кол-во двоечников " << "||" << endl;
	cout << setw(50) << "__________________________________________________" << endl;
	for (int i = 0; i < nums_of_gr - 1; i++) {
		cout << "||" << setw(6) << a[i] << setw(4) << "|" << setw(9) << b[i] << setw(9) << "|" << setw(10) << badcount[i] << setw(10) << "||" << endl;
	}
	cout << "||" << setw(6) << a[nums_of_gr - 1] << setw(4) << "|" << setw(9) << b[nums_of_gr - 1] << setw(9) << "|" << setw(10) << badcount[nums_of_gr - 1] << setw(10) << "||" << endl;
	cout << setw(50) << "==================================================" << endl;
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
	for (int i = 0; i < N; i++) {
		if (average_mark(students[i].marks, marks) >= 4.0) {
			good_st += 1;
			for (int j = 0; j < N; j++) {
				if (good[j].surname == "no_name") {
					good[j] = equal(students[i], good[j], marks);
					break;
				}
			}
		}
		else continue;
	}
	double* averages;
	averages = new double[good_st];
	for (int i = 0; i < good_st; i++) {
		averages[i] = average_mark(good[i].marks, marks);
	}
	sort_average(good, averages, good_st);
	if (is_human) table2(good, good_st, averages);
	else output_students2(good, good_st, averages);
	delete[] averages;
	int nums_of_gr = num_of_gr(students, N);
	string* a;
	a = new string[nums_of_gr];
	arr_to_null(a, nums_of_gr);
	uniq_search(students, N, nums_of_gr, a);
	int* b, *badcount;
	b = new int[nums_of_gr];
	badcount = new int[nums_of_gr];
	arr_to_null1(badcount, nums_of_gr);
	arr_to_null1(b, nums_of_gr);
	counting_groups(nums_of_gr, students, a, b, badcount, N);
	conform(nums_of_gr, a, b, badcount);
	if (is_human) table3(nums_of_gr, a, b, badcount);
	else final_output(nums_of_gr, a, b, badcount);
	delete[] a;
	delete[] b;
	delete[] badcount;
	delete[] students;
	delete[] good;
}
