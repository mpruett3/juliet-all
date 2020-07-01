/*
 * @description Expression is always true via if (unsigned int >= 0)
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE571_Expression_Always_True__unsigned_int_01_bad() 
{
    /* Ensure (0 <= intBad < UINT_MAX) and that uIntBad is pseudo-random */
    unsigned int uIntBad = (unsigned int)(rand() * 2);

    /* FLAW: This expression is always true */
    if (uIntBad >= 0) 
    {
        printLine("Always prints");
    }
}

#endif /* OMITBAD */



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


#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE571_Expression_Always_True__unsigned_int_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
