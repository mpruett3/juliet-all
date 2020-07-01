/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_67a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE843_Type_Confusion__char_67_structType
{
    void * structFirst;
} CWE843_Type_Confusion__char_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE843_Type_Confusion__char_67b_badSink(CWE843_Type_Confusion__char_67_structType myStruct);

void CWE843_Type_Confusion__char_67_bad()
{
    void * data;
    CWE843_Type_Confusion__char_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a char */
        char charBuffer = 'a';
        data = &charBuffer;
    }
    myStruct.structFirst = data;
    CWE843_Type_Confusion__char_67b_badSink(myStruct);
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
    CWE843_Type_Confusion__char_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
