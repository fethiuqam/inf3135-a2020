#include "Basic.h"       // mode de base
//#include "Automated.h"
//#include "Console.h"
#include "tcv.h"         // declaration de mes fonctions
#include <stdio.h>       // printf
#include <stdbool.h>

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* NOS fonctions de tests *********************/
/*
void test_case_exemple(void)
{
   // Les types d'assertions disponibles
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/
/*void max_test_un(void) {
    CU_ASSERT_EQUAL( max(1,2), 2);
    CU_ASSERT_EQUAL( max(2,1), 2);
}

void max_test_deux(void) {
    CU_ASSERT_EQUAL( max(2,2), 2);
    CU_ASSERT_EQUAL( max(0,0), 0);
    CU_ASSERT_EQUAL( max(-1,-1), -1);
}

void max_test_trois(void) {
    CU_ASSERT_EQUAL( max(-1,-2), -1);
}*/

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
    CU_ASSERT_EQUAL(validerTH_2(170), true);
    CU_ASSERT_EQUAL(validerTH_2(400), true);
    CU_ASSERT_EQUAL(validerTH_2(160), false);
    CU_ASSERT_EQUAL(validerTH_2(410), false);
    CU_ASSERT_EQUAL(validerTH_2(169), false);
    CU_ASSERT_EQUAL(validerTH_2(401), false);
    CU_ASSERT_EQUAL(validerTH_2(0), false);
    CU_ASSERT_EQUAL(validerTH_2(-10), false);
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
    CU_ASSERT_EQUAL(validerTH_2(-400), true);
    CU_ASSERT_EQUAL(validerTH_2(400), true);
    CU_ASSERT_EQUAL(validerTH_2(-410), false);
    CU_ASSERT_EQUAL(validerTH_2(410), false);
    CU_ASSERT_EQUAL(validerTH_2(-401), false);
    CU_ASSERT_EQUAL(validerTH_2(401), false);
    CU_ASSERT_EQUAL(validerTH_2(0), true);
    CU_ASSERT_EQUAL(validerTH_2(-10), true);
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
    /*if ( (NULL == CU_add_test(pSuite, "max_test_1", max_test_un)) ||
         (NULL == CU_add_test(pSuite, "max_test_2", max_test_deux)) ||
         (NULL == CU_add_test(pSuite, "max_test_3", max_test_trois))
            )
    {*/
    if ((NULL == CU_add_test(pSuite, "test_validerTH_1", test_validerTH_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_2", test_validerTH_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerTH_3", test_validerTH_3)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_1", test_validerTA_1)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_2", test_validerTA_2)) ||
        (NULL == CU_add_test(pSuite, "test_validerTA_3", test_validerTA_3))
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
/*
   // LES modes interactifs
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
