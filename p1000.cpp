// 1000 - A+B problem
// http://poj.org/problem?id=1000
// O(1) algorithm

#include <cassert>
#include <iostream>

using namespace std;

int a, b;

int main() {
   cin.sync_with_stdio(false);
   cin>>a>>b;
   assert(a>=0 && a<=10 && b>=0 && b<=10);
   cout<<a+b<<"\n";
   return 0;
}
