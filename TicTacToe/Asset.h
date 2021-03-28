#pragma once
#include <string>
#include <map>
#include <exception>

template <typename T>
class Asset
{
public:

	void load(const std::string& filename, const std::string& name);
	const T& get(const std::string& name) const;
	bool contain(const std::string& name) const;
	typename std::map<std::string, T>::const_iterator getIterator(const std::string& name) const;

private:

	std::map<std::string, T> data;
};




template<typename T>
void Asset<T>::load(const std::string& filename, const std::string& name)
{
	if (contain(name))
		return;
	T obj;
	if (obj.loadFromFile(filename);)
		data[name] = obj;
}

template<typename T>
const T& Asset<T>::get(const std::string& name) const
{
	return map.at(name);
}

template<typename T>
bool Asset<T>::contain(const std::string& name) const
{
	return data.find(name) != data.end();
}

template<typename T>
typename std::map<std::string, T>::const_iterator Asset<T>::getIterator(const std::string& name) const
{
	decltype(data)::const_iterator it = data.find(name);
	if (name == data.end())
		throw std::out_of_range("no element \"" + name.c_str() + "\" in asset!\n");
	return it;
}
