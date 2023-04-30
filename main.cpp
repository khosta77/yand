#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

//using namespace std;

int main() {
    // 1. Ввод кол-во букв
    size_t N;
    std::cin >> N;
    // 2. Ввод колличества букв и их позиций
    std::vector<size_t> c(N), r(N);
    for (size_t i = 0; i < c.size(); i++)
        std::cin >> c[i];
    for (size_t i = 0; i < r.size(); i++)
        std::cin >> r[i];
    std::map<size_t, size_t> symbolAposition;

    for (size_t i = 0; i < N; i++) {
        symbolAposition[c[i]] = r[i];
    }

    // 3. Введем слово
    size_t K;
    std::cin >> K;
    std::vector<size_t> s(K);
    for (size_t i = 0; i < s.size(); i++)
        std::cin >> s[i];

    // считаем колличество
    size_t count = 0;
    for (size_t i = 0; i < (s.size() - 1); i++) {
        if (symbolAposition[s[i]] != symbolAposition[s[(i + 1)]]) {
            ++count;
        }
    }
    std::cout << count << std::endl;
	return 0;
}
