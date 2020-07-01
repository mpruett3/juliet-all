/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__listen_socket_fwrite_82_bad.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */