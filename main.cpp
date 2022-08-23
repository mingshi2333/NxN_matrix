#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;
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
		
	};
}
int main()
{
	std::unordered_map<CityRecord, uint32_t> foundmap;
	std::unordered_map<std::string, CityRecord> cityMap;
	cityMap["Melbourne"] = CityRecord{ "Melbourne",500000,2.4,9.4 };


}