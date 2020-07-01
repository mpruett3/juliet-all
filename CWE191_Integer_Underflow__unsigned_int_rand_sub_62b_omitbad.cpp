/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_sub_62b.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__unsigned_int_rand_sub_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(unsigned int &data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(unsigned int &data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
}

#endif /* OMITGOOD */

} /* close namespace */