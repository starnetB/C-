#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;


int main(int argc,char **argv)
{
    Matrix3d rotation_matrix=Matrix3d::Identity();

    //旋转向量
    //沿着z轴旋转45度
    AngleAxisd  rotation_vector(M_PI/4,Vector3d(0,0,1));

    cout.precision(3);

    cout<<"rotation matrix =\n"<<rotation_vector.matrix()<<endl;

    //矩阵直接赋值
    rotation_matrix=rotation_vector.toRotationMatrix();

    //直接用AngleAxis可以进行坐标变换
    Vector3d v(1,0,0);
    Vector3d v_rotated=rotation_vector*v;

    cout<<"(1,0,0) after rotation (by matrix)= "<<v_rotated.transpose()<<endl;
    //或者用旋转矩阵
    v_rotated=rotation_matrix*v;

    //旋转矩阵转欧拉角
    Vector3d euler_angles=rotation_matrix.eulerAngles(2,1,0);
    cout<<"yaw pitch roll"<<euler_angles.transpose()<<endl;

    //欧氏变换使用Eigen::Isometry
    Isometry3d T=Isometry3d::Identity();  //实际上是4x4的矩阵
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1,3,4));

    cout<<"Transform matrix ="<<T.matrix()<<endl;

    //用变换矩阵进行变换
    Vector3d v_tranformed=T*v;
    cout<<"v tranfromed ="<<v_tranformed.transpose()<<endl;

    Quaterniond q=Quaterniond(rotation_vector);
    cout<<"quaternion from rotation vector ="<<q.coeffs().transpose()<<endl;

    q=Quaterniond(rotation_matrix);
    cout<<"quaternion from rotation matrix ="<<q.coeffs().transpose()<<endl;

    //直接使用四元数进行变换
    v_rotated=q*v; //注意数学上是 qvq{-1}
    cout<<"(1,0,0) after rotation =" <<v_rotated.transpose()<<endl;
    cout<<"shoule be equal to "<<(q*Quaterniond(0,1,0,0)*q.inverse()).coeffs().transpose()<<endl;
    
}
