#ifndef CHATSERVER_H
#define CHATSERVER_H

#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

/*
1、组合TcpServer对象
2、创建EventLoop事件循环对象的指针
3、明确TcpServer的构造函数，输出ChatServer的构造函数
4、在ChatServer的构造函数里，注册处理连接和读写事件的回调函数
5、设置合适的服务端线程数量，借助muduo网络库，会自己分配合适的I/O线程和worker线程
*/


//聊天服务器的主类
class ChatServer
{
public:
    //初始化聊天服务器对象
    ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg);
    //启动服务
    void start();
private:
    //上报连接相关信息的回调函数
    void onConnection(const TcpConnectionPtr&);
    //上报读写事件相关信息的回调函数
    void onMessage(const TcpConnectionPtr&,
                        Buffer*,
                        Timestamp);
    TcpServer _server; //组合的muduo库，实现服务器功能的类对象
    EventLoop* _loop;  //指向事件循环对象的指针
};

#endif