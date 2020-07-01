/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_22b.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sink:
 *    BadSink : Remove element from list
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

typedef struct _linkedList
{
    struct _linkedList *next;
    struct _linkedList *prev;
} linkedList;

typedef struct _badStruct
{
    linkedList list;
} badStruct;

static linkedList *linkedListPrev, *linkedListNext;

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE123_Write_What_Where_Condition__fgets_22_badGlobal;

badStruct CWE123_Write_What_Where_Condition__fgets_22_badSource(badStruct data)
{
    if(CWE123_Write_What_Where_Condition__fgets_22_badGlobal)
    {
        /* FLAW: overwrite linked list pointers with user data */
        if (fgets((char*)&data, sizeof(data), stdin) == NULL)
        {
            printLine("fgets failed!");
            exit(1);
        }
    }
    return data;
}

#endif /* OMITBAD */

