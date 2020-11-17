#include <gazebo/gazebo.hh>

namespace gazebo
{

  class WorldPluginMyRobot : public WorldPludin
   {
   public: WorldPluginMyRobot() : WorldPlugin()
	    {
	      printf("Hello world!\n");
	    }
     
   public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
	    {
	    }

    };
    GZ_REGISTER_WORLD_PLUGIN(WorldPluginMyRobot)
	
}

