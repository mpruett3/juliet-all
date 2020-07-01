/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_22b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE675_Duplicate_Operations_on_Resource__freopen_22_badGlobal;

void CWE675_Duplicate_Operations_on_Resource__freopen_22_badSink(FILE * data)
{
    if(CWE675_Duplicate_Operations_on_Resource__freopen_22_badGlobal)
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

#endif /* OMITBAD */

