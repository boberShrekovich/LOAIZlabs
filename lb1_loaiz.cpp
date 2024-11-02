#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <conio.h>
#include <windows.h>

using namespace std;
//
//int main(){
//	setlocale(LC_ALL, "");
//	//int mass[10] = {}, max = INT_MIN, min = INT_MAX;
//	int* mass;
//	int n, max = INT_MIN, min = INT_MAX, g1, g2;
//
//	cout << "Введите кол-во элементов массива: ";
//	cin >> n;
//	cout << endl;
//
//	mass = (int*)malloc(n * sizeof(int));
//
//	cout << "Введите нижнюю границу для создания рандомных чисел: ";
//	cin >> g1;
//	cout << endl << "Введите верхнюю границу для создания рандомных чисел: ";
//	cin >> g2;
//	cout << endl;
//
//	for (int i = 0; i < n; i++) {
//		
//		mass[i] = g1 + rand() % (g2 - g1 + 1);
//		cout << mass[i] << endl;
//
//		if (mass[i] > max)
//			max = mass[i];
//		if (mass[i] < min)
//			min = mass[i];
//	}
//	cout << "Min: " << min << endl << "Max: " << max << endl << "RAZN: " << max - min << endl;
//
//	free(mass);
//
//	return 0;
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////




int main() {
	setlocale(LC_ALL, "");

	int rows, colls, g1, g2;
	//int max = INT_MIN, min = INT_MAX;
	//int sumI, sumJ;

	cout << "Введите количество строк: ";
	cin >> rows;
	cout << endl << "Введите количество столбцов: ";
	cin >> colls;
	cout << endl;

	//int** mass;
	//mass = (int**)malloc(rows * sizeof(int));
	//for (int i = 0; i < rows; i++) {
	//	mass[i] = (int*)malloc(colls * sizeof(int));
	//}

	int** mass = new int*[rows];
	for (int i = 0; i < rows; i++)
		mass[i] = new int[colls];

	
	cout << "Введите нижнюю границу для создания рандомных чисел: ";
	cin >> g1;
	cout << endl << "Введите верхнюю границу для создания рандомных чисел: ";
	cin >> g2;
	cout << endl;


	//ДО

	//for (int i = 0; i < rows; i++) {
	//	for (int j = 0; j < colls; j++) {
	//		mass[i][j] = g1 + rand() % (g2 - g1 + 1);
	//		cout << mass[i][j] << " ";
	//	}
	//}


	//cout << endl << "Суммы по строкам: " << endl;
	//for (int i = 0; i < rows; i++) {
	//	sumI = 0;
	//	for (int j = 0; j < colls; j++) {
	//		sumI += mass[i][j];
	//	}
	//	cout << "Сумма строки " << i + 1 << ": " << sumI << endl;
	//}


	//cout << "Суммы по столбцам: " << endl;
	//for (int i = 0; i < colls; i++) {
	//	sumJ = 0;
	//	for (int j = 0; j < rows; j++) {
	//		sumJ += mass[i][j];
	//	}
	//	cout << "Сумма столбца " << i + 1 << ": " << sumJ << endl;

	//}
	srand(time(0));

	int* sumI = new int[rows]();
	int* sumJ = new int[colls]();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			mass[i][j] = g1 + rand() % (g2 - g1 + 1);
			cout << mass[i][j] << " ";
			sumI[i] += mass[i][j]; // Сумма по строкам
			sumJ[j] += mass[i][j]; // Сумма по столбцам
		}
		cout << endl;
	}


	cout << "Суммы по строкам: " << endl;
	for (int i = 0; i < rows; i++) {
		cout << "Сумма строки " << i + 1 << ": " << sumI[i] << endl;
	}


	cout << "Суммы по столбцам: " << endl;
	for (int j = 0; j < colls; j++) {
		cout << "Сумма столбца " << j + 1 << ": " << sumJ[j] << endl;
	}


	for (int i = 0; i < rows; i++) {
		delete[] mass[i];
	}

	delete[] mass;
	delete[] sumI; 
	delete[] sumJ; 

	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////




//int main() {
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	const int count = 3; //кол-во студентов
//
//	struct student {
//		string name;
//		string surname;
//		int age;
//		string faculty;
//		int course;
//	}students[count];
//
//	for (int i = 0; i < count; i++) {
//		cout << "Введите имя студента: " ;
//		cin >> students[i].name;
//		cout << endl;
//
//		cout << "Введите фамилию студента: ";
//		cin >> students[i].surname;
//		cout << endl;
//
//		cout << "Введите возраст студента: ";
//		cin >> students[i].age;
//		cout << endl;
//		
//		cout << "Введите факультет студента: ";
//		cin >> students[i].faculty;
//		cout << endl;
//
//		cout << "Введите номер курса студента: ";
//		cin >> students[i].course;
//		cout << endl << endl;
//
//		//system("cls");
//	}
//	system("cls");
//
//
//	/*cout << "СТРУКТУРА СТУДЕНТОВ" << endl;
//	for (int i = 0; i < count; i++) {
//		cout << "№ " << i + 1 << " - " << students[i].name << " " << students[i].surname << " " << students[i].age << " " << students[i].faculty << " " << students[i].course << endl;
//	}
//	cout << endl;
//	system("pause");*/
//
//
//	char ch;
//	do {
//		system("cls");
//
//		cout << "СТРУКТУРА СТУДЕНТОВ" << endl;
//		for (int i = 0; i < count; i++) {
//			cout << "№ " << i + 1 << " - " << students[i].name << " " << students[i].surname << ", Возраст: " << students[i].age << ", Факультет: " << students[i].faculty << ", Номер курса: " << students[i].course << endl;
//		}
//		cout << endl << endl;
//
//		cout << "ПОИСК" << endl;
//		cout << endl;
//		cout << "1. Имя студента " << endl << "2. Фамилия студента " << endl << "3. Возраст студента " << endl << "4. Факультет студента " << endl << "5. Номер курса студента " << endl << "ESC. Выход " << endl;
//		
//		
//		// system("pause");
//
//		ch = _getch();
//
//		switch (ch) {
//
//		case '1': {
//			system("cls");
//
//			string name;
//			bool fn = false;
//			cout << "Введите имя студента: ";
//			cin >> name;
//			cout << endl;
//			for (int i = 0; i < count; i++) {
//				if (students[i].name == name) {
//					cout << "Студент найден. Номер структуры, которой соответствует это имя: " << i + 1 << endl;
//					fn = true;
//				}
//			}
//			if (!fn)
//				cout << "Ошибка!!! Студент с таким именем не найден. Попроюуйте другое имя." << endl;
//
//			system("pause");
//
//			break;
//			}
//
//		case '2': {
//			system("cls");
//
//			string surname;
//			bool fn = false;
//			cout << "Введите фамилию студента: ";
//			cin >> surname;
//			cout << endl;
//			for (int i = 0; i < count; i++) {
//				if (students[i].surname == surname) {
//					cout << "Студент найден. Номер структуры, которой соответствует эта фамилия: " << i + 1 << endl;
//					fn = true;
//				}
//			}
//			if (!fn)
//				cout << "Ошибка!!! Студент с такой фамилией не найден. Попроюуйте другую фамилию." << endl;
//
//			system("pause");
//
//			break;
//			}
//
//		case '3': {
//			system("cls");
//
//			int age;
//			bool fn = false;
//			cout << "Введите возраст студента: ";
//			cin >> age;
//			cout << endl;
//			for (int i = 0; i < count; i++) {
//				if (students[i].age == age) {
//					cout << "Студент найден. Номер структуры, которой соответствует этот возраст: " << i + 1 << endl;
//					fn = true;
//				}
//			}
//			if (!fn)
//				cout << "Ошибка!!! Студент с таким возрастом не найден. Попроюуйте другой возраст." << endl;
//
//			system("pause");
//
//			break;
//			}
//
//		case '4': {
//			system("cls");
//
//			string faculty;
//			bool fn = false;
//			cout << "Введите факультет студента: ";
//			cin >> faculty;
//			cout << endl;
//			for (int i = 0; i < count; i++) {
//				if (students[i].faculty == faculty) {
//					cout << "Студент найден. Номер структуры, которой соответствует этот факультет: " << i + 1 << endl;
//					fn = true;
//				}
//			}
//			if (!fn)
//				cout << "Ошибка!!! Студент с таким факультетом не найден. Попроюуйте другой факультет." << endl;
//
//			system("pause");
//
//			break;
//			}
//
//		case '5': {
//			system("cls");
//
//			int course;
//			bool fn = false;
//			cout << "Введите курс студента: ";
//			cin >> course;
//			cout << endl;
//			for (int i = 0; i < count; i++) {
//				if (students[i].course == course) {
//					cout << "Студент найден. Номер структуры, которой соответствует этот курс: " << i + 1 << endl;
//					fn = true;
//				}
//			}
//			if (!fn)
//				cout << "Ошибка!!! Студент с таким курсом не найден. Попроюуйте другое курс." << endl;
//
//			system("pause");
//
//			break;
//			}
//		}
//
//
//	} while (ch != 27);
//
//	return 0;
//}

