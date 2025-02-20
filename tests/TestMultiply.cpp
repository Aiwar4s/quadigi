#include <gtest/gtest.h>
#include "../interfaces/INode.h"
#include "../classes/Value.h"
#include "../classes/Multiply.h"

TEST(MultiplyTest, CalculateMultiply) {
    INode* left = new Value("3.0");
    INode* right = new Value("4.0");
    Multiply multiply(left, right);

    EXPECT_DOUBLE_EQ(multiply.calc(), 12.0);
}

TEST(MultiplyTest, PrintMultiply) {
    INode* left = new Value("3.5");
    INode* right = new Value("4.0");
    Multiply multiply(left, right);

    testing::internal::CaptureStdout();
    multiply.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(3.5 * 4)");
}
