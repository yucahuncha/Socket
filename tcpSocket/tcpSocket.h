//#ifdef _TCPSOCKET_H_
//#define _TCPSOCKET_H_
#include<WinSock2.h>							//Windows网络库头文件
#pragma comment(lib,"ws2_32.lib")	//库文件
#define err(errMsg) std::cout << "[line:"<< __LINE__ <<"]" <<errMsg <<" failed code:" << WSAGetLastError()<<std::endl;			
//定义报错宏函数      LINE获取行数，errmsg获取报错位置
#include<iostream>
#define PORT 8888//[0,65535    0~1024 是保留端口]
//打开网络库
bool init_Socket();

//关闭网络库
bool close_Socket();

//创建服务器socket
SOCKET createServerSocket();

//创建客户端socket
SOCKET createClientSocket(const char* IP);


//#endif // _TCPSOCKET_H_
