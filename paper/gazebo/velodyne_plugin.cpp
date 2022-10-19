#ifndef _VELODYNE_PLUGIN_HH_
#define _VELODYNE_PLUGIN_HH_

#include <gazebo-11/gazebo/gazebo.hh>
#include <gazebo-11/gazebo/physics/physics.hh>

namespace gazebo
{
    class VelodynePlugin:public ModelPlugin{
    public:
        VelodynePlugin(){}

        virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
        {
            //Just output  a message for now
            std::cerr<<"\nThe velodyne plugin is attach to model["<<_model->GetName()
        }
    }


}

#endif