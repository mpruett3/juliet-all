/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_62b.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: popen
 *    BadSink : Execute the popen function
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define BAD_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define GOOD_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define BAD_OS_COMMAND "ls -la"
#define GOOD_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

namespace CWE426_Untrusted_Search_Path__char_popen_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
    /* FIX: full path is specified */
    strcpy(data, GOOD_OS_COMMAND);
}

#endif /* OMITGOOD */

} /* close namespace */