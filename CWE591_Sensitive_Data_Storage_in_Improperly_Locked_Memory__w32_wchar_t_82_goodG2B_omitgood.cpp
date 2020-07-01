/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_82_goodG2B.cpp
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
