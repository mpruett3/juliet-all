/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_22b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE665_Improper_Initialization__char_ncat_22_badGlobal;

char * CWE665_Improper_Initialization__char_ncat_22_badSource(char * data)
{
    if(CWE665_Improper_Initialization__char_ncat_22_badGlobal)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    return data;
}

#endif /* OMITBAD */
