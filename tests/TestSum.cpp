#include <gtest/gtest.h>
#include "../interfaces/INode.h"
#include "../classes/Value.h"
#include "../classes/Sum.h"

TEST(SumTest, CalculateSum) {
    INode* left = new Value("3.0");
    INode* right = new Value("4.0");
    Sum sum(left, right);

    EXPECT_DOUBLE_EQ(sum.calc(), 7.0);
}

TEST(SumTest, PrintSum) {
    INode* left = new Value("3.5");
    INode* right = new Value("4.0");
    Sum sum(left, right);

    testing::internal::CaptureStdout();
    sum.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(3.5 + 4)");
}
