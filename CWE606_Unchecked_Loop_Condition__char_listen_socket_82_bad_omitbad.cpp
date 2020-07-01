/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_listen_socket_82_bad.cpp
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
