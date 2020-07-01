/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_66a.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_66b_badSink(void * dataArray[]);

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_66_bad()
{
    void * data;
    void * dataArray[5];
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FLAW: Set data to point to an int */
    data = &dataBadBuffer;
    /* put data in array */
    dataArray[2] = data;
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_66b_badSink(dataArray);
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
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
