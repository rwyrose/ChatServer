# ChatServer
基于muduo网络库实现的集群聊天服务器和客户端代码，使用nginx实现了tcp负载均衡，以及基于redis的消息队列，实现了跨服务器通信

编译方式
cd build
rm -rf *
cmake ..
make

需要实现nginx的tcp负载均衡
