/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__listen_socket_82_bad.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */