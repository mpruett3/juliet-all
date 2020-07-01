/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_06.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_fwrite_06_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Set count to a random value */
        count = RAND32();
    }
    if(STATIC_CONST_FIVE==5)
    {
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
    CWE400_Resource_Exhaustion__rand_fwrite_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
