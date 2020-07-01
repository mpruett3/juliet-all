/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_16.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: aes_encrypted_payload
 *    GoodSink: Use a plaintext payload in a system call
 *    BadSink : Use an AES encrypted payload in a system call
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "advapi32")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */


#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            /* FIX: plaintext command */
            char * payload = "calc.exe";
            if(system(payload) <= 0)
            {
                printLine("command execution failed!");
                exit(1);
            }
        }
        break;
    }
}

void CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_16_good()
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
    CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
