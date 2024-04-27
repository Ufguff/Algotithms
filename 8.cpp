#include <iostream>
#include <map>
#include <list>
using namespace std;

//Используя map из STL решите следующую задачу.
//Имеется список, первоначально пустой. Команда add v добавляет v в конец списка. Команда remove v удаляет первое вхождение v
//из списка. После каждой команды вывести "1", если в списке нет одинаковых элементов, или "2", если есть одинаковые.
template<typename T>
void check(list<T>& l)
{
    map<T, int> dict;

    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        if (dict.count(*iter))
            {std::cout << '2' << std::endl; return;}
        else
            dict[*iter]++;
    }
    std::cout << '1' << std::endl;
}

template<typename T>
void add(list<T>& l, T value)
{
    l.push_back(value);
    check(l);
}

template<typename T>
void remove(list<T>& l, T value)
{
    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        if (*iter == value)
        {
            l.erase(iter);
            break;
        }
    }
    check(l);   
}

int main()
{
    list<int> lis;

    add(lis, 10);   //1
    add(lis, 20);   //1
    add(lis, 10);   //1
    add(lis, 40);   //2
    add(lis, 50);   //2

    remove(lis, 10);    //1
    add(lis, 100);  //1
    add(lis, 100);  //2
    remove(lis, 100);   //1
    remove(lis, 100);    //1
    
    for (auto iter = lis.begin(); iter != lis.end(); iter++)
    {
        cout << *iter << endl;
    }


    return 0;
}