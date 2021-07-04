#ifndef CLAUSE_H
#define CLAUSE_H_

#include <vector>
#include <initializer_list>
#include <iostream>

using std::cout;
using std::vector;

class Clause : public vector<int> {
public:
    Clause() = default;
    Clause(std::initializer_list<int> lst) {
        for (int v : lst) push_back(v);
    }

    Clause& flip(Clause& cls) {
        for (auto& v : cls) {
            at(v) = -at(v);
        }
        return *this;
    } 

    Clause& flip() {
        for (auto& v : *this) {
            v = -v;
        }
        return *this;
    }
};

#endif