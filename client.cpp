#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define ERROR(errmsg) std::cout<< __LINE__ << errmsg <<"ERROR"<<std::endl

int main()
{

    // 1.创建通信的套接字
    int fd = socket(AF_INET, SOCK_STREAM,0);
    if (fd == -1)//判断是否成功
    {
        ERROR("socket");
        exit(-1);
        /* code */
    }
    
    //连接服务器
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;             //IP地址协议
    saddr.sin_port = htons(9999);           //端口
    inet_pton(AF_INET,"172.16.10.75",&saddr.sin_addr.s_addr);
    int ret = connect(fd,(struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1)
    {
        ERROR("connect");
        /* code */
        return -1;
    }

    int numble = 0;
    //通信
    while (1)
    {
        //发送数据

        char buff[1024];
        //测试数据sprintf(buff,"hello %d\n",numble++);
        std::cout<<"send>";
        std::cin>>buff;
        send(fd,buff,strlen(buff)+1,0);


        //接收数据
        memset(buff,0 ,sizeof(buff));
        int len =recv(fd,buff, sizeof(buff),0);
        if (len > 0)
        {
            std::cout<<"server say:"<<buff<<std::endl;
            /* code */
        }
        else if(len == 0)
        {
            std::cout<<"服务器已经断开了连接"<<std::endl;
            break;
            /* code */
        }
        else
        {
            ERROR(recv);
            break;

            /* code */
        }
        sleep(1);
        
        
        /* code */
    }
    //关闭连接
    close(fd);
    return 0;
}