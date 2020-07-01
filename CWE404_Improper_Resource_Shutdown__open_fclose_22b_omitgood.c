/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_22b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE404_Improper_Resource_Shutdown__open_fclose_22_badGlobal;

void CWE404_Improper_Resource_Shutdown__open_fclose_22_badSink(int data)
{
    if(CWE404_Improper_Resource_Shutdown__open_fclose_22_badGlobal)
    {
        if (data != -1)
        {
            /* FLAW: Attempt to close the file using fclose() instead of close() */
            fclose((FILE *)data);
        }
    }
}

#endif /* OMITBAD */

