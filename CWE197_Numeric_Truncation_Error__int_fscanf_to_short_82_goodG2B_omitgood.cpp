/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_short_82_goodG2B.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */