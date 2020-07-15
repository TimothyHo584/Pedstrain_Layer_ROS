pedstrain_layer in ROS
=======================
這將會解說如何在官網範例的simple layer中加入訂閱topic的功能。

-----------------------
## How to install
先把整個專案Download到您的catkin_ws/src內
```
cd ~/catkin_ws/src
git clone https://github.com/TimothyHo584/pedstrain_layer.git
```
執行`catkin_make`編譯新的package
```
cd ~/catkin_ws
catkin_make
```
**NOTE:請特別注意要確認編譯過程中吳出現Error，且在最後有看到libpedstrain_layer.so有成功生成且加入系統的lib中。**

到原本turtlebot3底下的導航包中，設定costmap_param
```
cd ~/catkin_ws/src/turtlebot3/turtlebot3_navigation/param
vim local_costmap_params.yaml
```
在`local_costmap_params.yaml`中加入以下內容：
```
plugins:
    - {name: static_map,       type: "costmap_2d::StaticLayer"}
    - {name: pedstrain_layer,  type: "pedstrain_layer_namespace::PedstrainLayer"}
    - {name: obstacles,        type: "costmap_2d::ObstacleLayer"}
    - {name: inflation_layer,  type: "costmap_2d::InflationLayer"}
```
