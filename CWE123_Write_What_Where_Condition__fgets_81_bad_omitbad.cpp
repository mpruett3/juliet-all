/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_81_bad.cpp
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */