#include <iostream>
using namespace std;
/*
Напишите функцию для симметричного (in-order) обхода бинарного дерева, заданного следующей структурой:
struct node { int value; node *left, *right; };
К каждому значению, хранящемуся в дереве, функция применяет функцию, указанную в качестве аргумента:
void inorder(node *n, void (*f)(int));
*/
void multBy2(int* n) {(*n) *= 2;}

struct node { int value; node *left, *right; };

void inorder(node *n, void (*op)(int*))
{
    if (n != nullptr)
    {
        op(&n->value);
        inorder(n->left, op);
        cout << n->value << endl;
        inorder(n->right, op);
    }
}

int main()
{
    node* root = new node();
    node* n1 = new node();
    node* n2 = new node();
    node* n3 = new node();

    root->value = 10;
    n1->value = 2;
    n2->value = 5;
    n3->value = 8;

    root->left = n1;
    root->right = n2;
    n1->right = n3;

    inorder(root, multBy2);
    return 0;
}