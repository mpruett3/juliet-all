/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73a.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <windows.h>

using namespace std;

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<HANDLE> dataList);

void bad()
{
    HANDLE data;
    list<HANDLE> dataList;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_73; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
