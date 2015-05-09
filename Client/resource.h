#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

public ref class Client
{
public:
	Client(String^ ip, int port) :
		socket(gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp)),
		remote(gcnew IPEndPoint(IPAddress::Parse(ip), port))
	{
		if ((int)socket->GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout) < 5000)
		{
			socket->SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, 5000);
		}
	}


	void send(String ^ message)
	{
		array<unsigned char>^ newMessage = Encoding::ASCII->GetBytes(message);
		socket->SendTo(newMessage, message->Length, SocketFlags::None, remote);
		//		socket->SendTo(newMessage, recv, remote);
	}

	String^ recieve()
	{
		array<unsigned char>^ message = gcnew array<unsigned char>(1024);
		recv = socket->ReceiveFrom(message, remote);

		/*	Console::WriteLine("[{0}] {1}",
		remote->ToString(), Encoding::ASCII->GetString(message, 0, recv));*/

		return Encoding::ASCII->GetString(message, 0, recv);
	}


private:
	Socket^ socket;
	EndPoint^ remote;
	int recv;
};