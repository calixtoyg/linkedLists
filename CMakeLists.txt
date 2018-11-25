cmake_minimum_required(VERSION 3.12)
project(linkedlist_cascara_v5 C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(testing)
include_directories(testing/inc)

add_executable(linkedlist_cascara_v5
        inc/LinkedList.h
        src/LinkedList.c
        src/main.c
        testing/inc/addNodeTest.h
        testing/inc/addTest.h
        testing/inc/clearTest.h
        testing/inc/cloneTest.h
        testing/inc/containsAllTest.h
        testing/inc/containsTest.h
        testing/inc/deleteLinkedListTest.h
        testing/inc/Employee.h
        testing/inc/getNodeTest.h
        testing/inc/getTest.h
        testing/inc/indexOfTest.h
        testing/inc/isEmptyTest.h
        testing/inc/lenTest.h
        testing/inc/main_test.h
        testing/inc/newTest.h
        testing/inc/popTest.h
        testing/inc/pushTest.h
        testing/inc/removeTest.h
        testing/inc/setTest.h
        testing/inc/sortTest.h
        testing/inc/subListTest.h
        testing/src/addNodeTest.c
        testing/src/addTest.c
        testing/src/clearTest.c
        testing/src/cloneTest.c
        testing/src/containsAllTest.c
        testing/src/containsTest.c
        testing/src/deleteLinkedListTest.c
        testing/src/Employee.c
        testing/src/getNodeTest.c
        testing/src/getTest.c
        testing/src/indexOfTest.c
        testing/src/isEmptyTest.c
        testing/src/lenTest.c
        testing/src/main_test.c
        testing/src/newTest.c
        testing/src/popTest.c
        testing/src/pushTest.c
        testing/src/removeTest.c
        testing/src/setTest.c
        testing/src/sortTest.c
        testing/src/subListTest.c
        testing/utest.c
        testing/utest.h)
