#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
using namespace boost;
int client_end_point()
{
    std::string raw_ip_address = "127.45.2.1";
    unsigned short port_num = 3333;
    system::error_code ec;
    asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);
    if (ec.value() != 0)
    {
        std::cout << "Failed to prase the ip address.error code is" << ec.value() << "Message is" << ec.message() << std::endl;
        return ec.value();
    }

    asio::ip::tcp::endpoint ep(ip_address, port_num);
    return 0;
}

int server_end_point()
{
    unsigned short port_num = 3333;
    asio::ip::address ip_address = asio::ip::address_v6::any();
    asio::ip::tcp::endpoint ep(ip_address, port_num);
    return 0;
}

int creat_tcp_socket()
{
    asio::io_context ioc;
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    asio::ip::tcp::socket sock(ioc);
    system::error_code ec;
    sock.open(protocol, ec);
    if (ec.value() != 0)
    {
        std::cout << "Failed to prase the ip address.error code is" << ec.value()
                  << "Message is" << ec.message() << std::endl;
        return ec.value();
    }

    return 0;
}

int creat_acceptor_socket()
{
    asio::io_context ios;
    /*
    asio::ip::tcp::acceptor acceptor(ios);
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    system::error_code ec;
    acceptor.open(protocol, ec);
    if (ec.value() != 0)
    {
        std::cout << "Failed to prase the ip address.error code is"
                  << ec.value() << "Message is" << ec.message() << std::endl;
        return ec.value();
    }
    */
    asio::ip::tcp::acceptor a(ios, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 3333));
    return 0;
}

int bind_acceptor_socket()
{
    unsigned short port_num = 3333;
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
    asio::io_context ios;
    asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
    system::error_code ec;
    acceptor.bind(ep, ec);
    if (ec.value() != 0)
    {
        std::cout << "Failed to prase the ip address.error code is"
                  << ec.value() << "Message is" << ec.message() << std::endl;
        return ec.value();
    }
    return 0;
}

int connect_to_end()
{
    std::string raw_ip_address = "192.168.12.3";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ios;
        asio::ip::tcp::socket sock(ios, ep.protocol());
        sock.connect(ep);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}

int dns_connect_to_end()
{
    std::string host = "Samplehost";
    std::string port_num = "3333";
    asio::io_context ios;
    asio::ip::tcp::resolver::query resolver_query(host, port_num, asio::ip::tcp::resolver::query::numeric_service);
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
        asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
        acceptor.bind(ep);
        acceptor.listen(BACKLOG_SIZE);
        asio::ip::tcp::socket sock(ios);
        acceptor.accept(sock);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}
/*
以下均为构造buffer
void use_const_buffer()
{
    std::string buf = "hello world";
    asio::const_buffer asio_buf(buf.c_str(), buf.length());
    std::vector<asio::const_buffer> buffers_sequence;
    buffers_sequence.push_back(asio_buf);
}

void use_buffer_str()
{
    asio::const_buffers_1 output_buf = asio::buffer("hello world");
}
*/
void use_buffer_arry()
{
    const size_t BUF_SIZE_BYTES = 20;
    std::unique_ptr<char[]> buf(new char[BUF_SIZE_BYTES]);
    auto input_buf = asio::buffer(static_cast<void *>(buf.get()), BUF_SIZE_BYTES);
}

void write_to_socket(asio::ip::tcp::socket &sock)
{
    std::string buf = "hello world";
    std::size_t total_bytes_written = 0;
    // 循环发送
    while (total_bytes_written != buf.length())
    {
        total_bytes_written += sock.write_some(asio::buffer(buf.c_str() + total_bytes_written,
                                                            buf.length() - total_bytes_written));
    }
}

int send_data_by_write_send()
{
    std::string raw_ip_address = "12.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        std::string buf = "hello world";
        int sendlength = sock.send(asio::buffer(buf.c_str(), buf.length()));
        if (sendlength <= 0)
        {
            return 0;
        }
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}

int send_data_by_write_some()
{
    std::string raw_ip_address = "12.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        write_to_socket(sock);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}

int send_data_by_write()
{
    std::string raw_ip_address = "12.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        std::string buf = "hello world";
        int send_length = asio::write(sock, asio::buffer(buf.c_str(), buf.length()));
        if (send_length <= 0)
        {
            return 0;
        }
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
    return 0;
}

std::string read_from_socket(asio::ip::tcp::socket &sock)
{
    const unsigned char MESSAGE_SIZE = 7;
    char buf[MESSAGE_SIZE];
    std::size_t total_bytes_read = 0;
    while (total_bytes_read != MESSAGE_SIZE)
    {
        total_bytes_read += sock.read_some(asio::buffer(buf + total_bytes_read, MESSAGE_SIZE - total_bytes_read));
    }
    return std::string(buf, total_bytes_read);
}

int read_data_by_read_some()
{
    std::string raw_ip_address = "127.1.01.";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        read_from_socket(sock);
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
}

int read_data_by_receive()
{
    std::string raw_ip_address = "127.1.01.";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        const unsigned char BUFFER_SIZE = 7;
        char buffer_receive[BUFFER_SIZE];
        int receive_length = sock.receive(asio::buffer(buffer_receive, BUFFER_SIZE));
        if (receive_length <= 0)
        {
            return 0;
        }
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
}

int read_data_by_read()
{
    std::string raw_ip_address = "127.1.01.";
    unsigned short port_num = 3333;
    try
    {
        asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
        asio::io_context ioc;
        asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        const unsigned char BUFFER_SIZE = 7;
        char buffer_receive[BUFFER_SIZE];
        int receive_length = asio::read(sock, asio::buffer(buffer_receive, BUFFER_SIZE));
        if (receive_length <= 0)
        {
            return 0;
        }
    }
    catch (system::system_error &e)
    {
        std::cout << "Error occured!Error code is" << e.code()
                  << "message is " << e.what() << std::endl;

        return e.code().value();
    }
}