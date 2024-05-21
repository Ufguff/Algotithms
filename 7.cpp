#include <iostream>
#include <functional>
#include <cassert>
#include <algorithm>
#include <optional>
using namespace std;

template <typename T, typename State, typename Operation>
class STreap {
using func=function<State(State,State)>;
func f;
struct node {
  T v; // значение элемента
  size_t k; // неявный ключ - количество элементов в поддереве
  int y; // случайная высота
  State s; // результаты для поддерева
  optional<Operation> op={}; // операция над поддеревом
  node *left=nullptr, *right=nullptr;
  node(T v) : v(v), k(1), y(rand()),s(v) { }
  void update(func f) {
    assert(!op);
    k=1+size(left)+size(right);
    s=f(f(state(left),State(v)),state(right));
  }
  void add_op(Operation o) {
    if(!op) op=o;
    else op=op->combine(o);
  }
  void clear_op() {
    if(!op) return;
    v=(*op)(v);
    if(left) left->add_op(*op);
    if(right) right->add_op(*op);
    s=(*op)(s,k);
    op={};
  }
};
node *root;
static size_t size(node *n) { return n?n->k:0; }
static State state(node *n) { 
  if(!n) return State();
  if(n->op) return (*(n->op))(n->s,n->k);
  return n->s;
}
pair<node*, node*> spliti(node* t, size_t k) { // разрезание по количеству
  if (!t || k>=t->k) return {t,nullptr};
  if(k==0) return {nullptr,t};
  t->clear_op();
  size_t l=size(t->left);
  if (l<k) {
    auto [t1,t2]=spliti(t->right,k-l-1);
    t->right=t1;
    t->update(f);
    return {t,t2};
  } else {
    auto [t1,t2]=spliti(t->left,k);
    t->left=t2;
    t->update(f);
    return {t1,t};
  }
}
node* merge(node* t1, node* t2) { // слияние
  if(!t2) return t1;
  if(!t1) return t2;
  if (t1->y > t2->y) {
    t1->clear_op();
    t1->right=merge(t1->right,t2);
    t1->update(f);
    return t1;
  } else {
    t2->clear_op();
    t2->left=merge(t1,t2->left);
    t2->update(f);
    return t2;
  }
}
public:
STreap(func f):f(f),root(nullptr) {}
STreap(const STreap&)=delete; // запрет копирования
STreap& operator=(const STreap&)=delete; // запрет присваивания
~STreap() { free(root); }
size_t size() const { return size(root); } // размер
void insert(size_t k, T v) { // вставка
   if(k>size()) throw runtime_error("Wrong index");
   node *m=new node(v);
   auto [t1,t2]=spliti(root,k);
   root=merge(merge(t1,m),t2);
}
void erase(size_t k) { // удаление
   if(k>=size()) throw runtime_error("Wrong index");
   auto [t1,t]=spliti(root, k);
   auto [m,t2]=spliti(t, 1);
   root=merge(t1,t2);
   free(m);
}
State calc(size_t i, size_t j) {
  if(i>=size() || j>=size() || i>j) throw runtime_error("Wrong index");
  auto [t1,t]=spliti(root, i);
  auto [m,t2]=spliti(t, j-i+1);
  State s=state(m);
  root=merge(t1,merge(m,t2));
  return s;
}
void apply(size_t i, size_t j, Operation op) {
  if(i>=size() || j>=size() || i>j) throw runtime_error("Wrong index");
  auto [t1,t]=spliti(root, i);
  auto [m,t2]=spliti(t, j-i+1);
  if(m) m->add_op(op);
  root=merge(t1,merge(m,t2));
}
};
struct Op {
  int op; // 0 - присваивание, 1 - увеличение на a | 0 - умножение 
  int a; // параметр
  int operator()(int s, size_t k) const { return op?s+a:a; }
  int operator()(int v) const { return op?v+a:a; }
  optional<Op> combine(Op o) const { if(o.op==0) return Op(op,a*o.a); return Op(op,a+o.a); }
};

//int Print(int a, int b) {const long long M=1000000007; return a%M;}

int Print(int a, int b) {return max(a, b);}

int main()
{ 

   function<int(int, int)> maxF = Print;
  STreap<int,int,Op> t(maxF);
/*  
t.insert(0,10);
  t.insert(1,20);
  t.insert(1,15);
  cout<<t.calc(0,2)<<"\n";
  t.apply(0,1,Op(1,7));
  cout<<t.calc(0,2)<<"\n";
  t.erase(1);
  cout<<t.calc(0,0)<<"\n";
  cout<<t.calc(0,1)<<"\n";
*/
   int n;       cin >> n;
   for (int i = 0; i < n; i++)
   {
      int k;    cin >> k;
      t.insert(i, k);
   }
   
    int req_n, l, r, d, p;  cin >> req_n;
    char c;
    for (int i = 0; i < req_n; i++)
    {
        cin >> c;
        switch (c)
        {
        case '+':
            cin >> l >> r >> d;       
            t.apply(l - 1, r - 1, Op(1, d));
            break;
        case '*':
            cin >> l >> r >> d;
            t.apply(l - 1, r - 1, Op(0, d));
            break;
        case '?':
            cin >> p;
            cout << t.calc(p - 1, p - 1) << endl;
            break;
        
        }
    }
   
}