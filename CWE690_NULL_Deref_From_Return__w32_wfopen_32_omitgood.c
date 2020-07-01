/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_32.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE690_NULL_Deref_From_Return__w32_wfopen_32_bad()
{
    FILE * data;
    FILE * *dataPtr1 = &data;
    FILE * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        FILE * data = *dataPtr1;
        /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
        data = _wfopen(L"file.txt", L"w+");
        *dataPtr1 = data;
    }
    {
        FILE * data = *dataPtr2;
        /* FLAW: if the fopen failed, data will be NULL here */
        fclose(data);
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif