/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_sleep_44.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

#ifndef OMITBAD

static void badSink(int count)
{
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}

void CWE400_Resource_Exhaustion__rand_sleep_44_bad()
{
    int count;
    /* define a function pointer */
    void (*funcPtr) (int) = badSink;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    /* use the function pointer */
    funcPtr(count);
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
    CWE400_Resource_Exhaustion__rand_sleep_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
