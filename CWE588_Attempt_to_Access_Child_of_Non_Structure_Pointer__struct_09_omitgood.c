/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_09.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_09_bad()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    if(GLOBAL_CONST_TRUE)
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
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
