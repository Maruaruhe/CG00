#pragma once
#include <string>
#include <format>
#include <d3d12.h>

void LogText(const std::string& message);

std::wstring ConvertString(const std::string& str);
std::string ConvertString(const std::wstring& str);
