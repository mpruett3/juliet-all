/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_snprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_environment_snprintf_67_structType
{
    char * structFirst;
} CWE134_Uncontrolled_Format_String__char_environment_snprintf_67_structType;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_environment_snprintf_67b_badSink(CWE134_Uncontrolled_Format_String__char_environment_snprintf_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITBAD */
