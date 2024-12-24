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
	for (int i = 0; i < N-1; ++i) {
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

bool badmark_search(STUDENT students) {
	for (int i = 0; i < marks; i++) {
		if (students.marks[i] == 2)
			return true;
	}
	return false;
}

void counting_groups(int nums_of_gr, STUDENT students[], string a[], int b[], int badcount[], int N) {
	for (int i = 0; i < nums_of_gr; i++) {
		for (int j = 0; j < N; j++) {
			if (students[j].group == a[i]) {
				b[i]++;
				if (badmark_search(students[j])) badcount[i]++;
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

void table2(STUDENT students[], int good_st, double averages[], int N) {
	cout <<setw(30)<< "Список хорошистов" << endl;
	cout << setfill('=') << setw(get_max_length(students, N, 1) + get_max_length(students, N, 2) + 20) << "=" << endl;
	cout << "" << setfill(' ') << "||" << setw((get_max_length(students, N, 2) / 2) + 4) << "# группы" << setw((get_max_length(students, N, 2) / 2) + 1) << "||" << setw((get_max_length(students, N, 1) / 2) + 1) << "ФИО";
	cout << setw((get_max_length(students, N, 1) / 2) + 2) << "||" << "Ср.балл" << setw(3) << "||" << endl;
	for (int i = 0; i < good_st-1; i++) {
		cout << "||" << setw((get_max_length(students, N, 2) / 2) + 4) << students[i].group << setw((get_max_length(students, N, 2) / 2) + 2) << "||";
		cout << students[i].surname << " ";
		cout << students[i].name << " ";
		cout << students[i].dad_name << setw(get_max_length(students, N, 1) - students[i].surname.length() - students[i].name.length() - students[i].dad_name.length()) << "||";
		cout << setw(7) << averages[i];
		cout << setw(3) << "||" << endl;
	}
	cout << "||" << setw((get_max_length(students, N, 2) / 2) + 4) << students[good_st - 1].group << setw((get_max_length(students, N, 2) / 2) + 2) << "||";
	cout << students[good_st-1].surname << " ";
	cout << students[good_st - 1].name << " ";
	cout << students[good_st - 1].dad_name << setw(get_max_length(students, N, 1) - students[good_st - 1].surname.length() - students[good_st - 1].name.length() - students[good_st - 1].dad_name.length()) << "||";
	cout << setw(7) << averages[good_st - 1];
	cout << setw(3) << "||" << endl;
	cout << setfill('=') << setw(get_max_length(students, N, 1) + get_max_length(students, N, 2) + 20) << "=" << endl<<""<<setfill(' ');
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

bool is_good(STUDENT student) {
	if (average_mark(student.marks, marks) >= 4.0) return true;
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
		double* averages;
		averages = new double[good_st];
		for (int i = 0; i < good_st; i++) {
			averages[i] = average_mark(good[i].marks, marks);
		}
		sort_average(good, averages, good_st);
		if (is_human) table2(good, good_st, averages, N);
		else output_students2(good, good_st, averages);
		delete[] averages;
	}
	else {
		if (is_human) cout << "Студентов с баллом выше 4.0 нет." << endl;
		else cout << "NO" << endl;
	}
	int nums_of_gr = num_of_gr(students, N);
	string* a;
	a = new string[nums_of_gr];
	arr_to_null(a, nums_of_gr);
	uniq_search(students, N, nums_of_gr, a);
	int* q_of_st, *badcount;
	q_of_st = new int[nums_of_gr];
	badcount = new int[nums_of_gr];
	arr_to_null1(badcount, nums_of_gr);
	arr_to_null1(q_of_st, nums_of_gr);
	counting_groups(nums_of_gr, students, a, q_of_st, badcount, N);
	conform(nums_of_gr, a, q_of_st, badcount);
	if (is_human) table3(nums_of_gr, a, q_of_st, badcount);
	else final_output(nums_of_gr, a, q_of_st, badcount);
	delete[] a;
	delete[] q_of_st;
	delete[] badcount;
	delete[] students;
	delete[] good;
}