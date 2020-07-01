/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fopen_09.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    GoodSink: Check to see if fopen() failed and handle errors properly
 *    BadSink : Check to see if fopen() failed, but fail to handle errors
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__fopen_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FLAW: Check to see if fopen failed, but do nothing about it */
            if (fileDesc == NULL)
            {
                /* do nothing */
            }
            fclose(fileDesc);
        }
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__fopen_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
