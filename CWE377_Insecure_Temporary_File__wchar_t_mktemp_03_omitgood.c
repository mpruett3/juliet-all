/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_mktemp_03.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: mktemp
 *    GoodSink: Create and open a temporary file, created with _wmktemp(), more securely
 *    BadSink : Create and open a temporary file, created with _wmktemp(), insecurely
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef _WIN32
#define OPEN _wopen
#define CLOSE _close
#define MKTEMP _wmktemp
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#else
#define OPEN open
#define CLOSE close
#define MKTEMP mktemp
#endif

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_mktemp_03_bad()
{
    if(5==5)
    {
        {
            wchar_t * filename;
            wchar_t tmpl[] = L"fnXXXXXX";
            int fileDesc;
            filename = MKTEMP(tmpl);
            if (filename == NULL)
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
    CWE377_Insecure_Temporary_File__wchar_t_mktemp_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif