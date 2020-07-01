/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_67a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE675_Duplicate_Operations_on_Resource__freopen_67_structType
{
    FILE * structFirst;
} CWE675_Duplicate_Operations_on_Resource__freopen_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__freopen_67b_goodG2BSink(CWE675_Duplicate_Operations_on_Resource__freopen_67_structType myStruct);

static void goodG2B()
{
    FILE * data;
    CWE675_Duplicate_Operations_on_Resource__freopen_67_structType myStruct;
    data = NULL; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
    myStruct.structFirst = data;
    CWE675_Duplicate_Operations_on_Resource__freopen_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__freopen_67b_goodB2GSink(CWE675_Duplicate_Operations_on_Resource__freopen_67_structType myStruct);

static void goodB2G()
{
    FILE * data;
    CWE675_Duplicate_Operations_on_Resource__freopen_67_structType myStruct;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    myStruct.structFirst = data;
    CWE675_Duplicate_Operations_on_Resource__freopen_67b_goodB2GSink(myStruct);
}

void CWE675_Duplicate_Operations_on_Resource__freopen_67_good()
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
    CWE675_Duplicate_Operations_on_Resource__freopen_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif