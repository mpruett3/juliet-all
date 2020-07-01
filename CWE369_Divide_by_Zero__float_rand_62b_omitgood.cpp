/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_62b.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

namespace CWE369_Divide_by_Zero__float_rand_62
{

#ifndef OMITBAD

void badSource(float &data)
{
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
}

#endif /* OMITBAD */


} /* close namespace */
