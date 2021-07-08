#include <vector>
#include <utility>
#include "cnf.hpp"
#include "state.hpp"

class Converter {
public: 
    Converter(unsigned int h, unsigned int l, unsigned int p) {
        height = h + 2, length = l + 2, period = p;
    }

    CNF& convert() {
        cnf.clear();

        ruleNeighbor();
        ruleWall();
        ruleNotAllZero();
        ruleMarginal();

        return cnf;
    }

    CNF& preventOld(const State& st) {
        if (st.getHeight() > height - 2 || st.getLength() > length - 2)   return cnf;
        for (int i = 0; i < height - st.getHeight() - 1; ++i) {
            for (int j = 0; j < length - st.getLength() - 1; ++j) {
                paste(st, -i, -j);
            }
        }
        return cnf;
    }

    State decode(const Clause& cls) {
        State st;
        for (const auto& v : cls) {
            if (v > 0 && (v - 1) % period == 0) {
                int d = (v - 1) / period;
                st.add({d / static_cast<int>(length), d % static_cast<int>(length)});
            }
        }
        return st;
    }

    const CNF& getCnf() const {
        return cnf;
    }

protected:
    inline int getIndex(int x, int y, int p) const {
        return (x * length + y) * period + p + 1;
    }

    void ruleNeighbor() {
        const int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
        const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < length - 1; ++j) {
                for (int k = 0; k < period; ++k) {
                    Clause cls;
                    for (int l = 0; l < 8; ++l) {
                        cls.push_back(getIndex(i + dx[l], j + dy[l], k));
                    }
                    ruleSingleNeighbor(cls, getIndex(i, j, (k + 1) % period));
                }
            }
        }
    }

    void ruleSingleNeighbor(Clause nei, int nxt) {
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

    void ruleWall() {
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
    }

    void ruleNotAllZero() {
        Clause all;
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < length - 1; ++j) {
                for (int k = 0; k < period; ++k) {
                    all.push_back(getIndex(i, j, k));
                }
            }
        }
        cnf.push_back(all);
    }

    void ruleMarginal() {
        Clause c1, c2, c3, c4;
        for (int i = 1; i < height - 1; ++i) {
            c1.push_back(getIndex(i, 1, 0));
            c2.push_back(getIndex(i, length - 2, 0));
        }
        for (int i = 1; i < length - 2; ++i) {
            c3.push_back(getIndex(1, i, 0));
            c4.push_back(getIndex(height - 2, i, 0));
        }
        cnf.push_back(c1);
        cnf.push_back(c2);
        cnf.push_back(c3);
        cnf.push_back(c4);
    }

    void paste(const State& st, int ofsx, int ofsy) {
        Clause cls;
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < length - 1; ++j) {
                if (st.count({i + ofsx, j + ofsy})) cls.push_back(-getIndex(i, j, 0));
                else cls.push_back(getIndex(i, j, 0));
            }
        }
        cnf.push_back(cls);
    }

    unsigned int height, length, period;
    CNF cnf;
};