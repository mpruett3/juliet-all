/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_05.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameW(), more securely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameW(), insecurely
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <windows.h>

#define OPEN _wopen
#define CLOSE _close
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_05_bad()
{
    if(staticTrue)
    {
        {
            wchar_t filename[MAX_PATH] = L"";
            int fileDesc;
            /* FLAW: Passing 0 in for uUnique tells GetTempFileName to create and then close the file,
            * leading to an inescapable race condition when we try to open it again. */
            if (GetTempFileNameW(L".", L"bad", 0, filename) == 0)
            {
                exit(1);
            }
            printWLine(filename);
            /* FLAW: Open a temporary file using open() and flags that do not prevent a race condition */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
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
    CWE377_Insecure_Temporary_File__wchar_t_w32GetTempFileName_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
