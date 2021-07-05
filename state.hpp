#ifndef STATE_H
#define STATE_H

#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>

using std::vector;
using std::pair;
using std::set;
using std::max;

struct Pos {
    int x, y;
    bool operator<(const Pos& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

class State : public set<Pos>{
public:
    State() = default;
    State(const set<Pos>& st) {
        *this = st;
        N = M = 1;
        for (auto p : st) {
            N = max(N, p.x), M = max(M, p.y);
        }
    }

    void add(const Pos& p) {
        insert(p);
        N = max(N, p.x), M = max(M, p.y);
    }

    inline int getHeight() const { return N; }
    inline int getLength() const { return M; }

    friend std::ostream& operator<<(std::ostream& out, const State& st) {
        out << st.size() << ' ' << st.N << ' ' << st.M << '\n';
        for (const Pos& p : st) {
            out << p.x << ' ' << p.y << '\n';
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, State& st) {
        int n;
        in >> n >> st.N >> st.M;
        for (int i = 0; i < n; ++i) {
            Pos p;
            in >> p.x >> p.y;
            st.insert(p);
        }
        return in;
    }
protected:
    int N = 1, M = 1;
};

#endif