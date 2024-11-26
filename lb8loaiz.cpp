#include <iostream>
#include <queue>

using namespace std;


queue <int> Q;

int** createG(int size)
{
    int** G;
    G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++)
    {
        G[i][i] = 0;
        for (int j = i + 1; j < size; j++)
        {
            G[i][j] = rand() % 2;
            G[j][i] = G[i][j];
        }
    }
    return G;
}

void printG(int** G, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int** G, int size, int start, int* vis) {
    vis[start] = 1;

    cout << start << endl;

    for (int i = 0; i < size; i++) {
        if (G[start][i] == 1 && vis[i] == 0)
            DFS(G, size, i, vis);
    }


}

void bFS(int** G, int size, int start, int* vis) {
    Q.push(start);
    vis[start] = 1;
    
    cout << start << " ";

    while (!Q.empty()) {
        start = Q.front();
        Q.pop();
        for (int i = 0; i < size; i++) {
            if (G[start][i] == 1 && vis[i] == 0) {
                Q.push(i);
                vis[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int** G = NULL;
    int nG, s;


    cout << "Vvedite razmer: ";
    cin >> nG;

    G = createG(nG);

    printG(G, nG);
    cout << endl;

    cout << "Vvedite start: ";
    cin >> s;
    cout << endl;

    int* vis = NULL;
    vis = (int*)malloc(nG * sizeof(int));

    /*
    Q.push(i); //кладет в очередь
    Q.pop(); //
    s = Q.front(); // в начале очереди возвращает
    Q.empty();//
    */

    for (int i = 0; i < nG; i++) {
        vis[i] = 0;
    }

    //DFS(G, nG, s, vis);

    bFS(G, nG, s, vis);

	return 0;
}