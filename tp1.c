#include "Basic.h"       // mode de base
#include "tcv.h"         // declaration de mes fonctions
#include <stdio.h>       // printf
#include <stdbool.h>

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }

int clean_suite(void) { return 0; }

/********************* Fonctions de tests *********************/

void test_validerTH_1(void) {
    for (int i = -2147483648; i < 2147483647; ++i) {
        if (i < 170 || i > 400) {
            CU_ASSERT_EQUAL(validerTH_1(i), false);
        } else {
            CU_ASSERT_EQUAL(validerTH_1(i), true);
        }
    }
}

void test_validerTH_2(void) {
    for (int i = -128; i < 127; ++i) {
        CU_ASSERT_EQUAL(validerTH_2(i), false);
    }
}

void test_validerTH_3(void) {
    for (int i = -32768; i < 32767; ++i) {
        if (i < 170 || i > 400) {
            CU_ASSERT_EQUAL(validerTH_3(i), false);
        } else {
            CU_ASSERT_EQUAL(validerTH_3(i), true);
        }
    }
}

void test_validerTA_1(void) {
    for (int i = -2147483648; i < 2147483647; ++i) {
        if (i < -400 || i > 400) {
            CU_ASSERT_EQUAL(validerTA_1(i), false);
        } else {
            CU_ASSERT_EQUAL(validerTA_1(i), true);
        }
    }
}

void test_validerTA_2(void) {
    for (int i = -128; i < 127; ++i) {
        CU_ASSERT_EQUAL(validerTA_2(i), true);
    }
}

void test_validerTA_3(void) {
    for (int i = -32768; i < 32767; ++i) {
        if (i < -400 || i > 400) {
            CU_ASSERT_EQUAL(validerTA_3(i), false);
        } else {
            CU_ASSERT_EQUAL(validerTA_3(i), true);
        }
    }
}

void test_validerPulsation_1(void) {
    for (int i = -2147483648; i < 2147483647; ++i) {
        if (i < 50 || i > 200) {
            CU_ASSERT_EQUAL(validerPulsation_1(i), false);
        } else {
            CU_ASSERT_EQUAL(validerPulsation_1(i), true);
        }
    }
}

void test_validerPulsation_2(void) {
    for (int i = -128; i < 127; ++i) {
        if (i < 50) {
            CU_ASSERT_EQUAL(validerPulsation_2(i), false);
        } else {
            CU_ASSERT_EQUAL(validerPulsation_2(i), true);
        }
    }
}

void test_validerPulsation_3(void) {
    for (int i = -32768; i < 32767; ++i) {
        if (i < 50 || i > 200) {
            CU_ASSERT_EQUAL(validerPulsation_3(i), false);
        } else {
            CU_ASSERT_EQUAL(validerPulsation_3(i), true);
        }
    }
}

void test_validerSignal_1(void) {
    for (int i = -2147483648; i < 2147483647; ++i) {
        if (i < -85 || i > -25) {
            CU_ASSERT_EQUAL(validerSignal_1(i), false);
        } else {
            CU_ASSERT_EQUAL(validerSignal_1(i), true);
        }
    }
}

void test_validerSignal_2(void) {
    for (int i = -128; i < 127; ++i) {
        if (i < -85 || i > -25) {
            CU_ASSERT_EQUAL(validerSignal_2(i), false);
        } else {
            CU_ASSERT_EQUAL(validerSignal_2(i), true);
        }
    }
}

void test_validerSignal_3(void) {
    for (int i = -32768; i < 32767; ++i) {
        if (i < -85 || i > -25) {
            CU_ASSERT_EQUAL(validerSignal_3(i), false);
        } else {
            CU_ASSERT_EQUAL(validerSignal_3(i), true);
        }
    }
}

/************* Nous debutons l'execution des tests **************/

int main(void) {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("max_test_suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_validerTH_1", test_validerTH_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_2", test_validerTH_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_3", test_validerTH_3)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_1", test_validerTA_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_2", test_validerTA_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_3", test_validerTA_3)) ||
        (NULL == CU_add_test(pSuite, "test_validerPulsation_1", test_validerPulsation_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerPulsation_2", test_validerPulsation_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerPulsation_3", test_validerPulsation_3)) ||
        (NULL == CU_add_test(pSuite, "test_validerSignal_1", test_validerSignal_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerSignal_2", test_validerSignal_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerSignal_3", test_validerSignal_3))
            ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
