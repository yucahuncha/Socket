#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define ERROR(errmsg) std::cout<< __LINE__ << errmsg <<"ERROR"<<std::endl

int main()
{

    // 1.创建监听的套接字
    int fd = socket(AF_INET, SOCK_STREAM,0);
    if (fd == -1)//判断是否成功
    {
        ERROR("socket");
        exit(-1);
        /* code */
    }
    
    //绑定本地的IP端口
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;             //IP地址协议
    saddr.sin_port = htons(9999);           //端口
    saddr.sin_addr.s_addr = INADDR_ANY;     //绑定任意IP地址   = 0.0.0.0
    int ret = bind(fd, (struct sockaddr*)&saddr,sizeof(saddr));
    if (ret == -1)
    {
        ERROR("bind");
        std::cout<<"bind"<<"-1";
        /* code */
        return -1;
    }
    

    //设置监听
    ret = listen(fd,128);
    if (ret == -1)
    {
        ERROR("listen");
        /* code */
    }

    //设置阻塞，等待连接
    std::cout<<"等待连接"<<std::endl;
    struct sockaddr_in caddr;
    int addrlen = sizeof(caddr);
    int cfd = accept(fd,NULL,NULL);
    if (cfd == -1)
    {
        ERROR("accept");
        return -1;
        /* code */
    }
    
    //连接建立成功，打印客户端的IP和端口信息
    char ip[32];
    std::cout<<"客户端的IP:"<< inet_ntop(AF_INET,&caddr.sin_addr.s_addr, ip, sizeof(ip)) <<"端口:"<< ntohs(caddr.sin_port) <<std::endl;


    //通信
    while (1)
    {
        // 接受数据
        char buff[1024];
        int len =recv(cfd,buff, sizeof(buff),0);
        if (len > 0)
        {
            std::cout<<"client say:"<<buff<<std::endl;
            send(cfd,buff,len,0);
            /* code */
        }
        else if(len == 0)
        {
            std::cout<<"客户端已经断开了连接"<<std::endl;
            break;
            /* code */
        }
        else
        {
            ERROR(recv);
            break;

            /* code */
        }

        char buf[1024];
        //测试数据sprintf(buff,"hello %d\n",numble++);
        std::cout<<"send>";
        std::cin>>buf;
        send(fd,buf,strlen(buf),0);
        
        
        
        /* code */
    }
    //关闭连接
    close(fd);
    close(cfd);
    return 0;
}