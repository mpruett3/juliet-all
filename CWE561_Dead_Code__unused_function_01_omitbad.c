/*
 * @description Unused function declaration
 * 
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* FIX: this function is used */
static void helperGood1() 
{
    printLine("helperGood1()");
}

static void good1() 
{
    printLine("CWE561_Dead_Code__unused_function_01_good()");
    helperGood1();
}

void CWE561_Dead_Code__unused_function_01_good() 
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) 
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );

#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE561_Dead_Code__unused_function_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */


    return 0;
} 

#endif
