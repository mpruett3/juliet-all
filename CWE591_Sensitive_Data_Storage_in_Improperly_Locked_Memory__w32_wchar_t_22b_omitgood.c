/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22b.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badGlobal;

wchar_t * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badSource(wchar_t * password)
{
    if(CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badGlobal)
    {
        password = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (password == NULL)
        {
            printLine("Memory could not be allocated");
            exit(1);
        }
        /* FLAW: Do not lock the memory */
        /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
        wcscpy(password, L"Password1234!");
    }
    return password;
}

#endif /* OMITBAD */

