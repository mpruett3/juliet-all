/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_printf_42.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static char * goodG2BSource(char * data)
{
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    return data;
}

static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = goodG2BSource(data);
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static char * goodB2GSource(char * data)
{
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    return data;
}

static void goodB2G()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = goodB2GSource(data);
    /* FIX: Specify the format disallowing a format string vulnerability */
    printf("%s\n", data);
}

void CWE134_Uncontrolled_Format_String__char_file_printf_42_good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_file_printf_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif