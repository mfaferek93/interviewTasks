#ifndef FLOWER_PROCESSOR
#define FLOWER_PROCESSOR

#include "IFlower.h"

#include <string>
#include <vector>

class FlowerProcessor
{
public:
    const std::vector<IFlower> &ReadFromJson(const std::string &path) noexcept;
    void SimulateAgeing() noexcept;

private:
    std::vector<IFlower> m_flowers;
};

#endif // FLOWER_PROCESSOR
