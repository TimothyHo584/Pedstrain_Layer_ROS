#ifndef PEDSTRAIN_LAYER_H_
#define PEDSTRAIN_LAYER_H_
#include <ros/ros.h>
#include <costmap_2d/layer.h>
#include <costmap_2d/layered_costmap.h>
#include <costmap_2d/GenericPluginConfig.h>
#include <dynamic_reconfigure/server.h>
#include <std_msgs/Float32.h>

namespace pedstrain_layer_namespace
{
 
  class PedstrainLayer : public costmap_2d::Layer
  {
    public:
      PedstrainLayer();
    
      virtual void onInitialize();
      virtual void updateBounds(double origin_x, double origin_y, double origin_yaw, double* min_x, double* min_y, double* max_x,
                                double* max_y);
      virtual void updateCosts(costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j);
    
    private:
      void reconfigureCB(costmap_2d::GenericPluginConfig &config, uint32_t level);
      //declare subscriber callback function
      void pedestrainCB(const std_msgs::Float32::ConstPtr& msg);
    
      double mark_x_, mark_y_;
      //add value to keep subscribe data
      float point1;
      //add pedestrain_sub_ to keep Subscriber structure
      ros::Subscriber pedestrain_sub_;
      dynamic_reconfigure::Server<costmap_2d::GenericPluginConfig> *dsrv_;
  };
}
#endif

