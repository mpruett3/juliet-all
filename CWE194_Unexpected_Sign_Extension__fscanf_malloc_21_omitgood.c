/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_malloc_21.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-21.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The static variable below is used to drive control flow in the source function */
static int badStatic = 0;

static short badSource(short data)
{
    if(badStatic)
    {
        /* FLAW: Use a value input from the console using fscanf() */
        fscanf (stdin, "%hd", &data);
    }
    return data;
}

void CWE194_Unexpected_Sign_Extension__fscanf_malloc_21_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    badStatic = 1; /* true */
    data = badSource(data);
    /* Assume we want to allocate a relatively small buffer */
    if (data < 100)
    {
        /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
         * the conversion will cause malloc() to allocate a very large amount of data or fail */
        char * dataBuffer = (char *)malloc(data);
        if (dataBuffer == NULL) {exit(-1);}
        /* Do something with dataBuffer */
        memset(dataBuffer, 'A', data-1);
        dataBuffer[data-1] = '\0';
        printLine(dataBuffer);
        free(dataBuffer);
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
    CWE194_Unexpected_Sign_Extension__fscanf_malloc_21_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif