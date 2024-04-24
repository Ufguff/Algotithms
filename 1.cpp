#include <iostream>
#include <vector>
using namespace std;
// Реализуйте АТД Очередь на vector, используя циклический буфер, с расширением размера в 2 раза при переполнении. 
// Операция pop() должна выполняться за O(1), push() за O(1) (амортизированная оценка).
template<typename T>
class Queue{
    private:
        vector<T> queue;
        int _size, _front, _back, _maxsize;

    public:
        Queue() : queue(2), _size(0), _maxsize(2), _back(0), _front(0) {}
        
        int size() {return _size;}

        bool empty()
        {return (_size == 0);}

        void push(T obj){
            if (_maxsize == _size){
                _maxsize *= 2;
                queue.resize(_maxsize);
                if (_front != 0)
                {
                    for (int i = _front; i < _size; i++)
                        queue[_size + i] = queue[i];
                    _front += _size;
                }
            }

            if (_back >= _maxsize)
                _back = 0;
                
            queue[_back++] = obj;
            _size++;
        }

        void pop(){
            if (_size == 0) return;
            _front++;
            if (_front >= _maxsize)
                _front = 0;
            _size--;

        }
        
        T front(){
            return queue[_front];
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
    for (int i = 1; i <= 10; i++)
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