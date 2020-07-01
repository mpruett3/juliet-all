/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_01.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#define FDOPEN fdopen
// to run on Windows, supply a replacement for Unix mkstemp()
#define MKSTEMP _mkstemp
static int _mkstemp(const char * t){
  size_t l = strlen(t) + 1;
  char s[50];
  strncpy(s, t, l);
  return _mktemp_s(s, l) ? -1 : _open(s, _O_CREAT|_O_EXCL);
}

#else
#include <unistd.h>
#define UNLINK unlink
#define FDOPEN fdopen
#define MKSTEMP mkstemp
#endif


#ifndef OMITGOOD

static void good1()
{
    {
        char filename[] = "goodXXXXXX";
        FILE *pFile;
        /* Establish that this is a temporary file and that it should be deleted */
        int fileDesc = MKSTEMP(filename);
        if (fileDesc != -1)
        {
            pFile = FDOPEN(fileDesc, "w");
            if (pFile != NULL)
            {
                fprintf(pFile, "Temporary file");
                fclose(pFile);
                /* FIX: Unlink the temporary file */
                UNLINK(filename); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

void CWE459_Incomplete_Cleanup__char_01_good()
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
    CWE459_Incomplete_Cleanup__char_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif