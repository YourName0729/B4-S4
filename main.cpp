#include <iostream>
#include <fstream>
#include "converter.hpp"
#include "dimacs_adapter.hpp"

using std::cout;

bool arr[14][14] = {0};

int main() {
    Converter cvt(7, 7, 2);

    std::ofstream fout("cnf.cnf");
    DIMACSAdapter::cnf2dimacs(cvt.convert(), fout);
    fout.close();

    system("./MiniSat_v1.14_linux cnf.cnf ans.sat");

    std::ifstream fin("ans.sat");
    auto vec = cvt.decode(DIMACSAdapter::dimacs2cls(fin));
    for (auto p : vec) {
        cout << p.first << ' ' << p.second << '\n'; 
    }

    //fout << cvt.convert() << '\n';

    // std::ifstream fin("a.txt");
    // vector<int> vec;
    // int d;
    // while (fin >> d) {
    //     vec.push_back(d);
    // }

    
    // int cnt = 0;
    // for (auto& v : vec) {
    //     if (v > 0) {
    //         --v;
    //         if (v % 2 == 0) {
    //             v /= 2;
    //             arr[v / 9][v % 9] = 1;
    //             ++cnt;
    //             //cout << "(" << v / 10 << ", " << v % 10 << '\n';
    //         }
    //     }
    // }
    // cout << cnt << '\n';
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         if (arr[i][j]) cout << 'O';
    //         else cout << ".";
    //     }
    //     cout << '\n';
    // }

    return 0;
}