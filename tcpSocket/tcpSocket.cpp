#include"tcpSocket.h"

bool init_Socket()
{
	//wsa windows socket async		windows�첽�׽���
	//parm1�������socket�汾 2.2 2.1 2.0       parm ��������
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
	//1.�����յ�socket	
	//parm1:af ��ַЭ���� IPV4 IPV6
	//parm2:type ����Э������ ��ʽ�׽��� ���ݱ�
	//parm3:protocl ʹ�þ����ĳ������Э��
	socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);     
	//AF_INET����IPV4��SOC_STREAM����ʾ��������IPPROTO_TCP��ʾtcpЭ��



	return 0;
}
