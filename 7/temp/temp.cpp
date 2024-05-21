




using namespace std;

const unsigned long long MOD = 1e9 + 7;

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
  int op; // 1 - увеличение на a | 0 - умножение 
  int a; // параметр
  int operator()(int s, size_t k) const { return op? (static_cast<long long>(a)+ static_cast<long long>(s)) % MOD : (static_cast<long long>(a)*static_cast<long long>(s)) % MOD; }
  int operator()(int v) const { return op? (static_cast<long long>(a)+static_cast<long long>(v)) % MOD : (static_cast<long long>(a)*static_cast<long long>(v)) % MOD; }
  optional<Op> combine(Op o) const { if(o.op==0) return Op(op, (static_cast<long long>(a)*static_cast<long long>(o.a)) % MOD); return Op(op, (static_cast<long long>(a)+static_cast<long long>(_abracadabra_cast(o);