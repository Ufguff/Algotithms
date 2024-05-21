#include <cstring>
#include <string>
#include <functional>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

/*
Напишите функцию поиска подстроки методом Хорспула. 
Сравните время работы вашей функции с методом find и алгоритмом search с использованием boyer_moore_searcher из <functional> 
для текста размером 10^6 символов и шаблона 10^4 символов. Результаты представить в виде таблицы. 
Строки: 3 указанных алгоритма. Столбцы: 
1) для случайного текста и шаблона; 
2) текст 00...00, шаблон 00...01; 
3) текст 00...00, шаблон 10...00.
*/

unsigned const long long ASIZE = 256;

unsigned const long long TextSize = 1e6;
unsigned const long long TemplSize = 1e4;

void OUTPUT(int j) {}


void HORSPOOL( char *y , char *x ,int n , int m )
{
 int a, i, j, bm_bc[ ASIZE ];
 char ch, lastch;
 
 /* Preprocessing */
 for ( a=0; a < ASIZE; a++ ) bm_bc[ a ] = m;
 for ( j=0; j < m-1; j++ ) bm_bc[ x[ j ] ] = m - j - 1;
 
 /* Searching */
 lastch = x[ m-1 ];
 i = 0;
 while ( i <= n-m ) {
     ch = y[ i + m - 1 ];
    if ( ch == lastch )
        if ( memcmp( &y[ i ], x, m-1 ) == 0 ) OUTPUT( i );
    i += bm_bc[ ch ];
 }
}
/*
1) для случайного текста и шаблона; 
2) текст 00...00, шаблон 00...01; 
3) текст 00...00, шаблон 10...00.
*/
int main()
{
    string textF, templF;

    for (int i = 0; i < TextSize; i++)  {textF.push_back(char('a' + rand() % ('z' - 'a')));}
    for (int i = 0; i < TemplSize; i++)  {templF.push_back(char('a' + rand() % ('z' - 'a')));}

    string textS = string(TextSize, '0'), templS = string(TemplSize, '0');
    templS[TemplSize - 1] = '1';
    string textT = string(TextSize, '0'), templT = string(TemplSize, '0');
    templT[0] = '1';

    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    HORSPOOL(textF.data(), templF.data(), TextSize, TemplSize);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "first - " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    HORSPOOL(textS.data(), templS.data(), TextSize, TemplSize);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    cout << "second - " << chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << endl;
    
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    HORSPOOL(textT.data(), templT.data(), TextSize, TemplSize);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    cout << "third - " << chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << endl;
    

    /* find
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto res1 = textF.find(templF);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "first - " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    auto res2 = textS.find(templS);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    cout << "second - " << chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << endl;
    
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    auto res3 = textT.find(templT);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    cout << "third - " << chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << endl;
    */

    /*
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto res1 = search(textF.begin(), textF.end(), boyer_moore_searcher(templF.begin(), templF.end()));
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "first - " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    auto res2 = search(textS.begin(), textS.end(), boyer_moore_searcher(templS.begin(), templS.end()));
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    cout << "second - " << chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << endl;
    
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    auto res3 = search(textT.begin(), textT.end(), boyer_moore_searcher(templT.begin(), templT.end()));
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    cout << "third - " << chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << endl;
    */
}