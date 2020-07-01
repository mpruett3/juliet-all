/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_strncpy_09.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_strncpy_09_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
    }
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_strncpy_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif