/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_tmpnam_06.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: tmpnam
 *    GoodSink: Create and open a temporary file, created with _wtmpnam(), more securely
 *    BadSink : Create and open a temporary file, created with _wtmpnam(), insecurely
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
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
#define TMPNAM _wtmpnam
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#else
#define OPEN open
#define CLOSE close
#define TMPNAM tmpnam
#endif

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_tmpnam_06_bad()
{
    if(STATIC_CONST_FIVE==5)
    {
        {
            wchar_t * filename;
            int fileDesc;
            filename = TMPNAM(NULL);
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
    CWE377_Insecure_Temporary_File__wchar_t_tmpnam_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif