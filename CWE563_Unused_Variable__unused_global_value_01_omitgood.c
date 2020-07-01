/*
 * @description Unused global value
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE563_Unused_Variable__unused_global_value_01_badGlobal = 0;

void CWE563_Unused_Variable__unused_global_value_01_bad() 
{
    /* FLAW: Overwrite the initial value of the global variable before use */
    CWE563_Unused_Variable__unused_global_value_01_badGlobal = 10;
    printIntLine(CWE563_Unused_Variable__unused_global_value_01_badGlobal);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on 
 *  its own for testing or for building a binary to use in testing binary 
 *  analysis tools. It is not used when compiling all the testcases as one 
 *  application, which is how source code analysis tools are tested. 
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) 
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );


#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_global_value_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif