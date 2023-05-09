#ifndef YAND_TEST_H_
#define YAND_TEST_H_

#include "CPUTime.h"
#include "test_obj.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>
#include <iomanip>


#define CONTROL_TIME (double(0.002))

class MyTest {
    std::vector<test_obj> array_tests;

    int print_result_error(const size_t &n) {
        std::cout << "Тест №" << std::setw(3) << (n + 1) << "| Результат не верный" << std::endl;
        return -1;
    }

    int print_time_error(const size_t &n, const double &t) {
        std::cout << "Тест №" << std::setw(3) << (n + 1) << "| Долго: " << t << " [c]" << std::endl;
        return -1;
    }

    void print_success(const size_t &n) {
        std::cout << "Тест №" << std::setw(3) << (n + 1) << "| SUCCESS" << std::endl;
    }

public:
    MyTest() {}

    void add(int (*f)()) {
        array_tests.push_back(test_obj(f));
    }

    int make() {
        double startTime, endTime;
        int result;
        for (size_t i = 0; i < array_tests.size(); ++i) {
            startTime = getCPUTime();
            result = array_tests[i].foo();
            endTime = getCPUTime();
            
            if (result != 0)
                return print_result_error(i);
            
            if ((endTime - startTime) >= CONTROL_TIME)
                return print_time_error(i, (endTime - startTime));

            print_success(i);
        }
        return 0;
    }
};

#endif // YAND_TEST_H_
