/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_84_goodG2B.cpp
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */