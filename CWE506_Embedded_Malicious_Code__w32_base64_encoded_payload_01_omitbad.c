/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_base64_encoded_payload_01.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: base64_encoded_payload
 *    GoodSink: Use a plaintext payload in a system call
 *    BadSink : Use a base64 encoded payload in a system call
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "crypt32.lib")


#ifndef OMITGOOD

static void good1()
{
    {
        /* FIX: plaintext command */
        char * decodedPayload = "calc.exe";
        if (system(decodedPayload) <= 0)
        {
            printLine("command execution failed!");
            exit(1);
        }
    }
}

void CWE506_Embedded_Malicious_Code__w32_base64_encoded_payload_01_good()
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
    CWE506_Embedded_Malicious_Code__w32_base64_encoded_payload_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
