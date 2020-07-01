/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_34.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE400_Resource_Exhaustion__fscanf_fwrite_34_unionType;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fscanf_fwrite_34_bad()
{
    int count;
    CWE400_Resource_Exhaustion__fscanf_fwrite_34_unionType myUnion;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    myUnion.unionFirst = count;
    {
        int count = myUnion.unionSecond;
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
    CWE400_Resource_Exhaustion__fscanf_fwrite_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
