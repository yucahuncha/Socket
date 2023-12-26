#include"tcpSocket.h"

bool init_Socket()
{
	//wsa windows socket async		windows异步套接字
	//parm1：请求的socket版本 2.2 2.1 2.0       parm 传出参数
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		std::cout << "WSAStartup failed code:" << WSAGetLastError();
		return false;
	}

	return true;
}

bool close_Socket()
{
	if (0 != WSACleanup())
	{
		std::cout << "WSACleanup failed code:" << WSAGetLastError();
		return false;
	}
	return true;
}

SOCKET createServerSocket()
{
	//1.创建空的socket	
	//parm1:af 地址协议族 IPV4 IPV6
	//parm2:type 传输协议类型 流式套接字 数据报
	//parm3:protocl 使用具体的某个传输协议
	socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);     
	//AF_INET代表IPV4，SOC_STREAM，表示数据流，IPPROTO_TCP表示tcp协议



	return 0;
}
