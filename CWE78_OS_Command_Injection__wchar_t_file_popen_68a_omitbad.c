/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_popen_68a.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: file Read input from a file
 * GoodSource: Fixed string
 * Sink: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"ls "
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

wchar_t * CWE78_OS_Command_Injection__wchar_t_file_popen_68_badData;
wchar_t * CWE78_OS_Command_Injection__wchar_t_file_popen_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE78_OS_Command_Injection__wchar_t_file_popen_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
    CWE78_OS_Command_Injection__wchar_t_file_popen_68_goodG2BData = data;
    CWE78_OS_Command_Injection__wchar_t_file_popen_68b_goodG2BSink();
}

void CWE78_OS_Command_Injection__wchar_t_file_popen_68_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__wchar_t_file_popen_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif