/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_01.c
Label Definition File: CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 785 Path Manipulation Function Without Max Sized Buffer
 * Sinks:
 *    GoodSink: Ensure the path parameter is MAX_PATH
 *    BadSink : Use PathAppend() with a buffer that is less than MAX_PATH
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi")

#define BAD_PATH_SIZE (MAX_PATH / 2) /* maintenance note: must be < MAX_PATH in order for 'bad' to be 'bad' */


#ifndef OMITGOOD

static void good1()
{
    {
        /* FIX: ensure MAX_PATH allocated in 'path' */
        char path[MAX_PATH];
        DWORD length;
        length = GetCurrentDirectoryA(MAX_PATH, path);
        if (length == 0 || length >= MAX_PATH)
        {
            exit(1); /* failure conditions for this API call */
        }
        if (!PathAppendA(path, "AAAAAAAAAAAA"))
        {
            exit(1);
        }
        printLine(path);
    }
}

void CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_01_good()
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
    CWE785_Path_Manipulation_Function_Without_Max_Sized_Buffer__w32_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
