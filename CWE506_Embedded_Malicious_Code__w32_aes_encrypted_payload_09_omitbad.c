/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_09.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: aes_encrypted_payload
 *    GoodSink: Use a plaintext payload in a system call
 *    BadSink : Use an AES encrypted payload in a system call
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "advapi32")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */


#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
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
    }
}

void CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_09_good()
{
    good1();
    good2();
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
    CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
