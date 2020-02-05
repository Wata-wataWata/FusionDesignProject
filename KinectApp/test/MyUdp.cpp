#include "MyUdp.h"
#include <iostream>
#include <string>

MyUdp::MyUdp(const std::string& address, int port)
    : addr(),
    sock()
{   
    /*
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 1) {
        std::cout << "[!] WSAStartup Failed." << std::endl;
        return;
    };
    */

    int err = WSAStartup(MAKEWORD(2, 0), &wsaData);
    if (err != 0) {
        switch (err) {
        case WSASYSNOTREADY:
            printf("WSASYSNOTREADY\n");
            break;
        case WSAVERNOTSUPPORTED:
            printf("WSAVERNOTSUPPORTED\n");
            break;
        case WSAEINPROGRESS:
            printf("WSAEINPROGRESS\n");
            break;
        case WSAEPROCLIM:
            printf("WSAEPROCLIM\n");
            break;
        case WSAEFAULT:
            printf("WSAEFAULT\n");
            break;
        }
        return;
    }
    else {
        std::cout << "[-] WSAStartup succeed." << std::endl;
    }

    // ソケットを作る
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket(AF_INET, SOCK_DGRAM, 0) failed");
    }

    // アドレスの種類
    addr.sin_family = AF_INET;

    // ポートを取得
    addr.sin_port = htons(port);

    // 文字列をIPアドレスを変換
    if (inet_pton(addr.sin_family, address.c_str(), &addr.sin_addr) != 1) {
        perror("[!] inet_pton() failed.");
    }


    std::cout << "[-] MyUdp Set." << std::endl;
    return;

}

MyUdp::~MyUdp()
{
}

void MyUdp::SendHello() {
    int err = sendto(sock, "HELLO", 5, 0, (struct sockaddr*) & addr, sizeof(addr));
    if(err == -1){
        perror("[!] sentto() failed.");
    }
}

bool MyUdp::SendString(const std::string data) {
    sendto(sock, data.c_str(), data.length(), 0, (sockaddr*)&addr, sizeof(addr));
    return TRUE;
}