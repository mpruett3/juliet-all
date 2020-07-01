/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_52c.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__open_52c_badSink(int data)
{
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

#endif /* OMITBAD */
