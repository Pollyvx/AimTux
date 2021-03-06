#pragma once

#include <string>
#include <sys/mman.h>
#include <zconf.h>
#include <vector>
#include <map>
#include <algorithm>
#include "SDK/SDK.h"
#include "interfaces.h"

#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin)

namespace Util {
	char GetButtonString(ButtonCode_t key);
	std::string GetButtonName(ButtonCode_t buttonCode);
	ButtonCode_t GetButtonCode(std::string buttonName);
	std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace);
	void StdReplaceStr(std::string&, const std::string&, const std::string&);
	const char* PadStringRight(std::string text, size_t value);
	void ProtectAddr(void* address, int prot);
	bool Contains(const std::string &word, const std::string &sentence);
	std::string ToLower(std::string str);
	std::string ToUpper(std::string str);

	template <typename T>
	T GetValueByKey(std::vector<std::pair<int, T>> vec, int key)
	{
		for (auto i : vec)
			if (i.first == key)
				return i.second;

		return "";
	}

	template <typename K, typename V>
	K MapReverseSearchOrDefault(std::map<K, V> const* _map, V value, K fallback) 
	{
		auto _pair = std::find_if(_map->begin(), _map->end(),
				[value](const std::pair<K, V>& pair) {
					return pair.second == value;
				});

		if (_pair == _map->end())
			return fallback;

		return _pair->first;
	}

	template <typename K, typename V>
	V MapSearchOrDefault(std::map<K, V> const* _map, K key, V fallback)
	{
		auto result = _map->find(key);
		if (result == _map->end())
			return fallback;

		return result->second;
	}

}
