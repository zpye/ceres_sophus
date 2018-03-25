#ifndef SOPHUS_LOCAL_PARAMETERIZATION_SE3_HPP
#define SOPHUS_LOCAL_PARAMETERIZATION_SE3_HPP

#include <ceres/local_parameterization.h>
#include <sophus/se3.hpp>

namespace Sophus {
    struct SE3Plus {
        template<typename T>
        bool operator()(const T* x, const T* delta, T* x_plus_delta) const {
            Eigen::Map<SE3<T> const> const T_x(x);
            Eigen::Map<Vector6<T> const> const T_delta(delta);
            Eigen::Map<SE3<T>> T_x_plus_delta(x_plus_delta);
            T_x_plus_delta = SE3<T>::exp(T_delta) * T_x;
            return true;
        }
    };

    ceres::LocalParameterization* GetLocalParamsSE3()
    {
        ceres::LocalParameterization* LocalParamSE3 =
        new ceres::AutoDiffLocalParameterization<Sophus::SE3Plus,
        Sophus::SE3d::num_parameters, Sophus::SE3d::DoF>;
        
        return LocalParamSE3;
    }
}  // namespace Sophus

#endif // SOPHUS_LOCAL_PARAMETERIZATION_SE3_HPP
