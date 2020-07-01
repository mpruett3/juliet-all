/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_listen_socket_84_bad.cpp
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */