# 🤖 bot_description

This package contains the robot's URDF/XACRO description and launch files for spawning the robot model in Gazebo using ROS 2 and ROS-Gazebo bridge.

## 🧩 Package Contents

- `urdf/` – Contains the URDF or XACRO files that define the robot’s physical structure, joints, links, and sensors (camera, LiDAR).
- `launch/` – Includes launch files to:
  - Spawn the robot into Gazebo simulation.
  - Teleoperate the robot using keyboard input (`teleop_twist_keyboard`).

## 🚀 How to Use

### 1. Build the workspace
Make sure you’ve sourced ROS 2 and you're inside your workspace:

```bash
cd ~/nanibabu_ws
colcon build --packages-select bot_description
source install/setup.bash
ros2 launch bot_description spawn.launch.xml
