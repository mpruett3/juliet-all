/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_declare_loop_34.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} CWE127_Buffer_Underread__wchar_t_declare_loop_34_unionType;

#ifndef OMITBAD

void CWE127_Buffer_Underread__wchar_t_declare_loop_34_bad()
{
    wchar_t * data;
    CWE127_Buffer_Underread__wchar_t_declare_loop_34_unionType myUnion;
    wchar_t dataBuffer[100];
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            size_t i;
            wchar_t dest[100];
            wmemset(dest, L'C', 100-1); /* fill with 'C's */
            dest[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
            for (i = 0; i < 100; i++)
            {
                dest[i] = data[i];
            }
            /* Ensure null termination */
            dest[100-1] = L'\0';
            printWLine(dest);
        }
    }
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
    CWE127_Buffer_Underread__wchar_t_declare_loop_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif