/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_45.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static char * CWE401_Memory_Leak__strdup_char_45_badData;
static char * CWE401_Memory_Leak__strdup_char_45_goodG2BData;
static char * CWE401_Memory_Leak__strdup_char_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    char * data = CWE401_Memory_Leak__strdup_char_45_badData;
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__strdup_char_45_bad()
{
    char * data;
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
        /* Use data */
        printLine(data);
    }
    CWE401_Memory_Leak__strdup_char_45_badData = data;
    badSink();
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
    CWE401_Memory_Leak__strdup_char_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
