/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_22b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE690_NULL_Deref_From_Return__fopen_22_badGlobal;

void CWE690_NULL_Deref_From_Return__fopen_22_badSink(FILE * data)
{
    if(CWE690_NULL_Deref_From_Return__fopen_22_badGlobal)
    {
        /* FLAW: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

#endif /* OMITBAD */

