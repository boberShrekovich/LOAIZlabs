#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <cstring>

using namespace std;


struct Node {
	char str;
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root; //указатель на корень дерева (указывает на ноду которая выше)

struct Node* CreateTree(struct Node* root, struct Node* r, int data, char strt) { // куда добавляем, что добавляем, что хранится в том что добавл

	if (r == NULL) // только корень
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		r->str = strt;
		if (root == NULL)
			return r; // если не было дерева то введенный элемент создается корнем

		if (data > root->data)	
			root->left = r;
		else if (data < root->data) 
			root->right = r;
		else 
			return r;

		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data, strt);
	else if (data < r->data)
		CreateTree(r, r->right, data, strt);
	else
		return root;

	return root;
}

void print_tree(struct Node* r, int l) {

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1); // в l кол-во уровней
	for (int i = 0; i < l; i++)
	{
		cout << " ";
	}

	cout << r->str << endl;
	print_tree(r->left, l + 1);
}

struct Node* find(struct Node* r, char strt) {
	if (tolower(r->str) == tolower(strt))
		return r;

	else if (tolower(r->str) < tolower(strt)) {
		find(r->left, strt);
	}

	else if (tolower(r->str) > tolower(strt)) {
		find(r->right, strt);
	}

	else {
		cout << "Не найдено";
		return NULL;
	}
}

int fcount(struct Node* r, char strt, int count) {
	if (r == NULL)
		return count;

	if (tolower(r->str) == tolower(strt))
		count++;

	count = fcount(r->right, strt, count);
	count = fcount(r->left, strt, count);

}



int main() {
	setlocale(LC_ALL, "");
	int D, start = 1, co;
	char St;

	struct Node* r = NULL;
	cout << "-1 - окончание построения дерева. Одинаковые не вводить!!!" << endl;
	while (start) {
		cout << "Введите число: ";
		cin >> D;

		if (D != -1) {
			cout << "Введите символ: ";
			cin >> St;

		}

		if (D == -1) {
			cout << "Построение дерева окончено" << endl << endl;
			start = 0;
		}
		else
			root = CreateTree(root, root, D, St);

	}

	print_tree(root, 0);

	cout << "Введите какой символ искать: ";
	cin >> St;

	r = find(root, St);
	if (r != NULL)
		cout << "Символ '" << r->str << "' найден" << endl;

	co = fcount(root, St, 0);
	cout << "Найдено " << co << " раз" << endl;

	return 0;
}

