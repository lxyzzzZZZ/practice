//#pragma once
//
////封装一个udp的套接字接口类
////套接字创建
////绑定地址
////发送数据
////关闭套接字                                                                          
//#include <string.h>
//#include <features.h>
//#include <stdint.h>
//#include <bits/types.h>
//#include <iostream>
//#include <string>
//#include <sys/types.h>          /* see notes */
//#include <sys/socket.h>
//#include <errno.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//class udpsocket
//{
//public:
//    udpsocket()
//    {}
//	~udpsocket()
//	{}
//    //创建套接字
//    bool socket()
//    {
//      //domain地址域：af_unix,af_local 用于本地通信
//	  //              af_inet  ipv4
//      //              af_inet6 ipv6
//      //              af_packet 低等级的包接口
//      //type套接字类型：soc_stream 流式套接字  提供字节流服务 默认协议tcp
//      //                soc_dgram 数据报套接字，提供用户数据报服务 默认协议udp
//      //protocol协议：ipproto_tcp = 6  ipproto_udp = 17 （直接用宏）
//      //              0 使用套接字类型用的默认协议
//      // int socket(int domain, int type, int protocol);
//
//     _sock = socket(af_inet, sock_dgram, 0);
//      if (_sock < 0)
//      {
//        perror("socket error");
//        return false;
//      }
//      return true;
//    }
//    //为套接字绑定地址
//
//    bool bind(std::string& ip, uint16_t port)
//    {
//      // int bind(int sockfd, const struct sockaddr *addr,
//      //socklen_t addrlen);                                                           
//      //sockfd 套接字操作句柄
//      //addr：要绑定的地址信息
//      //addrlen：地址信息长度
//      //返回值：0  失败-1
//      struct sockaddr_in addr;
//      addr.sin_family = af_inet;
//      //转换为网络字节序的数据
//      //uint16_t htons(uint16_t hostshort)
//      //uint32_t htonl(uint32_t hostshort)
//      addr.sin_port = htons(port);
//      //int_addr_t inet_addr(const char* cp)
//      //将字符串点分十进制ip地址转换为网络字节序的整数ip地址
//      addr.sin_addr.s_addr = inet_addr(ip.c_str());
//      addr.sin_addr.s_addr = htonl(0x0a87a84);
//      inet_pton(af_inet, ip.c_str(), &addr);
//      socklen_t len = sizeof(struct sockaddr_in);
//      int ret = bind(_sock, (struct sockaddr*)&addr, len);
//      if (ret < 0)
//      {
//        perror("bind error");
//      }
//      return true;
//    }
//
//    bool recv(std::string& buf, sockaddr_in* _addr)
//    {
//      //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
//      //                           struct sockaddr *src_addr, socklen_t *addrlen);
//      //buf:用于保存接受的数据
//      //len：要接收的数据长度
//      //flags：默认0---阻塞接收--没有数据则阻塞   阻塞接收标志位
//      //src_addr：发送端的地址信息
//      //addrlen：输入输出型参数，用于获取地址长度
//      //返回值：实际接受的数据长度  失败：-1
//
//      char buf[1024] = { 0 };
//      struct sockaddr_in addr;
//      socklen_t len = sizeof(struct sockaddr_in);
//	  int ret = recvfrom(_sock, buf, 1024, 0, (struct sockaddr*)&addr, &len);
//	  if (ret < 0)
//	  {
//		  perror("recvfrom error");
//		  return false;
//	  }
//	  buf.assign(buf, ret);//从buf中截取指定长度的数据
//	  if (_addr != nullptr)
//	  {
//		  memcpy(_addr, &addr, len);
//	  }
//	  return true;
//	}
//	bool send(std::string& buf, struct sockaddr_in& addr)
//	{
//		//ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
//		//                      const struct sockaddr *dest_addr, socklen_t addrlen);
//		//dest_addr: 目的端地址信息
//		//addrlen： 地址信息长度
//		socklen_t len = sizeof(struct sockaddr_in);
//		int ret = sendto(_sock, buf.c_str(), buf.size(), 0,
//			(struct sockaddr*)&addr, len);
//		if (ret < 0)
//		{
//			perror("sendto error");
//			return false;
//		}
//		return true;
//	}
//
//	bool close()
//	{
//		close(_sock);
//		_sock = -1;
//		return true;
//	}
//private:
//	int _sock;
//};
//
