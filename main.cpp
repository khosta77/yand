#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>

//using namespace std;

bool cmp(const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) {
    return a.second < b.second;
}
 
std::vector<std::pair<size_t, size_t>> my_sort(const std::map<size_t, size_t>& M) {
    std::vector<std::pair<size_t, size_t>> A;
    for (auto& it : M) {
        A.push_back(it);
    }
    std::sort(A.begin(), A.end(), cmp);
    return A;
}


int main() {
    size_t N, X, T;
    std::cin >> N >> X >> T;
    std::vector<size_t> a(N);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }

    std::map<size_t, size_t> delta_a;
    for (size_t i = 0; i < N; i++) {
        delta_a[(i + 1)] = size_t(abs(int(X - a[i])));
    }

    auto new_delta_a = my_sort(delta_a);

    std::vector<size_t> out;
    size_t new_T = T;
    for (auto& it : new_delta_a) {
        new_T -= it.second;
        if (new_T <= T) {
            out.push_back(it.first);
        } else {
            break;
        }
    }

    std::cout << out.size() << std::endl;
    for (size_t i = 0; i < out.size(); i++) {
        std::cout << out[i] << " ";
    }
    std::cout << std::endl;
	return 0;
}
