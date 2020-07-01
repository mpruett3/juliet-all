/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_email_08.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.badonly.label.xml
Template File: point-flaw-badonly-08.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: email
 *    BadSink : Send an e-mail
 *      BadOnly (No GoodSink)
 * Flow Variant: 08 Control flow: if(staticReturnsTrue())
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CRLF "\r\n"
#define MAIL_SERVER "smtp.gmail.com"

/* The function below always return the same value, so a tool
   should be able to identify that calls to this function will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}


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