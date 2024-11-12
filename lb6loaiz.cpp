#include <iostream>
#include <cstdlib>

using namespace std;

int** createGraph(int size) { // новый граф

	int** G;
	G = (int**)malloc(size * sizeof(int*));
	
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		G[i][i] = 0;
		for (int j = i + 1; j < size; j++) {

			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}

	return G;
}

void freeGraph(int** G, int size) {
	for (int i = 0; i < size; i++)
		free(G[i]);

	free(G);
}

void printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << " " << G[i][j];
		}
		cout << endl;
	}
	return;
}

int** delV(int** G, int size, int V) {
	int** Gnew = createGraph(size - 1);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j < V && i < V)
				Gnew[i][j] = G[i][j];
			if (j > V && i > V)
				Gnew[i - 1][j - 1] = G[i][j];
			if (j > V && i < V)
				Gnew[i][j - 1] = G[i][j];
			if (j < V && i > V)
				Gnew[i - 1][j] = G[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		free(G[i]);
	}
	free(G);
	G = NULL;

	return Gnew;
}

int** unionV(int** G, int size, int v1, int v2) {
	for (int i = 0; i < size; i++) {
		if (G[v2][i] == 1) {
			G[v1][i] = G[v2][i];
			G[i][v1] = G[i][v2];
		}
	}

	G = delV(G, size, v2);

	return G;
}

int** contrE(int** G, int size, int v1, int v2)//стягивание ребра 
{
	G[v1][v2] = 0;
	G[v2][v1] = 0;
	
	for (int i = 0; i < size; i++) {
		if (G[v1][i] = 1) {
			G[v1][i] = G[v2][i];
			G[i][v1] = G[i][v2];
		}
	}

	G = delV(G, size, v2);

	return G;
}

//
int** splitV(int **G, int size, int V) {
	int** Gtemp = createGraph(size + 1);

	for (int i = 0; i < size; i++) {
		Gtemp[i][size] = G[i][V];
		Gtemp[size][i] = G[V][i];
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Gtemp[i][j] = G[i][j];
		}
	}

	Gtemp[V][V] = 0;
	Gtemp[size][size] = 0;
	
	for (int i = 0; i < size; i++) {
		free(G[i]);
	}
	free(G);
	G = NULL;

	
	return Gtemp;
}

//
int** unionG(int **G1, int **G2, int size1, int size2) {
	int sizemax = (size1 > size2) ? size1 : size2;
	int sizemin = (size1 < size2) ? size1 : size2;

	int** Gmax = (size1 > size2) ? G1 : G2;
	int** Gmin = (size1 < size2) ? G1 : G2;


	int** Gtemp = createGraph(sizemax);

	for (int i = 0; i < sizemax; i++) {
		for (int j = 0; j < sizemax; j++) {
			Gtemp[i][j] = Gmax[i][j];

			//Gtemp[i][j] = Gmax[i][j] | Gmin[i][j];
		}
	}
	for (int i = 0; i < sizemin; i++) {
		for (int j = 0; j < sizemin; j++) {
			if (Gmin[i][j] == 1) 
				Gtemp[i][j] = Gmin[i][j];
		}
	}
	/*for (int i = sizemin + 1; i < sizemax; i++) {
		for (int j = sizemin + 1; j <= sizemax; j++) {

			Gtemp[i][j] = Gmax[i][j];
		}
	}*/

	return Gtemp;
}

// 
int **interSectionG(int **G1, int **G2, int size1, int size2) {
	int sizemin = (size1 < size2) ? size1 : size2;
	int** Gtemp = createGraph(sizemin);

	for (int i = 0; i < sizemin; i++) {
		for (int j = 0; j < sizemin; j++) {
			Gtemp[i][j] = G1[i][j] & G2[i][j];
		}
	}

	return Gtemp;
}

// 
int **xorG(int** G1, int** G2, int size1, int size2, int* nG5) {
	
	
	int sizemax = (size1 > size2) ? size1 : size2;
	int sizemin = (size1 < size2) ? size1 : size2;

	int** Gmax = (size1 > size2) ? G1 : G2;
	int** Gmin = (size1 < size2) ? G1 : G2;

	int** Gtemp = createGraph(sizemax);
	//int** Gtemp2 = createGraph(sizemax);

	for (int i = 0; i < sizemin; i++) {
		for (int j = 0; j < sizemin; j++) {
			Gtemp[i][j] = G1[i][j] ^ G2[i][j];
		}
	}

	for (int i = 0; i < sizemin; i++) {
		for (int j = sizemin; j < sizemax; j++) {
			Gtemp[i][j] = Gmax[i][j];
		}
	}

	for (int i = sizemin; i < sizemax; i++) {
		for (int j = 0; j < sizemax; j++) {
			Gtemp[i][j] = Gmax[i][j];
		}
	}

	for (int i = 0; i < sizemax; i++) {
		int step = 0;
		for (int j = 0; j < sizemax; j++) {
			
			if (Gtemp[i][j] == 1)
				step++;
		}
		if (step == 0) {
			Gtemp = delV(Gtemp, sizemax, i);
			sizemax--; 
			i--;
		}
	}

	//int** Gtemp2 = delV(Gtemp, i);
	*nG5 = sizemax;

	return Gtemp;
}

int main(void) {
	srand(time(NULL));
	int nG1, nG2, v1, v2, V, choose, graph;

	cout << "vved kolvo versh G1" << endl;
	cin >> nG1;
	cout << "vved kolvo versh G2" << endl;
	cin >> nG2;

	int** G1 = createGraph(nG1);
	int** G2 = createGraph(nG2);

	cout << "gr G1" << endl;
	printG(G1, nG1);

	cout << "gr G2" << endl;
	printG(G2, nG2);


	cout << "Vyberite " << endl << "1. Otozhdestvlenie" << endl << "2. Styagivanie" << endl << "3. Obedinenie" << endl << "4. Peresechenie" << endl << "5. Kolcevaya sum" << endl << "6. Rasscheplenie" << endl;
	cin >> choose;

	switch (choose) {
	case 1:
	
		cout << "Vyberite graph: " << endl;
		cin >> graph;
		cout << "Vyberite vershiny dlya otozhdestvleniya: " << endl << "Vershina 1:" << endl;
		cin >> v1;
		cout << "Vershina 2:" << endl;
		cin >> v2;

		if (graph == 1) {
			int** G6 = unionV(G1, nG1, v1, v2);
			cout << "otozhdestvlenny graph:" << endl;
			printG(G6, nG1 - 1);
		}
		else {
			int** G6 = unionV(G2, nG2, v1, v2);
			cout << "otozhdestvlenny graph:" << endl;
			printG(G6, nG2 - 1);
		}
		break;
	

	case 2:
	
		cout << "Vyberite graph: " << endl;
		cin >> graph;
		cout << "Vyberite vershiny dlya otozhdestvleniya: " << endl << "Vershina 1:" << endl;
		cin >> v1;
		cout << "Vershina 2:" << endl;
		cin >> v2;


		if (graph == 1) {
			int** G6 = contrE(G1, nG1, v1, v2);
			cout << "otozhdestvlenny graph:" << endl;
			printG(G6, nG1 - 1);
		}
		else {
			int** G6 = contrE(G2, nG2, v1, v2);
			cout << "otozhdestvlenny graph:" << endl;
			printG(G6, nG2 - 1);
		}

		break;
	

	case 3:
	{
		int** G3 = unionG(G1, G2, nG1, nG2);
		int nG3 = (nG1 > nG2)?nG1:nG2;
		cout << "obed graph" << endl;
		printG(G3, nG3);

		break;
	}

	case 4:
	{
		int** G4 = interSectionG(G1, G2, nG1, nG2);
		int nG4 = (nG1 < nG2) ? nG1 : nG2;
		cout << "peresech graf" << endl;
		printG(G4, nG4);
		
		break;
	}

	case 5:
	{
		int nG5;
		int** G5 = xorG(G1, G2, nG1, nG2, &nG5);
		cout << "xor" << endl;
		printG(G5, nG5);

		break;
	}
	case 6:
		cout << endl << "kakoe rasship vershiny: ";
		cin >> V;
		G1 = splitV(G1, nG1, V);
		printG(G1, nG1 + 1);
	
		break;
	}

	return 0;
}

	//int** G3 = unionG(G1, G2, nG1, nG2);
	//int nG3 = (nG1 > nG2)?nG1:nG2;

	//cout << "obed graf" << endl;

	//printG(G3, nG3);



	//cout << endl << "Vvod otozgdestvlyaemoy vetshini: ";
	//cin >> V;
	//v2 = V;
	//v1 = v2 - 1;
	//G1 = unionV(G1, nG1, v1, v2);
	//nG1--;
	//cout << endl << "Otoshdestvlenye vetshini: \n";
	//printG(G1, nG1);

	//if (G1[v1][v2] != 1){
	//	cout << "Rebra net";
	//}
	//else {
	//	G1 = contrE(G1, nG1, v1, v2);
	//	nG1--;
	//}
	//cout << "Styagivanie rebra" << endl;
	//printG(G1, nG1);

	//int v3;
	//cout << "Vvedite vershinu" << endl;
	//cin >> v3;
	//G2 = splitV(G2, nG2, v3);
	//nG2++;
	//cout << "Rascheplenie vershiny" << endl;
	//printG(G2, nG2);


	//int** G4 = interSectionG(G1, G2, nG1, nG2);
	//int nG4 = (nG1 < nG2) ? nG1 : nG2;

	//cout << "peresech graf" << endl;

	//printG(G4, nG4);


	////int nG5 = (nG1 < nG2) ? nG1 : nG2;
	//int nG5;
	//int** G5 = xorG(G1, G2, nG1, nG2, &nG5);

	//cout << "xor" << endl;

	//printG(G5, nG5);



	//return 0;






	//int nG1, nG2, V, v1, v2;
	////nG1 = 5;

	//cout << "vvedite nG1: ";
	//cin >> nG1;
	//cout << endl;

	//int** G1 = createGraph(nG1);
	//printG(G1, nG1);

	//cout << endl;


	//cout << "vvedite nG2: ";
	//cin >> nG2;
	//cout << endl;

	//int** G2 = createGraph(nG2);
	//printG(G2, nG2);

	//cout << endl;


	//int** G3 = unionG(G1, G2, nG1, nG2);
	//int nG3 = (nG1 > nG2) ? nG1 : nG2;
	//cout << endl << "ob'edinenie" << endl;
	//printG(G3, nG3);
	////cout << "Vvedite V: ";
	////cin >> V;
	////cout << endl;

	//////cout << "vvedite v1 i v2";
	//v2 = 3;
	//v1 = v2 - 1;
	//cout << endl;

	//G2 = unionV(G2, nG2, v1, v2);
	//nG2--;
	//cout << "otozhd";



	//cout << endl << "otozhdestvlenie vershiny" << endl;
	//printG(G1, nG1);
	//if (G1[v1][v2] != 1) {
	//	cout << "rebra net";
	//}
	//cout << endl;

	//G2 = contrE(G2, nG2, v1, v2);
	//nG2--;
	//cout << "styag rebra";
	//printG(G2, nG2);


	//G1 = splitV(G1, nG1, 2);
	//nG1++;
	//cout << "Rasscheplenie vershiny";
	//printG(G1, nG1);
	////G1 = contrE(G1, nG1, v1, v2);
	////int** G1new = delV(G1, nG1, V);
	////printG(G1new, nG1 - 1);

	////freeGraph(G1, nG1);
	////freeGraph(G2, nG2);
	////freeGraph(G1new, nG1 - 1);

	////int** G3 = unionG(G1, G2, nG1, nG2);
	////int nG3 = (nG1 > nG2) ? nG1 : nG2;
	////cout << endl << "ob'edinenie" << endl;

	//printG(G2, nG2);

	//return 0;
//}