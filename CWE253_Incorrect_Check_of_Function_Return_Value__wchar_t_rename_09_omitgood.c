/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_09.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: rename
 *    GoodSink: Correctly check if rename() failed
 *    BadSink : Incorrectlycheck if rename() failed
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define RENAME _wrename
#else
#define RENAME rename
#endif

#define OLD_BAD_FILE_NAME L"oldbadfilename.txt"
#define OLD_GOOD_FILE_NAME L"oldgoodfilename.txt"
#define NEW_BAD_FILE_NAME L"newbadfilename.txt"
#define NEW_GOOD_FILE_NAME L"newgoodfilename.txt"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: rename() might fail, in which case the return value will be non-zero, but
         * we are checking to see if the return value is 0 */
        if (RENAME(OLD_BAD_FILE_NAME, NEW_BAD_FILE_NAME) == 0)
        {
            printLine("rename failed!");
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_rename_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
