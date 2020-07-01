/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_15.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_fwrite_15_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Set count to a random value */
        count = RAND32();
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_bad.txt";
        pFile = fopen(filename, "w+");
        if (pFile == NULL)
        {
            exit(1);
        }
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile))
            {
                exit(1);
            }
        }
        if (pFile)
        {
            fclose(pFile);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_fwrite_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
