/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_tempnam_18.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: tempnam
 *    GoodSink: Create and open a temporary file more securely, with mkstemp()
 *    BadSink : Create and open a temporary file, created with tempnam(), insecurely
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#define TEMPNAM tempnam
// to run on Windows, supply a replacement for Unix mkstemp()
#define MKSTEMP _mkstemp
static int _mkstemp(const char * t){
  size_t l = strlen(t) + 1;
  char s[50];
  strncpy(s, t, l);
  return _mktemp_s(s, l) ? -1 : _open(s, _O_CREAT|_O_EXCL);
}

#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#else
#define OPEN open
#define CLOSE close
#define TEMPNAM tempnam
#define MKSTEMP mkstemp
#endif


#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        char filename[] = "/tmp/fileXXXXXX"; // mutable store for filename
        // FIX: Use mkstemp(). This is not a perfect solution, since file
        // names are too predictable, but it is a vast improvement.
        int fileDesc = MKSTEMP(filename);
        printLine(filename);
        if (fileDesc != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fileDesc);
        }
    }
}

void CWE377_Insecure_Temporary_File__char_tempnam_18_good()
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
    CWE377_Insecure_Temporary_File__char_tempnam_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif