#include <bits/stdc++.h>
// std系を全部includeします。
using ulli = unsigned long long int;
// ulliと書くと、64bitの符号なし整数(正の数)の変数を作れるようにします。

int main(void) { // mainの中に書かれたものは基本的にどうにかなります。
  ulli N; cin >> N;
  // Nを入力し、指定します。このとき必ず2<=Nでなければなりません。
  vector<bool> table(N + 1, true);
  // 0,1,...,Nと書かれた表(正確には0-indexedでN+1の長さのbool型配列)を作ります。
  table[0] = false; table[1] = false;
  // 0,1は素数ではないとします。
  for (ulli i = 2; i <= N; i++) { // i=2として、i>Nとなるまでiを+1しながら以下の処理を繰り返します。
　　if (table[i] == true) { // iが素数であるならば
      cout << i << " "; // iを出力します。
      if (i * i <= N) { // i<=n^0.5であるならば
        for (ulli j = i; i * j <= N; j++) { // j=iとして、ij>Nとなまでjを+1しながら以下の処理を繰り返します。(iの倍数の消去)
          table[i * j] = false; // i*jを消去します。
        }
      }
    }
    // 計算量はO(N log log N)です。
  }
  cout << endl; // 念のため改行を入れます。
  // table[i]は、iが素数であるかどうか、というのもboolで格納されているので、出力以外にもいろいろな使い方があります。
}
