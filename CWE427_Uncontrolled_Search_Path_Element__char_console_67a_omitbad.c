/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_console_67a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: console Read input from the console
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

typedef struct _CWE427_Uncontrolled_Search_Path_Element__char_console_67_structType
{
    char * structFirst;
} CWE427_Uncontrolled_Search_Path_Element__char_console_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__char_console_67b_goodG2BSink(CWE427_Uncontrolled_Search_Path_Element__char_console_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE427_Uncontrolled_Search_Path_Element__char_console_67_structType myStruct;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    myStruct.structFirst = data;
    CWE427_Uncontrolled_Search_Path_Element__char_console_67b_goodG2BSink(myStruct);
}

void CWE427_Uncontrolled_Search_Path_Element__char_console_67_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE427_Uncontrolled_Search_Path_Element__char_console_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif