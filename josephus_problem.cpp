#include <bits/stdc++.h>
using namespace std;
int josephus(int N, int K) {
  if (N == 1)
    return 1;
  else
    return (josephus(N - 1, K) + K - 1) % N + 1;
}
int main(){
  int nop = 5, int kill = 3; // These have to be assumed
  int winner = josephus(nop, kill);
  cout<<winner;

}