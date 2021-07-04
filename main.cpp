#include <iostream>
#include <fstream>
#include "converter.hpp"

using std::cout;

bool arr[14][14] = {0};

int main() {
    // Converter cvt(7, 7, 2);

    // std::ofstream fout("cnf.cnf");
    // fout << cvt.convert() << '\n';

    std::ifstream fin("a.txt");
    vector<int> vec;
    int d;
    while (fin >> d) {
        vec.push_back(d);
    }

    
    int cnt = 0;
    for (auto& v : vec) {
        if (v > 0) {
            --v;
            if (v % 2 == 0) {
                v /= 2;
                arr[v / 9][v % 9] = 1;
                ++cnt;
                //cout << "(" << v / 10 << ", " << v % 10 << '\n';
            }
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j]) cout << 'O';
            else cout << ".";
        }
        cout << '\n';
    }

    return 0;
}