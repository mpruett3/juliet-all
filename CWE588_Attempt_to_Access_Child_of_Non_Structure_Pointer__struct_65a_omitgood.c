/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_65a.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_65b_badSink(void * data);

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_65_bad()
{
    void * data;
    /* define a function pointer */
    void (*funcPtr) (void *) = CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_65b_badSink;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FLAW: Set data to point to an int */
    data = &dataBadBuffer;
    /* use the function pointer */
    funcPtr(data);
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
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
