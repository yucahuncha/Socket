//#ifdef _TCPSOCKET_H_
//#define _TCPSOCKET_H_
#include<WinSock2.h>							//Windows�����ͷ�ļ�
#pragma comment(lib,"ws2_32.lib")	//���ļ�
#define err(errMsg) std::cout << "[line:"<< __LINE__ <<"]" <<errMsg <<" failed code:" << WSAGetLastError()					
//���屨��꺯��      LINE��ȡ������errmsg��ȡ����λ��
#include<iostream>
#define PORT 8888; //[0,65535    0~1024 �Ǳ����˿�]
//�������
bool init_Socket();

//�ر������
bool close_Socket();

//����������socket
SOCKET createServerSocket();




//#endif // _TCPSOCKET_H_
