/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE605_Multiple_Binds_Same_Port__basic_01.c
Label Definition File: CWE605_Multiple_Binds_Same_Port__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 605 Multiple Binds to the Same Port
 * Sinks:
 *    GoodSink: Do not allow multiple binds to the same port
 *    BadSink : Set the SO_REUSEADDR socket option allowing multiple binds to the same port
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PATH_SZ PATH_MAX
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int


#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifndef OMITBAD

void CWE605_Multiple_Binds_Same_Port__basic_01_bad()
{
    {
        char data[100] = "";
        int recvResult;
        struct sockaddr_in service;
        char *replace;
        SOCKET listenSocket = INVALID_SOCKET;
        SOCKET acceptSocket = INVALID_SOCKET;
        size_t dataLen = strlen(data);
        int bOptVal = 1;
        int bOptLen = sizeof(int);

        do
        {
            listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (listenSocket == INVALID_SOCKET)
            {
                break;
            }
            /* FLAW: Set the SO_REUSEADDR socket option allowing multiple binds to the same port */
            if (setsockopt(listenSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&bOptVal, bOptLen) != 0)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = INADDR_ANY;
            service.sin_port = htons(TCP_PORT);
            if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
            {
                break;
            }
            acceptSocket = accept(listenSocket, NULL, NULL);
            if (acceptSocket == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed */
            recvResult = recv(acceptSocket, data+dataLen, (int)(100-dataLen-1), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            data[recvResult] = '\0';
            /* Eliminate CRLF */
            replace = strchr(data, '\r');
            if (replace)
            {
                *replace = '\0';
            }
            replace = strchr(data, '\n');
            if (replace)
            {
                *replace = '\0';
            }
        }
        while (0);
        if (listenSocket != INVALID_SOCKET)
        {
            CLOSE_SOCKET(listenSocket);
        }
        if (acceptSocket != INVALID_SOCKET)
        {
            CLOSE_SOCKET(acceptSocket);
        }
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char data[100] = "";

        int recvResult;
        struct sockaddr_in service;
        char *replace;
        SOCKET listenSocket = INVALID_SOCKET;
        SOCKET acceptSocket = INVALID_SOCKET;
        size_t dataLen = strlen(data);
        do
        {
            listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (listenSocket == INVALID_SOCKET)
            {
                break;
            }
            /* FIX: Do not allow multiple binds to the same port */
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = INADDR_ANY;
            service.sin_port = htons(TCP_PORT);
            if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
            {
                break;
            }
            acceptSocket = accept(listenSocket, NULL, NULL);
            if (acceptSocket == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed */
            recvResult = recv(acceptSocket, data+dataLen, (int)(100-dataLen-1), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            data[recvResult] = '\0';
            /* Eliminate CRLF */
            replace = strchr(data, '\r');
            if (replace)
            {
                *replace = '\0';
            }
            replace = strchr(data, '\n');
            if (replace)
            {
                *replace = '\0';
            }
        }
        while (0);
        if (listenSocket != INVALID_SOCKET)
        {
            CLOSE_SOCKET(listenSocket);
        }
        if (acceptSocket != INVALID_SOCKET)
        {
            CLOSE_SOCKET(acceptSocket);
        }
        printLine(data);
    }
}

void CWE605_Multiple_Binds_Same_Port__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */
