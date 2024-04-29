#include <iostream>
#include <queue>

using namespace std;
int main()
{
   queue<int> q;
   int n; cin >> n;
   vector<int> v(n + 1, 0);
   q.push(1);
   auto step = [&](int x, int k){
      if (x <= n && v[x] == 0)
      {
         v[x] = v[k] + 1;
         q.push(x);
      }
   };
   while(!q.empty())
   {
      int k = q.front();
      q.pop();
      
      for (int d = 1; d*d <= k; d++)
      {
         if (k % d == 0)
         {
            if (k + d <= n)
            {
               step(k+d, k);
               step(k+k/d, k);
            }
         }
      }
      
   }
   cout << v[n];
   return 0;
}