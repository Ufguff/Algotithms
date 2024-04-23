#include <iostream>
#include <vector>
using namespace std;
// Реализуйте АТД Очередь на vector, используя циклический буфер, с расширением размера в 2 раза при переполнении. 
// Операция pop() должна выполняться за O(1), push() за O(1) (амортизированная оценка).
template<typename T>
class Queue{
    private:
        vector<T> queue;
        int _size, _curr, _front, _back;

    public:
        Queue(){ 
            _curr = 0;
            _size = 1;
            queue.resize(_size);
        }

        int size() {return _size;}

        bool empty()
        {return (_size == 0);}

        void push(T obj){
            if (_curr + 1 == _size){
                _size *= 2;
                queue.resize(_size);
            }
                
            queue[_curr] = obj;
        }

        void pop(){
            _curr++;
        }
        
        T front(){
            return queue[_curr];
        }
/*
        void print()
        {
            for (auto it : queue) {cout << (it) << " "; it++;}
            cout << endl;
        }
*/
};

int main()
{
    Queue<int> q;
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 1; j <= i; j++)
            q.push(j);
        while (q.size())
        {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }
}