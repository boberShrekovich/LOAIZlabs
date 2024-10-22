#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root; //указатель на корень дерева (указывает на ноду которая выше)

struct Node* CreateTree(struct Node* root, struct Node* r, int data) { // куда добавляем, что добавляем, что хранится в том что добавл

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
		if (root == NULL) 
			return r; // если не было дерева то введенный элемент создается корнем

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

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

	cout << r->data << endl;
	print_tree(r->left, l + 1);
}

struct Node* find(struct Node* r, int data) {
	if (r->data == data)
		return r;

	else if (r->data < data && r->left != NULL){
		find(r->left, data);
	}

	else if (r->data > data && r->right != NULL){
		find(r->right, data);
	}

	else{
		cout << "Не найдено";
		return NULL;
	}
}

int fcount(struct Node* r, int data, int count) {
	if (r == NULL)
		return count;

	if (r->data == data)
		count++;

	count = fcount(r->right, data, count);
	count = fcount(r->left, data, count);

}



int main() {
	setlocale(LC_ALL, "");
	int D, start = 1, co;

	struct Node* r = NULL;
	cout << "-1 - окончание построения дерева" << endl;
	while (start) {
		cout << "Введите число: ";
		cin >> D;
		if (D == -1) {
			cout << "Построение дерева окончено" << endl << endl;
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);

	cout << "Введите какое число искать: ";
	cin >> D;

	r = find(root, D);
	if (r != NULL)
		cout << "Число " << r->data << " найдено" << endl;

	co = fcount(root, D, 0);
	cout << "Кол-во равно " << co << endl;

	return 0;
}
