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
	while (true)
	{
		if (0 < recv(clifd, buf, BUFSIZ, 0))
		{
			std::cout << "recv:" << buf << std::endl;
		}
		//发送消息
		std::cout << "send>";
		gets_s(buf, BUFSIZ);
		if (SOCKET_ERROR == send(clifd, buf, strlen(buf), 0))
		{
			err("SEND");
		};
	}
	closesocket(clifd);
	closesocket(serfd);


	close_Socket();				//关闭socket连接

	std::cout << "--------end----------" << std::endl;

	getchar();
	return 0;
}