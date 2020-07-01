/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_CreateWindowStation_14.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationA() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationA() with excessive privileges
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_char_CreateWindowStation_14_bad()
{
    if(globalFive==5)
    {
        {
            HWINSTA hWinStation;
            char * wStationName = "WindowsStationExample";
            /* FLAW: Call CreateWindowStationA() with GENERIC_ALL as the 3rd parameter */
            hWinStation = CreateWindowStationA(
                              wStationName,
                              0,
                              GENERIC_ALL,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_char_CreateWindowStation_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
