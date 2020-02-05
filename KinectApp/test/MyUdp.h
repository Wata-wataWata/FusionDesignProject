#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <wchar.h>
#include <string>

class MyUdp
{
public:
    MyUdp(const std::string& address, int port);
    ~MyUdp();

    void SendHello();
    bool SendString(const std::string data);

private:
    WSAData wsaData;

    SOCKET sock;
    sockaddr_in addr;



};
