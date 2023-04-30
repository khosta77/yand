#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>

//using namespace std;

int main() {
    size_t N;
    std::cin >> N;
    std::vector<int> a((N + 1));
    std::vector<int> b((N + 1));
    std::vector<int> c((N + 1));

    for (size_t i = 1; i <= N; ++i) {   std::cin >> a[i]; }
    for (size_t i = 1; i <= N; ++i) {   std::cin >> b[i]; }
    for (size_t i = 1; i <= N; ++i) {   std::cin >> c[i]; }

    size_t Q;
    std::cin >> Q;
    std::vector<int> x((Q + 1));
    std::vector<int> y((Q + 1));
    std::vector<int> z((Q + 1));

    for (size_t i = 1; i <= Q; ++i) {   std::cin >> x[i]; }
    for (size_t i = 1; i <= Q; ++i) {   std::cin >> y[i]; }
    for (size_t i = 1; i <= Q; ++i) {   std::cin >> z[i]; }

    std::vector<int> p;
    size_t buf;
    for (size_t i = 1; i <= Q; ++i) {
        buf = p.size();
        for (size_t j = 1; j <= N; ++j) {
            if ((x[i] == 0) && (y[i] == 0) && (z[i] == 0)) {
                if ((a[j] == 0) && (b[j] == 0) && ((c[j] == 0) || (c[j] == 1))) {
                    p.push_back(j);
                	j = (N + 1);
                }
            }

            if (((x[i] >= a[j]) && ((y[i] - b[j]) >= 0)) || ((z[i] == int(j)) && (c[j] == 1))) {
                p.push_back(j);
                j = (N + 1);
            }
        }
        if (p.size() == buf)
            p.push_back(0);
    }

    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << p[i];
        if (i != (p.size() - 1))
            std::cout << " ";
        else
            std::cout << std::endl;
    }
	return 0;
}


