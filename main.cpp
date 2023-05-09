#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

//using namespace std;

#include "test.h"

size_t task_1(size_t *c, size_t *r, const size_t &cr_N, size_t *s, const size_t &s_N) {
	const size_t SIZE_SA = (*std::max_element(c, (c + cr_N)) + 1); 
	int symbolAposition[SIZE_SA];
	// Для подстраховки будем записывать -1 в массив
	for (size_t i = 0; i < SIZE_SA; ++i)
		symbolAposition[i] = -1;
	// Выписываем уникальные символы в массив
	for (size_t i = 0; i < cr_N; ++i)
		symbolAposition[*(c + i)] = *(r + i);
	
	size_t count = 0;
    for (size_t i = 0; i < (s_N - 1); ++i)
        if (symbolAposition[*(s + i)] != symbolAposition[*(s + (i + 1))])
            ++count;
	return count;
}

int test1() {
	const size_t cr_N = 4;
	size_t c[cr_N] = {1, 3, 5, 6};
	size_t r[cr_N] = {1, 2, 1, 2};
	const size_t s_N = 5;
	size_t s[s_N] = {1, 3, 5, 6, 3};
	int res = task_1(c, r, cr_N, s, s_N);
	if (res == 3)
		return 0;
	return 1;
}

int main() {
	MyTest tt;
	tt.add(*test1);
	return tt.make();
#if 0
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
#endif
	return 0;
}
