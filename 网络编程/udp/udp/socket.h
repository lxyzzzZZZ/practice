//#pragma once
//
////��װһ��udp���׽��ֽӿ���
////�׽��ִ���
////�󶨵�ַ
////��������
////�ر��׽���                                                                          
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
//    //�����׽���
//    bool socket()
//    {
//      //domain��ַ��af_unix,af_local ���ڱ���ͨ��
//	  //              af_inet  ipv4
//      //              af_inet6 ipv6
//      //              af_packet �͵ȼ��İ��ӿ�
//      //type�׽������ͣ�soc_stream ��ʽ�׽���  �ṩ�ֽ������� Ĭ��Э��tcp
//      //                soc_dgram ���ݱ��׽��֣��ṩ�û����ݱ����� Ĭ��Э��udp
//      //protocolЭ�飺ipproto_tcp = 6  ipproto_udp = 17 ��ֱ���ú꣩
//      //              0 ʹ���׽��������õ�Ĭ��Э��
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
//    //Ϊ�׽��ְ󶨵�ַ
//
//    bool bind(std::string& ip, uint16_t port)
//    {
//      // int bind(int sockfd, const struct sockaddr *addr,
//      //socklen_t addrlen);                                                           
//      //sockfd �׽��ֲ������
//      //addr��Ҫ�󶨵ĵ�ַ��Ϣ
//      //addrlen����ַ��Ϣ����
//      //����ֵ��0  ʧ��-1
//      struct sockaddr_in addr;
//      addr.sin_family = af_inet;
//      //ת��Ϊ�����ֽ��������
//      //uint16_t htons(uint16_t hostshort)
//      //uint32_t htonl(uint32_t hostshort)
//      addr.sin_port = htons(port);
//      //int_addr_t inet_addr(const char* cp)
//      //���ַ������ʮ����ip��ַת��Ϊ�����ֽ��������ip��ַ
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
//      //buf:���ڱ�����ܵ�����
//      //len��Ҫ���յ����ݳ���
//      //flags��Ĭ��0---��������--û������������   �������ձ�־λ
//      //src_addr�����Ͷ˵ĵ�ַ��Ϣ
//      //addrlen����������Ͳ��������ڻ�ȡ��ַ����
//      //����ֵ��ʵ�ʽ��ܵ����ݳ���  ʧ�ܣ�-1
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
//	  buf.assign(buf, ret);//��buf�н�ȡָ�����ȵ�����
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
//		//dest_addr: Ŀ�Ķ˵�ַ��Ϣ
//		//addrlen�� ��ַ��Ϣ����
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
