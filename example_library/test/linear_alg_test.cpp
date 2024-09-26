#include <gtest/gtest.h>
#include <linear_alg.h>
#include <vector>
#include <cmath>

TEST(TwoNormTests, BasicAssertions)
{
  std::vector<double> v1 = {1.0, 0.0, 0.0};
  EXPECT_EQ(calculateTwoNorm(v1), 1.0);
}

TEST(TwoNormTests, ZeroNorm)
{
  std::vector<double> v0 = {0, 0, 0};
  EXPECT_EQ(calculateTwoNorm(v0), 0);
}

TEST(TwoNormTests, Sqrt2)
{
  std::vector<double> vsqrt2 = {1.0, 1.0};
  EXPECT_EQ(calculateTwoNorm(vsqrt2), sqrt(2));
}

TEST(DotProductTests, ParallelEqualLength)
{
  std::vector<double> v1 = {1.0, 1.0, 1.0};
  std::vector<double> v2 = {-1.0, -1.0, -1.0};
  EXPECT_EQ(calculateDotProduct(v1, v2), -3.0);
}

TEST(DotProductTests, Orthogonal)
{
  std::vector<double> v1 = {1.0, 0.0, 0.0};
  std::vector<double> v2 = {0.0, 1.0, 0.0};
  EXPECT_EQ(calculateDotProduct(v1, v2), 0.0);
}

TEST(DotProductTests, Angle45)
{
  std::vector<double> v1 = {1.0, 1.0, 0.0};
  std::vector<double> v2 = {0.0, sqrt(2), 0.0};
  EXPECT_EQ(calculateDotProduct(v1, v2), sqrt(2));
}

TEST(ProjectionTests, ParallelEqualLength)
{
  std::vector<double> v1 = {1.0, 1.0, 1.0};
  std::vector<double> v2 = {-1.0, -1.0, -1.0};
  EXPECT_EQ(calculateProjection(v1, v2), -3.0 / sqrt(3));
}

TEST(ProjectionTests, Orthogonal)
{
  std::vector<double> v1 = {1.0, 0.0, 1.0};
  std::vector<double> v2 = {0.0, -1.0, 0.0};
  EXPECT_EQ(calculateProjection(v1, v2), 0.0);
}

TEST(ProjectionTests, Angle45)
{
  std::vector<double> v1 = {1.0, 1.0, 0.0};
  std::vector<double> v2 = {0.0, sqrt(2), 0.0};
  EXPECT_EQ(calculateProjection(v1, v2), 1.0);
}

TEST(ProjectionTests, DoubleLen)
{
  std::vector<double> v1 = {2.0, 0.0, 0.0};
  std::vector<double> v2 = {4.0, 0.0, 0.0};
  EXPECT_EQ(calculateProjection(v1, v2), 2.0);
}

TEST(ProjectionTests, DoubleLenRev)
{
  std::vector<double> v1 = {2.0, 0.0, 0.0};
  std::vector<double> v2 = {4.0, 0.0, 0.0};
  EXPECT_EQ(calculateProjection(v2, v1), 4.0);
}