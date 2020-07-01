/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE367_TOC_TOU__access_18.c
Label Definition File: CWE367_TOC_TOU.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 367 Time-of-Check Time-Of-Use Race Condition
 * Sinks: access
 *    GoodSink: Open the file without checking the status information
 *    BadSink : Get status information on file using access(), open, write to, and close the file
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define STAT _stat
#define OPEN _open
#define WRITE _write
#define O_RDWR _O_RDWR
#define CLOSE _close
#else
#include <unistd.h>
#define STAT stat
#define OPEN open
#define WRITE write
#define CLOSE close
#endif

#define BAD_SINK_STRING "Bad Sink..."
#define GOOD_SINK_STRING "Good Sink..."

#ifdef _WIN32
#define ACCESS _access
#define W_OK 02
#else
#define ACCESS access
#endif

#ifndef OMITBAD

void CWE367_TOC_TOU__access_18_bad()
{
    goto sink;
sink:
    {
        char filename[100] = "";
        int fileDesc = -1;
        if (fgets(filename, 100, stdin) == NULL)
        {
            printLine("fgets() failed");
            /* Restore NUL terminator if fgets fails */
            filename[0] = '\0';
        }
        if (strlen(filename) > 0)
        {
            filename[strlen(filename)-1] = '\0'; /* remove newline */
        }
        /* FLAW: Open and write to the file after checking the status information */
        if (ACCESS(filename, W_OK) == -1)
        {
            exit(1);
        }
        fileDesc  = OPEN(filename, O_RDWR);
        if (fileDesc == -1)
        {
            exit(1);
        }
        if (WRITE(fileDesc, BAD_SINK_STRING, strlen(BAD_SINK_STRING)) == -1)
        {
            exit(1);
        }
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
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
    CWE367_TOC_TOU__access_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif