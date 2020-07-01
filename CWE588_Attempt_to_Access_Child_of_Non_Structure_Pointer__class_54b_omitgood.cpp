/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_54b.cpp
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class.label.xml
Template File: sources-sink-54b.tmpl.cpp
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints class
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void badSink_c(void * data);

void badSink_b(void * data)
{
    badSink_c(data);
}

#endif /* OMITBAD */


} /* close namespace */