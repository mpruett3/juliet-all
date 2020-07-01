/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_82_goodB2G.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
