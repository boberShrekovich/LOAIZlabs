#include <iostream>
#include <time.h>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;
/*
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
    setlocale(LC_ALL, "");

	clock_t start, end; // объявляем переменные для определения времени выполнения
	
	int rows = 100;
	int colls = 100;

	int** matrA;	

	matrA = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++){
		matrA[i] = (int*)malloc(sizeof(int) * colls);
	}
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			matrA[i][j] = rand() % 101 + 1;

		}

	}


	int** matrB;

	matrB = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrB[i] = (int*)malloc(sizeof(int) * colls);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			matrB[i][j] = rand() % 101 + 1;
		}

	}


	int k;
	int** matrC;

	matrC = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrC[i] = (int*)malloc(sizeof(int) * colls);
	}

	int r;

	start = clock();
	//cout << start / CLOCKS_PER_SEC;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			k = 0;
			for (r = 0; r < rows; r++){
				k = k + matrA[i][r] * matrB[r][j];
				matrC[i][j] = k;
			}
		}
		
	}

	end = clock();
	cout << endl << (end - start) / 1000.0 << endl;

    for (int i = 0; i < rows; i++) 
        free(matrA[i]);

	free(matrA);

    for (int i = 0; i < rows; i++) 
        free(matrB[i]);

	free(matrB);

    for (int i = 0; i < rows; i++) 
        free(matrC[i]);

	free(matrC);


	return(0);
}

*/


// Функция сравнения для qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


void shell(int* items, int count){

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}


void qs(int* items, int left, int right) { //вызов функции: qs(items, 0, count-1);

    int i, j;
    int x, y;



    i = left; j = right;

    //выбор компаранда
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}



int main(void) {
    setlocale(LC_ALL, "");

    clock_t start, end;

    int* mass;
    int n = 50011;
    int half = n / 2;

    mass = (int*)malloc(n * sizeof(int));

    char ch;

    do {
        system("cls");

        cout << "МЕНЮ" << endl;
        cout << "1. Случайный набор" << endl << "2. Возрастающая последовательность" << endl << "3. Убывающая последовательность" << endl << "4. Половина - возрастающая, половина - убывающая" << endl << "5. Случайный набор (qsort)" << endl << "6. Возрастающая последовательность (qsort)" << endl << "7. Убывающая последовательность (qsort)" << endl << "8. Половина - возрастающая, половина - убывающая (qsort)" << endl;

        ch = _getch();

        switch (ch) {
        case '1':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, 1000);
            //qs(mass, 0, n - 1);
            end = clock();
         
            cout << endl << "Время сортировки (1000): " << (end - start) / 1000.0 << " секунд" << endl;


            for (int i = 0; i < 10001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, 10000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки (10000): " << (end - start) / 1000.0 << " секунд" << endl;


            for (int i = 0; i < 50001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, 50000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки (50000): " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '2':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, 1000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки (1000): " << (end - start) / 1000.0 << " секунд" << endl;


            for (int i = 0; i < 10001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, 10000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки (10000): " << (end - start) / 1000.0 << " секунд" << endl;


            for (int i = 0; i < 50001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, 50000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки(50000): " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '3':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = 1000 - i;
            }

            start = clock();
            shell(mass, 1000);
            //qs(mass, 0, n - 1);
            end = clock();  

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 10001; i++) {
                mass[i] = 10000 - i;
            }

            start = clock();
            shell(mass, 10000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 50001; i++) {
                mass[i] = 50000 - i;
            }

            start = clock();
            shell(mass, 50000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '4':
            system("cls");

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }
          
            start = clock();
            shell(mass, 1000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }

            start = clock();
            shell(mass, 10000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }

            start = clock();
            shell(mass, 50000);
            //qs(mass, 0, n - 1);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '5':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, 1000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 10001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, 10000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 50001; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, 50000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки: " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '6':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, 1000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(1000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 1001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, 10000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(10000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 1001; i++) {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, 50000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(50000): " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '7':
            system("cls");

            for (int i = 0; i < 1001; i++) {
                mass[i] = 1000 - i;
            }

            start = clock();
            qsort(mass, 1000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(1000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 10001; i++) {
                mass[i] = 10000 - i;
            }

            start = clock();
            qsort(mass, 10000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(10000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < 50001; i++) {
                mass[i] = 50000 - i;
            }

            start = clock();
            qsort(mass, 50000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(50000): " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        case '8':
            system("cls");

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }

            start = clock();
            qsort(mass, 1000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(1000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }

            start = clock();
            qsort(mass, 10000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(10000): " << (end - start) / 1000.0 << " секунд" << endl;

            for (int i = 0; i < half; i++) {
                mass[i] = i + 1;
            }

            for (int i = 0; i < half; i++) {
                mass[half + i] = half - i;
            }

            start = clock();
            qsort(mass, 50000, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки(50000): " << (end - start) / 1000.0 << " секунд" << endl;

            system("pause");

            break;
        }


    } while (ch != 27);
   

    free(mass);

	return 0;
}


