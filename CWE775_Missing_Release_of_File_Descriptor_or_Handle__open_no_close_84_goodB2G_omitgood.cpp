/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_goodB2G.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
