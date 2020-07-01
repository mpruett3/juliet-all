/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_screen_capture_07.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.badonly.label.xml
Template File: point-flaw-badonly-07.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: screen_capture
 *    BadSink : Capture the screen and save it to a file
 *      BadOnly (No GoodSink)
 * Flow Variant: 07 Control flow: if(staticFive==5)
 *
 * */

#include "std_testcase.h"

#include "windows.h"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Gdi32.lib")

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


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
