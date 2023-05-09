#ifndef YAND_TEST_OBJ_H_
#define YAND_TEST_OBJ_H_


struct test_obj {
    int (*foo)();

    test_obj(int (*f)()) : foo(f) {} 
};

#endif // YAND_TEST_OBJ_H_
