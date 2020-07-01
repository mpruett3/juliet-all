/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_07.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-07.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
 * any other value so a tool should be able to identify that reads of
 * this will always give its initialized value.
 */
static int staticFive = 5;

#ifndef OMITBAD

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_07_bad()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    if(staticFive==5)
    {
        /* FLAW: Set data to point to an int */
        data = &dataBadBuffer;
    }
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoIntsStruct *)data);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
