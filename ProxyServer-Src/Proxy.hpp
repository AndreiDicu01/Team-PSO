#ifndef PROXY_H
#define PROXY_H 1
#include <string>
#include <thread>
#include<netdb.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_PENDING_CONNECTIONS 100
class Proxy
{
    private:

    std::string m_address;
    std::string m_port;
    int m_listenSocket;

    bool m_isSet;
    private:
    /*------------------------------------------------*/
    static Proxy* m_ProxyInstance;

    private:
    Proxy(std::string ip, std::string port);
    Proxy(const Proxy&);
    ~Proxy();

    int connectToRequestedWeb(std::string host,std::string port);
    public:
    /*------------------------------------------------*/

    static Proxy& createInstance(std::string ip, std::string port);
    static Proxy& getInstance();
    static void destroyInstance();

    void setListeningSocket();
    void startHandlingConnections();
    void threadHandle(int clientSocket);
   
};

#endif