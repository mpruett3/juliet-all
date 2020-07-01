/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: sscanf
 *    GoodSink: Correctly check if sscanf() failed
 *    BadSink : Incorrectly check if sscanf() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC_STRING "string"


#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FIX: check for the correct return value */
        if (sscanf(SRC_STRING, "%99s\0", data) == EOF)
        {
            printLine("sscanf failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18_good()
{
    good1();
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_sscanf_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif