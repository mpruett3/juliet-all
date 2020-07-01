/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_22b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

/* The global variable below is used to drive control flow in the sink function */
extern int CWE675_Duplicate_Operations_on_Resource__open_22_badGlobal;

void CWE675_Duplicate_Operations_on_Resource__open_22_badSink(int data)
{
    if(CWE675_Duplicate_Operations_on_Resource__open_22_badGlobal)
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CLOSE(data);
    }
}

#endif /* OMITBAD */

