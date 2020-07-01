/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_01.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationW() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationW() with excessive privileges
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )


#ifndef OMITGOOD

static void good1()
{
    {
        HWINSTA hWinStation;
        wchar_t * wStationName = L"WindowsStationExample";
        /* FIX: Call CreateWindowStationW() without GENERIC_READ as the 3rd parameter to limit access */
        hWinStation = CreateWindowStationW(
                          wStationName,
                          0,
                          GENERIC_READ,
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

void CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_01_good()
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
    CWE284_Improper_Access_Control__w32_wchar_t_CreateWindowStation_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif