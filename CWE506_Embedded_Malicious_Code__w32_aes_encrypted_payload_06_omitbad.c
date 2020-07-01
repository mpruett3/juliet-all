/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_06.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: aes_encrypted_payload
 *    GoodSink: Use a plaintext payload in a system call
 *    BadSink : Use an AES encrypted payload in a system call
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "advapi32")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;


#ifndef OMITGOOD

/* good1() uses if(STATIC_CONST_FIVE!=5) instead of if(STATIC_CONST_FIVE==5) */
static void good1()
{
    if(STATIC_CONST_FIVE!=5)
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
    if(STATIC_CONST_FIVE==5)
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

void CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_06_good()
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
    CWE506_Embedded_Malicious_Code__w32_aes_encrypted_payload_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
