#ifndef CNF_H
#define CNF_H

#include <iostream>
#include "clause.hpp"

using std::ostream;
using std::cout;

class CNF : public vector<Clause> {
public:
    static CNF Choose(const Clause& cls, int num) {
        CNF cnf;
        Clause tmp;
        dfs(cnf, cls, tmp, 0, num);
        return cnf;
    }

    CNF& appendLiteral(int lit) {
        for (Clause& cls : *this) {
            cls.push_back(lit);
        }
        return *this;
    }

    void appendClauses(const CNF& cnf) {
        for (const Clause& cls : cnf) {
            push_back(cls);
        }
    }

    void appendClause(const Clause& cls) {
        push_back(cls);
    }

    friend ostream& operator<<(ostream& out, const CNF& cnf) {
        for (const Clause cls : cnf) {
            for (const int v : cls) {
                out << v << ' ';
            }
            out << "0\n";
        }
        return out;
    }
protected:
    static void dfs(CNF& cnf, const Clause& cls, Clause& prv, int i, int n) {
        if (prv.size() == n) {
            cnf.push_back(prv);
            return;
        }

        if (cls.size() - i - 1 >= n - prv.size()) {
            dfs(cnf, cls, prv, i + 1, n);
        }
        prv.push_back(cls[i]);
        dfs(cnf, cls, prv, i + 1, n);
        prv.pop_back();
    }
};

#endif