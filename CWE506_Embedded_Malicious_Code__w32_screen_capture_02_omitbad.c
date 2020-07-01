/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_screen_capture_02.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.badonly.label.xml
Template File: point-flaw-badonly-02.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: screen_capture
 *    BadSink : Capture the screen and save it to a file
 *      BadOnly (No GoodSink)
 * Flow Variant: 02 Control flow: if(1)
 *
 * */

#include "std_testcase.h"

#include "windows.h"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Gdi32.lib")


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
    return 0;
}

#endif
