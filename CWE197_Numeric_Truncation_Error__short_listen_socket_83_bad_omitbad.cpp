/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_listen_socket_83_bad.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */