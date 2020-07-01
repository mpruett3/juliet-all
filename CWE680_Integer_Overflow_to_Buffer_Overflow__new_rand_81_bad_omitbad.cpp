/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_bad.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
