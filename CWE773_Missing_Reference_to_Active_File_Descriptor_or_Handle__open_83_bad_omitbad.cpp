/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_bad.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file descriptor using open()
 * Sinks:
 *    GoodSink: Close the file before reusing the file descriptor
 *    BadSink : Reassign the file descriptor before closing the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
