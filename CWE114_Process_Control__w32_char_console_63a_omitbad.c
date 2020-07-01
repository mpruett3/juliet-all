/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_63a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: console Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_console_63b_goodG2BSink(char * * data);

static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    CWE114_Process_Control__w32_char_console_63b_goodG2BSink(&data);
}

void CWE114_Process_Control__w32_char_console_63_good()
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
    CWE114_Process_Control__w32_char_console_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
