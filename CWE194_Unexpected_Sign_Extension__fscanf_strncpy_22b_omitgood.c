/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_strncpy_22b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE194_Unexpected_Sign_Extension__fscanf_strncpy_22_badGlobal;

short CWE194_Unexpected_Sign_Extension__fscanf_strncpy_22_badSource(short data)
{
    if(CWE194_Unexpected_Sign_Extension__fscanf_strncpy_22_badGlobal)
    {
        /* FLAW: Use a value input from the console using fscanf() */
        fscanf (stdin, "%hd", &data);
    }
    return data;
}

#endif /* OMITBAD */

