/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_64a.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__strdup_char_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    char * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (char *)ALLOCA(100*sizeof(char));
    /* Initialize then use data */
    strcpy(data, "a string");
    printLine(data);
    CWE401_Memory_Leak__strdup_char_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__strdup_char_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
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
    CWE401_Memory_Leak__strdup_char_64b_goodB2GSink(&data);
}

void CWE401_Memory_Leak__strdup_char_64_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE401_Memory_Leak__strdup_char_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif