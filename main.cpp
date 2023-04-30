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
    std::vector<int> p(N);
    for (size_t i = 0; i < p.size(); i++) {
        std::cin >> p[i];
    }

    if (N == 0 || N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    } else if (N == 2) {
        if (p[0] >= p[1]) {
            std::cout << 0 << std::endl;
            return 0;
        } else {
            std::cout << 1 << std::endl;
            std::cout << p[0] << " " << p[1] << std::endl;
            return 0;
        }
    }

    std::vector<std::pair<size_t, size_t>> pos;

    int sma = 0;
    for (size_t i = 0; i < p.size(); i++) {
        sma += p[i];
    }
    sma /= p.size();

    int min = sma, min_pos = 0;
    for (size_t i = 0; i < p.size(); i++) {
        if ((p[i] < sma) && (p[i] < min)) {
            min = p[i];
            min_pos = i;
        }
        if ((p[i] > sma)) {
            if (i == (p.size() - 1)) {
                if (p[i] >= p[i - 1]) {
                    pos.push_back(std::pair((min_pos + 1), (i + 1)));
                }
            } else {
                if ((p[(i + 1)] <= sma) && (i != 0)) {
                    pos.push_back(std::pair((min_pos + 1), (i + 1)));
                    min = sma;
                    min_pos = (min_pos + 1);
                }
            }
        }
        if (p.size() == 2) {
            break;
        }
    }

    std::cout << pos.size() << std::endl;
    for (size_t i = 0; i < pos.size(); i++) {
        std::cout << pos[i].first << " " << pos[i].second << std::endl;
    }
	return 0;
}
