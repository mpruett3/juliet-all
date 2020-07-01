/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_file_attrib_created_12.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: file_attrib_created
 *    GoodSink: Do not modify the file's created time attribute
 *    BadSink : Modify the file's created time attribute
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* Note that the FILETIME structure is based on 100-nanosecond intervals.
 * It is helpful to define the following symbols when working with file times.
 * http://support.microsoft.com/kb/188768
 */
#define _SECOND ((INT64)10000000)
#define _MINUTE (60 * _SECOND)
#define _HOUR   (60 * _MINUTE)
#define _DAY    (24 * _HOUR)


#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            HANDLE hFile = CreateFile(TEXT("goodFile.txt"),
                                      GENERIC_READ | GENERIC_WRITE,
                                      0,
                                      NULL,
                                      CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, NULL);
            /* FIX: Do not modify the file's attributes */
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
    }
    else
    {
        {
            HANDLE hFile = CreateFile(TEXT("goodFile.txt"),
                                      GENERIC_READ | GENERIC_WRITE,
                                      0,
                                      NULL,
                                      CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, NULL);
            /* FIX: Do not modify the file's attributes */
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
    }
}

void CWE506_Embedded_Malicious_Code__w32_file_attrib_created_12_good()
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
    CWE506_Embedded_Malicious_Code__w32_file_attrib_created_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
