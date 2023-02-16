#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <tchar.h>
#include <string>
#include <Windows.h>
#include <locale.h>  
#include <conio.h>
#include "main_menu.h"
#include "screenn.h"
#include "color.h"
#include <vector>;
#include "auth.h"
#include "SkCR.h"
#include <io.h>
#include <fcntl.h>
#include "trigger.h"

#pragma comment(lib, "gdiplus.lib")

int main();

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

std::string name = (std::string)skCrypt("");
std::string ownerid = (std::string)skCrypt("");
std::string secret = (std::string)skCrypt("");
std::string version = (std::string)skCrypt("1.0");
using namespace KeyAuth;
std::string url = (std::string)skCrypt("https://keyauth.win/api/1.2/");
api KeyAuthApp(name, ownerid, secret, version, url);


std::string key;


int main() {
	SetConsoleTitleA(skCrypt("Netflix"));
	std::cout << skCrypt("\n\niniciando...");
	system("cls");
	KeyAuthApp.init();
	std::cout << skCrypt("\nKey: ");
	std::cin >> key;
	KeyAuthApp.license(key);


	if (!KeyAuthApp.data.success)
	{
		system("cls");
		if (KeyAuthApp.data.message == "The user is banned") {
			printf(skCrypt("\033[0;31m-> você está banido e não irá poder mais usar nosso programa.\033[0;0m"));
		}

		if (KeyAuthApp.data.message == "Key Not Found.") {
			printf(skCrypt("\033[0;31m->A key que você insiriu está inválida.\033[0;0m"));
		}

		if (KeyAuthApp.data.message == "No active subscriptions found.") {
			printf(skCrypt("\033[0;31m->Sua subscrição expirou.\033[0;0m"));
		}
		Sleep(1500);
		exit(0);
	}
	else {
		system("cls");
		std::cout << skCrypt("\033[0;36m\n Nome do produto: \033[0;0m");
		std::string subs;
		for (std::string value : KeyAuthApp.data.subscriptions)subs += value + " ";
		std::cout << subs;
		std::cout << skCrypt("\n\033[0;36m Data do fim da Subscrição: \033[0;0m") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
		KeyAuthApp.check();
		Sleep(4000);
		system("cls");
		trigger main_;
		main_.main_trigger();
	}

}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), skCrypt("%d/%m/%y ás %H horas e %M minutos "), &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); 

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}