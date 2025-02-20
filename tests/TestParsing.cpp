#include <gtest/gtest.h>
#include "../interfaces/INode.h"
#include "../classes/ExpressionParser.h"

TEST(ExpressionParserTest, ParseExpressionPrint) {
    ExpressionParser parser;
    INode* root = parser.parse("4+5*2");
    testing::internal::CaptureStdout();
    root->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(4 + (5 * 2))");
}

TEST(ExpressionParserTest, ParseExpressionCalc) {
    ExpressionParser parser;
    INode* root = parser.parse("4+5*2");
    EXPECT_DOUBLE_EQ(root->calc(), 14.0);
}