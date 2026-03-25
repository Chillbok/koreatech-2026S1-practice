#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cin, std::cout, std::endl;
using std::string;
using std::vector;
using std::stringstream;

struct Literal {
    int var_idx;
    bool is_neg;
};

struct Clause {
    Literal lits[3];
};

vector<Clause> parse_cnf(string cnf_str) {
    vector<Clause> clauses;
    stringstream ss(cnf_str);
    string segment;
    while (getline(ss, segment, '&')) {
        Clause c;
        int lit_count = 0;
        string lits_part = segment.substr(1, segment.length() - 2);
        stringstream lits_ss(lits_part);
        string lit_str;
        while (getline(lits_ss, lit_str, '|')) {
            Literal l;
            if (lit_str[0] == '!') {
                l.is_neg = true;
                l.var_idx = lit_str[1] - 'a';
            }
            else {
                l.is_neg = false;
                l.var_idx = lit_str[0] - 'a';
            }
            c.lits[lit_count++] = l;
        }
        clauses.push_back(c);
    }
    return clauses;
}

bool is_clause_satisfied(const Clause& c, const vector<bool>& assignments) {
    for (int i = 0; i < 3; i++) {
        bool lit_val = assignments[c.lits[i].var_idx];
        if (c.lits[i].is_neg) lit_val = !lit_val;
        if (lit_val) return true;
    }
    return false;
}

bool is_cnf_satisfied(const vector<Clause>& clauses, const vector<bool>& assignments) {
    for (const auto& c : clauses) {
        if (!is_clause_satisfied(c, assignments)) return false;
    }
    return true;
}

bool solve(int var_idx, int N, const vector<Clause>& clauses, vector<bool>& assignments) {
    if (var_idx == N) return is_cnf_satisfied(clauses, assignments);
    
    assignments[var_idx] = false;
    if (solve(var_idx + 1, N, clauses, assignments)) return true;

    assignments[var_idx] = true;
    if(solve(var_idx + 1, N, clauses, assignments)) return true;
    
    return false;
}

void test() {
    int var_count;
    cin >> var_count;
    string cnf_str;
    cin >> cnf_str;

    vector<Clause> clauses = parse_cnf(cnf_str);
    vector<bool> assignments(var_count);

    if (solve(0, var_count, clauses, assignments)) cout << "true" << endl;
    else cout << "false" << endl;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    while (testcase_count--) test();
    return 0;
}