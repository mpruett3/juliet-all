/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_82_bad.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */