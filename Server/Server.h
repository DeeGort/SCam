#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

public ref class Server
{
public:
	Server(int port) :
		socket(gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp)),
		remote((EndPoint^) gcnew IPEndPoint(IPAddress::Any, 0))
	{
		IPEndPoint^ ipep = gcnew IPEndPoint(IPAddress::Any, port);
		socket->Bind(ipep);
	}

	String^ recieve()
	{
		array<unsigned char>^ message = gcnew array<unsigned char>(1024);
		int recv = socket->ReceiveFrom(message, remote);

		return Encoding::ASCII->GetString(message, 0, recv);
	}

	void send(String ^ message)
	{
		array<unsigned char>^ newMessage = Encoding::ASCII->GetBytes(message); 
		socket->SendTo(newMessage, message->Length, SocketFlags::None, remote);
	}

	void send(array<unsigned char>^ message)
	{
		socket->SendTo(message, message->Length, SocketFlags::None, remote);
	}


private:
	Socket^ socket;
	EndPoint^ remote;
};