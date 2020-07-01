/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_goodG2B.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
