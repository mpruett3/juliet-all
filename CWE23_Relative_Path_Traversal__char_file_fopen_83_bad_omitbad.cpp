/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_fopen_83_bad.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sinks: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */