// 2408 - Anagram Groups
// http://poj.org/problem?id=2408
// O((m+n)lg n)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef pair<set<string>, int> ListeMots;

const int MAXN = 5;

struct Comp {
   bool operator () (const ListeMots& a, const ListeMots& b) const {
      if (a.second!=b.second)
         return a.second>b.second;
      return *a.first.begin()<*b.first.begin();
   }
};

map<string,ListeMots> dictA;
set<ListeMots,Comp> dictB;
string s;
int nbgrps;

int main() {
   cin.sync_with_stdio(false);

   // lit les mots
   while (cin>>s) {
      string sig = s;
      sort(sig.begin(), sig.end());
      dictA[sig].second++;
      dictA[sig].first.insert(s);
   }

   // insère les mots dans un autre dictionnaire
   for (map<string,ListeMots>::iterator it=dictA.begin(); it!=dictA.end(); ++it)
      dictB.insert(it->second);

   // affiche les anagrammes
   for (set<ListeMots,Comp>::iterator dit=dictB.begin(); dit!=dictB.end() && nbgrps<MAXN; ++dit) {
      cout<<"Group of size "<<dit->second<<": ";
      for (set<string>::iterator lit=dit->first.begin(); lit!=dit->first.end(); ++lit)
         cout<<*lit<<" ";
      cout<<".\n";
      nbgrps++;
   }
 
   return 0;
}
