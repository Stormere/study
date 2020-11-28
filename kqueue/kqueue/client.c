//
//  main.c
//  socket_client
//
//  Created by 郜俊博 on 2017/9/29.
//  Copyright © 2017年 郜俊博. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int myconnect() {
    int client_sockfd;
    ssize_t len;
    struct sockaddr_in remote_addr; //服务器端网络地址结构
    char buf[BUFSIZ];  //数据传送的缓冲
    memset(&remote_addr,0,sizeof(remote_addr)); //数据初始-清零
    remote_addr.sin_family=AF_INET; //设置为IP通信
    remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//服务器IP地址
    remote_addr.sin_port=htons(4312); //服务器端口号
    
    /*创建客户端套接字--IPv4协议，面向连接通信，TCP协议*/
    if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket");
        return 1;
    }
    int id = connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr));
    //将套接字绑定到服务器的网络地址
    if(id<0)
    {
        perror("connect");
        return 1;
    }
    printf("client_sockfd----%d\n",client_sockfd);
    printf("id----%d\n",id);
    printf("connected to server!\n");
    //len=recv(client_sockfd,buf,BUFSIZ,0);//接收服务器端信息
    
    for (int i=0; i<1000; i++) {
        buf[0]= (char)i;
        len = send(client_sockfd, buf, BUFSIZ, 0);

    }

    printf("%s",buf); //打印服务器端信息
    close(client_sockfd);//关闭套接
    return 0;
}
