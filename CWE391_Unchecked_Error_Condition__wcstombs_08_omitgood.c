/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__wcstombs_08.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: wcstombs
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if wcstombs() failed
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <errno.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__wcstombs_08_bad()
{
    if(staticReturnsTrue())
    {
        {
            size_t bytesTranslated = 0;
            char charString[100];
            charString[0] = '\0';
            bytesTranslated = wcstombs((char *)&charString, L"\xffff", 100);
            /* FLAW: Do not check to see if wcstombs() failed */
            printUnsignedLine(bytesTranslated);
            printLine(charString);
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
    CWE391_Unchecked_Error_Condition__wcstombs_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif