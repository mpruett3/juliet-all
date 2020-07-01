/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_badGlobal = 0;

int CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_badSource(int data);

void CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_badGlobal = 1; /* true */
    data = CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_badSource(data);
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_connect_socket_to_char_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
