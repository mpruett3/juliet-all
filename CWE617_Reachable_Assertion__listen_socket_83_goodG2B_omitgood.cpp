/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__listen_socket_83_goodG2B.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
