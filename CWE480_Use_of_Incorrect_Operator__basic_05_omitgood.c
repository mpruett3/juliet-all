/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE480_Use_of_Incorrect_Operator__basic_05.c
Label Definition File: CWE480_Use_of_Incorrect_Operator__basic.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 480 Use of Incorrect Operator
 * Sinks:
 *    GoodSink: Include parens
 *    BadSink : Forget parens
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

static char* staticStringBad = "Hello";
static char* staticStringGood = "Hello";

static char * helperBad()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringBad;
    }
}

static char * helperGood()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringGood;
    }
}

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE480_Use_of_Incorrect_Operator__basic_05_bad()
{
    if(staticTrue)
    {
        /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
        if(helperBad == NULL)
        {
            printLine("Got a NULL");
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
    CWE480_Use_of_Incorrect_Operator__basic_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
