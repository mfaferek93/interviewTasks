#include <gtest/gtest.h>

#include "FlowerProcessor.h"

TEST(FlowerProcessorTest, simulateAgeing)
{
    FlowerProcessor processor;
    const auto &flowers = processor.ReadFromJson("dummy.json");
    EXPECT_FALSE(flowers.empty());
    EXPECT_EQ(100, flowers[0].getValue());
    EXPECT_EQ(200, flowers[1].getValue());
    EXPECT_EQ(300, flowers[2].getValue());

    processor.SimulateAgeing();
    EXPECT_EQ(99, flowers[0].getValue());
    EXPECT_EQ(196, flowers[1].getValue());
    EXPECT_EQ(291, flowers[2].getValue());
}

// In a normal project the parser should be separated from FlowerProcessor class and passed by a 
// pointer to the constructor. Then it would be possible to mock it in test and return prepared 
// JSON data and all magic numbers from the test above will disappear :)
