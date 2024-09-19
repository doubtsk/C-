#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int client_end_point() // 客户端端点
{
    std::string raw_ip_address = "127.0.0.1";                                          // 设置原生地址
    unsigned short port_num = 1111;                                                    // 设置原生端口
    system::error_code ec;                                                             // 设置错误码函数
    asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec); // 绑定地址
    if (ec.value() != 0)
    {
        std::cout << "Failed tp prase the ip address.error code is " << ec.value()
                  << "Message is " << ec.message() << std::endl;
        return ec.value();
    }
    return 0;
}

int server_end_point() // 创建服务器端点
{
    unsigned short port_num = 3333;
    asio::ip::address ip_address = asio::ip::address_v6::any();
    asio::ip::tcp::endpoint ep(ip_address, port_num);
    return 0;
}

int creat_tcp_socket() // 创建tcp端口
{
    asio::io_context ios;
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    asio::ip::tcp::socket sock(ios);
    system::error_code ec;
    sock.open(protocol, ec);
    if (ec.value() != 0)
    {
        std::cout << "Failed to prase the ip address.error code is " << ec.value()
                  << "Message is " << ec.message() << std::endl;
        return ec.value();
    }
    return 0;
}

int creat_acceptor_socket() // 创建接收器端口
{
    asio::io_context ios;                                                               // 创建异步事件处理对象
    asio::ip::tcp::acceptor a(ios, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 3333)); // 创建acceptor用来绑定ipv4地址以及端口
    return 0;
}

int bind_acceptor_socket() // 绑定接收器端口
{
    unsigned short port_num = 3333;
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num); // 用来接收任何ipv4地址的连接请求
    asio::io_context ios;
    asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
}

int connect_to_end() // 连接
{
    std::string raw_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_address), port_num);
        asio::io_context ios;
        asio::ip::tcp::socket sock(ios, ep.protocol());
        sock.connect(ep);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured! Error code is" << e.code()
                  << "message is" << e.code().value();
        return e.code().value();
    }
    return 0;
}

int dns_connect_to_end() // dns连接端点
{
    std::string host = "Samplehost";
    std::string port_num = "3333";
    asio::io_context ios;
    asio::ip::tcp::resolver::query resolver_query(host, port_num, asio::ip::tcp::resolver::query::numeric_service);//将人类读懂的HTTP网站转换成数字也就是dns
    asio::ip::tcp::resolver resolver(ios);
    try
    {
        asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query);
        asio::ip::tcp::socket sock(ios);
        asio::connect(sock, it);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}
int acceptor_new_connection()
{
    const int BACKLOG_SIZE = 30;
    unsigned short port_num = 3333;
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
    asio::io_context ios;
    try
    {
        asio::ip::tcp::acceptor accpetor(ios, ep.protocol());
        accpetor.bind(ep);
        accpetor.listen(BACKLOG_SIZE);
        asio::ip::tcp::socket sock(ios);
        accpetor.accept(sock);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}