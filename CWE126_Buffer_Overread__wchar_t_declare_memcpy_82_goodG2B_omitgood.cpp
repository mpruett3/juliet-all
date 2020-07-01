/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_declare_memcpy_82_goodG2B.cpp
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
