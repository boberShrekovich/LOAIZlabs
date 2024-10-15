#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

int main() {
	int m = 5;
	int** G, *deg;

	cout << "1 zadanie" << endl;

	deg = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		deg[i] = 0;
	}


	G = (int**)malloc(m*sizeof(int*));
	for (int i = 0; i < m; i++) {
		G[i] = (int*)malloc(m * sizeof(int));
	}

	srand(time(NULL));

	for (int i = 0; i < m; i++) {
		G[i][i] = 0;
		for (int j = i + 1; j < m; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}


	cout << endl << "2 zadanie" << endl;

	int size = 0;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[j][i] == 1)
				size++;
		}
	}

	cout << "razmer = " << size / 2 << endl;


	cout << endl << "3 zadanie" << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[j][i] == 1)
				deg[i]++;
		}
		cout << "stepen vershiny " << i << " = " << deg[i] << endl;
	}

	cout << endl;
	for (int i = 0; i < m; i++) {
		if (deg[i] == 0)
			cout << "Vershina " << i << " izolirovannaya" << endl;
		if (deg[i] == 1)
			cout << "Vershina " << i << " koncevaya" << endl;
		if (deg[i] == m)
			cout << "Vershina " << i << " dominiruyuschaya" << endl;

	}

	return 0;
}