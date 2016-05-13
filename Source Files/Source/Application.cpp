#include <iostream>
#include "..\Headers\Application.hpp"



bool Application::Init()
{
	return true;
}

void Application::HandleEvents()
{

}

void Application::Update(int deltaTime)
{
	std::cout << deltaTime << std::endl;
}

Application::Application()
{
}


Application::~Application()
{
}
