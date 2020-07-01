/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_34.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE401_Memory_Leak__strdup_char_34_unionType;

#ifndef OMITBAD

void CWE401_Memory_Leak__strdup_char_34_bad()
{
    char * data;
    CWE401_Memory_Leak__strdup_char_34_unionType myUnion;
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
        /* Use data */
        printLine(data);
    }
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: No deallocation of memory */
        /* no deallocation */
        ; /* empty statement needed for some flow variants */
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
    CWE401_Memory_Leak__strdup_char_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
