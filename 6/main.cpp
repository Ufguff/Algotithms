#include <iostream>
#include <utility>
#include <cstdlib>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
class ITreap {
    struct node {
    T v; // значение элемента
    size_t k; // неявный ключ - количество элементов в поддереве
    int y; // случайная высота
    node *left=nullptr, *right=nullptr;
    node(T v) : v(v), k(1), y(rand()) { }
    void update() { k = 1 + size(left) + size(right); }
    
    };
    node *root;
    size_t size(node *n) { return n?n->k:0; }
public:
ITreap():root(nullptr) {}
ITreap(const ITreap&)=delete; // запрет копирования
ITreap& operator=(const ITreap&)=delete; // запрет присваивания
~ITreap() { free(root); }
size_t size() const { return size(root); } // размер
private:
pair<node*, node*> spliti(node* t, size_t k) { // разрезание по количеству
  if (!t || k>=t->k) return {t,nullptr};
  if(k==0) return {nullptr,t};
  size_t l = size(t->left);
  if (l<k) {
    auto [t1,t2]=spliti(t->right,k-l-1);
    t->right=t1;
    t->update();
    return {t,t2};
  } else {
    auto [t1,t2]=spliti(t->left,k);
    t->left=t2;
    t->update();
    return {t1,t};
  }
}
node* merge(node* t1, node* t2) { // слияние
  if(!t2) return t1;
  if(!t1) return t2;
  if (t1->y > t2->y) {
    t1->right=merge(t1->right,t2);
    t1->update();
    return t1;
  } else {
    t2->left=merge(t1,t2->left);
    t2->update();
    return t2;
  }
}

node* find(size_t k) const { // поиск узла по номеру
  node *p=root;
  while(p) {
    int l=size(p->left);
    if(l==k) break;
    else if(k<l) p=p->left;
    else { k-=l+1; p=p->right; }
  }
  return p;
}
void foreach(function<void(T&)> f, node *p) // обход дерева
{
  if(!p) return;
  foreach(f,p->left);
  f(p->v);
  foreach(f,p->right);
}

public:
  T& operator[](size_t k) { // доступ к элементу по индексу
    if(k>=size()) throw runtime_error("Wrong index");
    node *p=find(k);
    return p->v;
  }
  T operator[](size_t k) const { 
    if(k>=size()) throw runtime_error("Wrong index");
    node *p=find(k);
    return p->v;
  }

  void inserti(size_t k, T v) { // вставка
      if(k>size()) throw runtime_error("Wrong index");
      node *m=new node(v);
      auto [t1,t2]=spliti(root,k);
      root=merge(merge(t1,m),t2);
  }
  void erasei(size_t k) { // удаление
      if(k>=size()) throw runtime_error("Wrong index");
      auto [t1,t]=spliti(root, k);
      auto [m,t2]=spliti(t, 1);
      root=merge(t1,t2);
      free(m);
  }
  void foreach(function<void(T&)> f) {
    foreach(f,root);
  }
};

template<typename T>
void Print(T& x)
{cout << x << endl;}

int main()
{

    vector <int> arr;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    int l_count = 0, r_count = 0, l_sum = 0, r_sum = 0;


        ITreap<int> tree;
    for (int i = 0; i < n; i++)
    {
        tree.inserti(i, arr[i]);


    }
    tree.foreach([&](int& v) {cout << v << endl;});

/*
    for (int i = 0; i < tree.size(); i++)
    {
        l_count = 0;
        r_count = 0;

        for (int j = 0; j < i; j++)
            if (tree[i] >= tree[j])
                l_count++;

        for (int j = i + 1; j < tree.size(); j++)
            if (tree[i] <= tree[j])
                r_count++;

        
        if (l_count >= r_count)
        {
            cout << i + 1 << endl;
            break;
        }
    }
*/


    return 0;
}