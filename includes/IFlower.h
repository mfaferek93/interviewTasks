#ifndef IFLOWER
#define IFLOWER

#include <cstddef>    // size_t
#include <functional> // function
#include <string>

class IFlower
{
public:
    explicit IFlower(const std::string &name, size_t startValue, size_t ageingSpeed,
                     std::function<void(size_t &, size_t &)> simulationFunction);
    virtual ~IFlower();

    size_t getValue() const noexcept { return m_value; }
    void SimulateAgeing();

private:
    std::string m_name;
    size_t m_value;
    size_t m_ageingSpeed;
    std::function<void(size_t &, size_t &)> m_simulationFunction;
};

#endif // IFLOWER