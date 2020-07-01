/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_listen_socket_22a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE114_Process_Control__w32_wchar_t_listen_socket_22_badGlobal = 0;

wchar_t * CWE114_Process_Control__w32_wchar_t_listen_socket_22_badSource(wchar_t * data);

void CWE114_Process_Control__w32_wchar_t_listen_socket_22_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    CWE114_Process_Control__w32_wchar_t_listen_socket_22_badGlobal = 1; /* true */
    data = CWE114_Process_Control__w32_wchar_t_listen_socket_22_badSource(data);
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}

#endif /* OMITBAD */


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
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_listen_socket_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
