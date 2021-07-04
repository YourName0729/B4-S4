#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "cnf.hpp"

using std::string;
using std::istream;
using std::ostream;

class DIMACSAdapter {
public:
    static void cnf2dimacs(const CNF& cnf, ostream& out) {
        int N = 0;
        for (const Clause& cls : cnf) {
            for (const auto& v : cls) {
                N = std::max(N, std::abs(v));
            }
        }

        out << "p cnf " << N << ' ' << cnf.size() << '\n';
        for (const Clause& cls : cnf) {
            for (const auto& v : cls) {
                out << v << ' ';
            }
            out << "0\n";
        }
    }

    static Clause dimacs2cls(istream& in) {
        string s;
        in >> s;
        if (s == "UNSAT") {
            return Clause();
        }
        
        int d;
        Clause cls;
        while (in >> d && d) {
            cls.push_back(d);
        }
        return cls;
    }

};