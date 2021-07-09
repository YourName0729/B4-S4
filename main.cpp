#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include "converter.hpp"
#include "dimacs_adapter.hpp"

using namespace std;

void print(const State& st) {
    vector<vector<bool>> vec2(st.getHeight(), vector<bool>(st.getLength(), 0));
    for (auto p : st) {
        vec2[p.x - 1][p.y - 1] = 1;
    }
    for (int i = 0; i < st.getHeight(); ++i) {
        for (int j = 0; j < st.getLength(); ++j) {
            if (vec2[i][j]) cout << 'O';
            else cout << '.';
        }
        cout << '\n';
    }
}

void print(const string& s) {
    State st;
    ifstream fin(s);
    fin >> st;
    print(st);
}

// bool prefix(const string& s, const string& t) {
//     for (int i = 0; i < t.length(); ++i) {
//         if (s[i] != t[i]) return 0;
//     }
//     return 1;
// }

int main() {

    print("./oscillator/o12x12x2_tilt_1.txt");
    for (const auto& entry : filesystem::directory_iterator("./oscillator")) {
        if (entry.path() == "./oscillator/tmp.txt") continue;
        print(entry.path().string());
    }
        
    // Converter cvt(20, 20, 2);

    // cvt.convert();
    // for (const auto& entry : filesystem::directory_iterator("./oscillator")) {
    //     if (entry.path() == "./oscillator/tmp.txt") continue;
    //     ifstream fin(entry.path());
    //     State st;
    //     fin >> st;
    //     cvt.preventOld(st);
    // }

    // std::ofstream fout("cnf.cnf");
    // DIMACSAdapter::cnf2dimacs(cvt.getCnf(), fout);
    // fout.close();

    // system("./MiniSat_v1.14_linux cnf.cnf ans.sat");

    // std::ifstream fin("ans.sat");
    // auto st = cvt.decode(DIMACSAdapter::dimacs2cls(fin));
    // fin.close();

    // if (!st.size()) return 0;

    // std::ofstream fout2("oscillator/tmp.txt");
    // fout2 << st;
    // fout2.close();

    // print(st);

    // string name;
    // stringstream ss;
    // cin >> name;
    // if (name == ".") return 0;
    // ss << "oscillator/o" << st.getHeight() << 'x' << st.getLength() << 'x' << 2 << '_' << name << ".txt";
    // ss >> name;

    // rename("oscillator/tmp.txt", name.c_str());

    return 0;
}