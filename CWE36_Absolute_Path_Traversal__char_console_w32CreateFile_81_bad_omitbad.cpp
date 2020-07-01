/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_console_w32CreateFile_81_bad.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Full path and file name
 * Sinks: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
