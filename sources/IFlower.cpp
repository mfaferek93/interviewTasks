#include "IFlower.h"

IFlower::IFlower(const std::string &name, size_t startValue, size_t ageingSpeed,
                 std::function<void(size_t &, size_t &)> simulationFunction)
    : m_name(name)
    , m_value(startValue)
    , m_ageingSpeed(ageingSpeed)
    , m_simulationFunction(simulationFunction)
{
}

IFlower::~IFlower() = default;

void IFlower::SimulateAgeing()
{
    if (m_simulationFunction)
    {
        m_simulationFunction(m_value, m_ageingSpeed);
    }
}
