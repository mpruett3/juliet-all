/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__listen_socket_83_bad.cpp
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: listen_socket Overwrite linked list pointers using a listen socket (server side)
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
