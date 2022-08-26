#include <iostream>
#include <vector>
#include "bate.h"
#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;
	bool operator<(const CityRecord& other) const
	{
		return Latitude < other.Latitude;
	}//the same key need compare to store binary tree
	//and other do a compare
};

namespace std
{
	template <>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.Name);
		}
		
	};//let the structure to be a hash key  
}

int main()
{
	std::unordered_map<std::string, CityRecord> cityMap;
	cityMap["Melbourne"] = CityRecord{ "Melbourne",500000,2.4,9.4 };
	cityMap["beijing"] = CityRecord{ "beijing",500000,2.4,9.4 };
	cityMap["shanghai"] = CityRecord{ "shanghai",500000,2.4,9.4 };
	cityMap["nanjing"] = CityRecord{"nanjing",500000,2.4,9.4};
	cityMap["tianjing"] = CityRecord{ "tianjing",500000,2.4,9.4 };
	cityMap["chengdu"] = CityRecord{ "chengdu",500000,2.4,9.4 };


	cityMap.erase("shanghai");//base on key to erase a value


	const auto& cities = cityMap;
	if(cities.find("berlin")!= cities.end())
	{
		const CityRecord& berlinData = cities.at("berlin");//.at不会拆入新的元素，只会检查是否由收据
	}



	bate::timing("c++14");
	for (auto& av : cityMap)
	{
		std::cout << av.first << "\n" << av.second.Latitude << "\n";
	}
	bate::timing("c++14");

	bate::timing("c++17");
	// way to iterate the map
	for (auto& [name, city] : cityMap)
	{
		std::cout << name << "\n" << city.Latitude << "\n";
	}
	bate::timing("c++17");

	
	std::map<CityRecord, uint32_t> cityFound;
	cityFound[CityRecord{ "Melbourne",500000,2.4,9.4 }];
 

}