/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_51b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-51b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_51
{

#ifndef OMITBAD

void badSink(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */


} /* close namespace */