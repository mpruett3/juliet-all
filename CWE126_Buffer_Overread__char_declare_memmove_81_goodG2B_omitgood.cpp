/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memmove_81_goodG2B.cpp
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
