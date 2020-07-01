/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_struct_static_65a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Memory_Not_on_Heap__free_struct_static_65b_goodG2BSink(twoIntsStruct * data);

static void goodG2B()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = CWE590_Free_Memory_Not_on_Heap__free_struct_static_65b_goodG2BSink;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        twoIntsStruct * dataBuffer = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (dataBuffer == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i].intOne = 1;
                dataBuffer[i].intTwo = 1;
            }
        }
        data = dataBuffer;
    }
    funcPtr(data);
}

void CWE590_Free_Memory_Not_on_Heap__free_struct_static_65_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE590_Free_Memory_Not_on_Heap__free_struct_static_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif