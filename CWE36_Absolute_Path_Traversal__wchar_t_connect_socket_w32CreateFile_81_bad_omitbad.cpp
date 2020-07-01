/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_connect_socket_w32CreateFile_81_bad.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Full path and file name
 * Sinks: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
