/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_68b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

extern int CWE400_Resource_Exhaustion__rand_fwrite_68_badData;
extern int CWE400_Resource_Exhaustion__rand_fwrite_68_goodG2BData;
extern int CWE400_Resource_Exhaustion__rand_fwrite_68_goodB2GData;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_fwrite_68b_badSink()
{
    int count = CWE400_Resource_Exhaustion__rand_fwrite_68_badData;
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

#endif /* OMITBAD */
