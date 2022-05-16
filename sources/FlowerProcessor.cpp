#include "FlowerProcessor.h"

#include <unordered_map>

std::unordered_map<std::string, std::function<void(size_t &, size_t &)>> simulationFunctions{
    {"flowerType1", [](size_t &value, size_t &ageingSpeed)
     { value -= ageingSpeed; }},
    {"flowerType2", [](size_t &value, size_t &ageingSpeed)
     { value -= 2 * ageingSpeed; }},
    {"flowerType3", [](size_t &value, size_t &ageingSpeed)
     { value -= 3 * ageingSpeed; }}};

const std::vector<IFlower> &FlowerProcessor::ReadFromJson(const std::string & /*path*/) noexcept
{
    m_flowers.emplace_back("flowerType1", 100, 1, simulationFunctions.at("flowerType1"));
    m_flowers.emplace_back("flowerType2", 200, 2, simulationFunctions.at("flowerType2"));
    m_flowers.emplace_back("flowerType3", 300, 3, simulationFunctions.at("flowerType3"));

    return m_flowers;
}

void FlowerProcessor::SimulateAgeing() noexcept
{
    for (auto &flower : m_flowers)
    {
        flower.SimulateAgeing();
    }
}
