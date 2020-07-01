/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sinks: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

typedef struct _CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_structType
{
    int structFirst;
} CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67b_badSink(CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_structType myStruct);

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_bad()
{
    int data;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_structType myStruct;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    myStruct.structFirst = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67b_badSink(myStruct);
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memmove_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif