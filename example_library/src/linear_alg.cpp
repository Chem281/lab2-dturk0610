#include <vector>
#include <cblas.h>

/* Some maybe useful tips...
 * you can get the length of a std::vector, v using v.size()
 * you can access the data within it using v.data()
 * the cblas_dnrm2 and cblas_ddot functions require "increment" parameters - that's the stepsize
 * within your vector. it should be 1 for this case.
 */

/// @brief https://developer.apple.com/documentation/accelerate/1513248-cblas_dnrm2
/// @param a
/// @return
double calculateTwoNorm(const std::vector<double> &a)
{
    return cblas_dnrm2(a.size(), a.data(), 1);
}

/// @brief https://developer.apple.com/documentation/accelerate/1513100-cblas_ddot
/// @param x
/// @param y
/// @return
double calculateDotProduct(const std::vector<double> &x, const std::vector<double> &y)
{
    return cblas_ddot(x.size(), x.data(), 1, y.data(), 1);
}

/// @brief
/// @param x
/// @param y
/// @return
double calculateProjection(const std::vector<double> &x, const std::vector<double> &y)
{
    return calculateDotProduct(x, y) / calculateTwoNorm(y);
}