#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <sophus/se3.hpp>

using namespace std;
using namespace Eigen;


int main(int argc,char **argv)
{
    //旋转向量转3x3
    Matrix3d R=AngleAxisd(M_PI/2,Vector3d(0,0,1)).toRotationMatrix();

    //或者四元数
    Quaterniond q(R);

    Sophus::SO3d SO3_R(R);
    Sophus::SO3d SO3_q(R);      //两种方法构造,李群内容

    //两者等价
    cout<<"SO3_R::"<<SO3_R.matrix()<<endl;
    cout<<"SO3_Q::"<<SO3_q.matrix()<<endl;

    //使用log获得李代数
    Vector3d so3=SO3_R.log();
    cout<<"so3 =  "<<so3.transpose()<<endl;
    cout<<"so3 hat = \n"<<Sophus::SO3d::hat(so3)<<endl;
    cout<<"so3 vee = \n"<<Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose()<<endl;

    Vector3d update_so3(1e-4,0,0); //假设更新两为这么多
    Sophus::SO3d SO3_update =Sophus::SO3d::exp(update_so3)*SO3_R;

    cout<<"SO3  updated = \n"<<SO3_update.matrix()<<endl;

    //对SE3d的操作也差不多
    Vector3d t(1,0,0);
    Sophus::SE3d SE3_Rt(R,t);
    Sophus::SE3d SE3_qt(q,t);


    typedef Eigen::Matrix<double,6,1> Vector6d;
    Vector6d se3=SE3_Rt.log();
    cout<<"hat :::"<<Sophus::SE3d::hat(se3)<<endl;
    cout<<"vee :::"<<Sophus::SE3d::vee(Sophus::SE3d::hat(se3))<<endl;

    Vector6d update_se3;
    update_se3.setZero();
    update_se3(0,0)=1e-4;
    Sophus::SE3d SE3_update=Sophus::SE3d::exp(update_se3)*SE3_qt;
    cout<<"update::"<<SE3_update.matrix()<<endl;
    return 0;


}
