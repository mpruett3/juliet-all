/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_alloca_loop_82_bad.cpp
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
