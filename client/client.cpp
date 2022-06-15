#include "xmlrpc/XmlRpc.h"
#include <conio.h>
#include <iostream>

using namespace XmlRpc;
using namespace std;

int main()
{
	system("chcp 1251");
	int port = 20000;
	string server_addres = "localhost";
	XmlRpcValue result;
	XmlRpcValue Arg; // массив с параметрами для отправки
	string value;
	int k = 0;
	cout « "Введите числа , которые хотите сложить(напишите '0' для остановки): " « endl;
	while (true)
	{
		cin » value;
		if (value != "0")
		{
			Arg[k] = stoi(value);
			k++;
		}
		else
			break;
	}
	XmlRpcClient client(&server_addres[0], port);
	if (client.execute("127.0.0.1", Arg, result)) // процедура для обмена данными - посылаем адресс сервера и порт
	{
		cout « endl « "Результат от сервера:" « result[0];
	}
	else
	{
		cout « "Подключение не установлено, разрыв соединения" « endl;
	}
	client.close();
}