#include "cnf.hpp"

class Converter {
public: 
    Converter(unsigned int h, unsigned int l, unsigned int p) {
        height = h + 2, length = l + 2, period = p;
    }

    CNF convert() const {
        const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
        const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        CNF cnf;
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < length - 1; ++j) {
                for (int k = 0; k < period; ++k) {
                    Clause cls;
                    for (int l = 0; l < 8; ++l) {
                        cls.push_back(getIndex(i + dx[l], j + dy[l], k));
                    }
                    neighbor(cnf, cls, getIndex(i, j, (k + 1) % period));
                }
            }
        }

        for (int i = 0; i < period; ++i) {
            for (int j = 0; j < height; ++j) {
                cnf.push_back({-getIndex(j, 0, i)});
                cnf.push_back({-getIndex(j, length - 1, i)});
            }    
            for (int j = 1; j < length - 1; ++j) {
                cnf.push_back({-getIndex(0, j, i)});
                cnf.push_back({-getIndex(height - 1, j, i)});
            }
        }

        Clause all;
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < length - 1; ++j) {
                for (int k = 0; k < period; ++k) {
                    all.push_back(getIndex(i, j, k));
                }
            }
        }
        cnf.push_back(all);

        return cnf;
    }

    

protected:
    inline int getIndex(int x, int y, int p) const {
        return (x * length + y) * period + p + 1;
    }

    void neighbor(CNF& cnf, Clause nei, int nxt) const {
        CNF cp, pick = CNF::Choose({0, 1, 2, 3, 4, 5, 6, 7}, 4);
        for (Clause& cls : pick) {
            nei.flip(cls);
            cp.push_back(nei);
            nei.flip(cls);
        }
        cp.appendLiteral(nxt);
        cnf.appendClauses(cp);

        cnf.appendClauses(CNF::Choose(nei, 5).appendLiteral(-nxt));
        nei.flip();
        cnf.appendClauses(CNF::Choose(nei, 5).appendLiteral(-nxt));
    }

    unsigned int height, length, period;
};