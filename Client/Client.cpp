#include"../tcpSocket/tcpSocket.h"

int main()
{
	init_Socket();

	SOCKET fd = createClientSocket("127.0.0.1");
	
	
	char buf[BUFSIZ] = "大家好，我是客户端QAQ";
	//给服务器发个消息
	//if (SOCKET_ERROR == send(fd, buf, strlen(buf), 0))
	//{
		//err("send");
	//}

	while (true)
	{
		//发送消息
		std::cout << "send>";
		gets_s(buf, BUFSIZ);
		if (SOCKET_ERROR == send(fd, buf, strlen(buf), 0))
		{
			err("SEND");
		};
		if (0 < recv(fd, buf, BUFSIZ, 0))
		{
			std::cout << "recv:" << buf << std::endl;
		}
	}

	closesocket(fd);;
	close_Socket();
	std::cout << "--------end-----------" << std::endl;
	getchar();

	return 0;
}