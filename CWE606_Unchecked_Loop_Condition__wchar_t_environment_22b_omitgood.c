/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_environment_22b.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: environment Read input from an environment variable
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE606_Unchecked_Loop_Condition__wchar_t_environment_22_badGlobal;

void CWE606_Unchecked_Loop_Condition__wchar_t_environment_22_badSink(wchar_t * data)
{
    if(CWE606_Unchecked_Loop_Condition__wchar_t_environment_22_badGlobal)
    {
        {
            int i, n, intVariable;
            if (swscanf(data, L"%d", &n) == 1)
            {
                /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
                intVariable = 0;
                for (i = 0; i < n; i++)
                {
                    /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                    intVariable++; /* avoid a dead/empty code block issue */
                }
                printIntLine(intVariable);
            }
        }
    }
}

#endif /* OMITBAD */

