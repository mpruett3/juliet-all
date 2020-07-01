/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_62b.cpp
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_62
{

#ifndef OMITBAD

void badSource(wchar_t * &password)
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

#endif /* OMITBAD */


} /* close namespace */