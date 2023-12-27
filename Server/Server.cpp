#include"../tcpSocket/tcpSocket.h"


int main()
{
	init_Socket();					//打开socket连接

	SOCKET serfd = createServerSocket();
	std::cout << "wait client connecnt......" << std::endl;
	//如果有客户端请求连接，那么
	SOCKET clifd =	accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err("accept");
	}


	//可以和客户端进行通信了
	char	buf[BUFSIZ] = { 0 };
	//recv从指定的socket接受信息

	if (0 < recv(clifd, buf, BUFSIZ, 0))
	{
		std::cout << "recv:" << buf << std::endl;
	}


	//closesocket(clifd);
	//closesocket(serfd);


	close_Socket();				//关闭socket连接
	getchar();
	return 0;
}