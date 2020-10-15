#include "Basic.h"       // mode de base
#include "tcv.h"         // declaration de mes fonctions
#include <stdio.h>       // printf
#include <stdbool.h>

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* Fonctions de tests *********************/

void test_validerTH_1(void){
    CU_ASSERT_EQUAL(validerTH_1(170), true);
    CU_ASSERT_EQUAL(validerTH_1(400), true);
    CU_ASSERT_EQUAL(validerTH_1(160), false);
    CU_ASSERT_EQUAL(validerTH_1(410), false);
    CU_ASSERT_EQUAL(validerTH_1(169), false);
    CU_ASSERT_EQUAL(validerTH_1(401), false);
    CU_ASSERT_EQUAL(validerTH_1(0), false);
    CU_ASSERT_EQUAL(validerTH_1(-10), false);
}

void test_validerTH_2(void){
    CU_ASSERT_EQUAL(validerTH_2(127), false);
    CU_ASSERT_EQUAL(validerTH_2(0), false);
    CU_ASSERT_EQUAL(validerTH_2(-10), false);
    CU_ASSERT_EQUAL(validerTH_2(-128), false);
}

void test_validerTH_3(void){
    CU_ASSERT_EQUAL(validerTH_3(170), true);
    CU_ASSERT_EQUAL(validerTH_3(400), true);
    CU_ASSERT_EQUAL(validerTH_3(160), false);
    CU_ASSERT_EQUAL(validerTH_3(410), false);
    CU_ASSERT_EQUAL(validerTH_3(169), false);
    CU_ASSERT_EQUAL(validerTH_3(401), false);
    CU_ASSERT_EQUAL(validerTH_3(0), false);
    CU_ASSERT_EQUAL(validerTH_3(-10), false);
}

void test_validerTA_1(void){
    CU_ASSERT_EQUAL(validerTH_1(-400), true);
    CU_ASSERT_EQUAL(validerTH_1(400), true);
    CU_ASSERT_EQUAL(validerTH_1(-410), false);
    CU_ASSERT_EQUAL(validerTH_1(410), false);
    CU_ASSERT_EQUAL(validerTH_1(-401), false);
    CU_ASSERT_EQUAL(validerTH_1(401), false);
    CU_ASSERT_EQUAL(validerTH_1(0), true);
    CU_ASSERT_EQUAL(validerTH_1(-10), true);
}

void test_validerTA_2(void){
    CU_ASSERT_EQUAL(validerTH_2(-128), true);
    CU_ASSERT_EQUAL(validerTH_2(127), true);
    CU_ASSERT_EQUAL(validerTH_2(0), true);

}

void test_validerTA_3(void){
    CU_ASSERT_EQUAL(validerTH_3(-400), true);
    CU_ASSERT_EQUAL(validerTH_3(400), true);
    CU_ASSERT_EQUAL(validerTH_3(-410), false);
    CU_ASSERT_EQUAL(validerTH_3(410), false);
    CU_ASSERT_EQUAL(validerTH_3(-401), false);
    CU_ASSERT_EQUAL(validerTH_3(401), false);
    CU_ASSERT_EQUAL(validerTH_3(0), true);
    CU_ASSERT_EQUAL(validerTH_3(-10), true);
}

void test_validerPulsation_1(void){
    CU_ASSERT_EQUAL(validerPulsation_1(50), true);
    CU_ASSERT_EQUAL(validerPulsation_1(200), true);
    CU_ASSERT_EQUAL(validerPulsation_1(100), true);
    CU_ASSERT_EQUAL(validerPulsation_1(49), false);
    CU_ASSERT_EQUAL(validerPulsation_1(201), false);
    CU_ASSERT_EQUAL(validerPulsation_1(0), false);
    CU_ASSERT_EQUAL(validerPulsation_1(-10), false);
}

void test_validerPulsation_2(void){
    CU_ASSERT_EQUAL(validerPulsation_2(50), true);
    CU_ASSERT_EQUAL(validerPulsation_2(127), true);
    CU_ASSERT_EQUAL(validerPulsation_2(49), false);
    CU_ASSERT_EQUAL(validerPulsation_2(0), false);
    CU_ASSERT_EQUAL(validerPulsation_2(-10), false);
}

void test_validerPulsation_3(void){
    CU_ASSERT_EQUAL(validerPulsation_3(50), true);
    CU_ASSERT_EQUAL(validerPulsation_3(200), true);
    CU_ASSERT_EQUAL(validerPulsation_3(100), true);
    CU_ASSERT_EQUAL(validerPulsation_3(49), false);
    CU_ASSERT_EQUAL(validerPulsation_3(201), false);
    CU_ASSERT_EQUAL(validerPulsation_3(0), false);
    CU_ASSERT_EQUAL(validerPulsation_3(-10), false);
}

void test_validerSignal_1(void){
    CU_ASSERT_EQUAL(validerSignal_1(-85), true);
    CU_ASSERT_EQUAL(validerSignal_1(-25), true);
    CU_ASSERT_EQUAL(validerSignal_1(-45), true);
    CU_ASSERT_EQUAL(validerSignal_1(-86), false);
    CU_ASSERT_EQUAL(validerSignal_1(-24), false);
    CU_ASSERT_EQUAL(validerSignal_1(0), false);
    CU_ASSERT_EQUAL(validerSignal_1(10), false);
}

void test_validerSignal_2(void){
    CU_ASSERT_EQUAL(validerSignal_2(-85), true);
    CU_ASSERT_EQUAL(validerSignal_2(-25), true);
    CU_ASSERT_EQUAL(validerSignal_2(-45), true);
    CU_ASSERT_EQUAL(validerSignal_2(-86), false);
    CU_ASSERT_EQUAL(validerSignal_2(-24), false);
    CU_ASSERT_EQUAL(validerSignal_2(0), false);
    CU_ASSERT_EQUAL(validerSignal_2(10), false);
}

void test_validerSignal_3(void){
    CU_ASSERT_EQUAL(validerSignal_3(-85), true);
    CU_ASSERT_EQUAL(validerSignal_3(-25), true);
    CU_ASSERT_EQUAL(validerSignal_3(-45), true);
    CU_ASSERT_EQUAL(validerSignal_3(-86), false);
    CU_ASSERT_EQUAL(validerSignal_3(-24), false);
    CU_ASSERT_EQUAL(validerSignal_3(0), false);
    CU_ASSERT_EQUAL(validerSignal_3(10), false);
}

/************* Nous debutons l'execution des tests **************/

int main ( void )
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if ( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
    if ( NULL == pSuite ) {
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
    ){
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
