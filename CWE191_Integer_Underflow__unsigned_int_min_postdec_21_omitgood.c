/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_min_postdec_21.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for unsigned int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(unsigned int data)
{
    if(badStatic)
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

void CWE191_Integer_Underflow__unsigned_int_min_postdec_21_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    badStatic = 1; /* true */
    badSink(data);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_min_postdec_21_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
