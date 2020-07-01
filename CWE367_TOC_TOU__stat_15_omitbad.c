/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE367_TOC_TOU__stat_15.c
Label Definition File: CWE367_TOC_TOU.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 367 Time-of-Check Time-Of-Use Race Condition
 * Sinks: stat
 *    GoodSink: Open the file without checking the status information
 *    BadSink : Get status information on file using stat(), open, write to, and close the file
 * Flow Variant: 15 Control flow: switch(6)
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


#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
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
        /* FIX: Open the file without checking the status information */
        fileDesc  = OPEN(filename, O_RDWR);
        if (fileDesc == -1)
        {
            exit(1);
        }
        if (WRITE(fileDesc, GOOD_SINK_STRING, strlen(GOOD_SINK_STRING)) == -1)
        {
            exit(1);
        }
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
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
        /* FIX: Open the file without checking the status information */
        fileDesc  = OPEN(filename, O_RDWR);
        if (fileDesc == -1)
        {
            exit(1);
        }
        if (WRITE(fileDesc, GOOD_SINK_STRING, strlen(GOOD_SINK_STRING)) == -1)
        {
            exit(1);
        }
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE367_TOC_TOU__stat_15_good()
{
    good1();
    good2();
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
    CWE367_TOC_TOU__stat_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif