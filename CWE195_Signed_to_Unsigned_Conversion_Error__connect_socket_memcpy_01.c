/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memcpy_01.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITBAD

void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memcpy_01_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        int recvResult;
        struct sockaddr_in service;
        SOCKET connectSocket = INVALID_SOCKET;
        char inputBuffer[CHAR_ARRAY_SIZE];
        do
        {
            /* POTENTIAL FLAW: Read data using a connect socket */
            connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connectSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            service.sin_port = htons(TCP_PORT);
            if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            recvResult = recv(connectSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* NUL-terminate the string */
            inputBuffer[recvResult] = '\0';
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        while (0);
        if (connectSocket != INVALID_SOCKET)
        {
            CLOSE_SOCKET(connectSocket);
        }
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
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memcpy_01_good()
{
    goodG2B();
}

#endif /* OMITGOOD */
