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
```
 ### 2.To launch bot in RViz

```bash
ros2 launch bot_description display.launch.xml
```
### 3. To spawn bot in Gazebo Ignition

```bash
ros2 launch bot_descrition spawn.launch.xml
```
### 4. To control bot using keyboard
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

---

### 📁 `bot_world


# 🌍 bot_world

This package contains custom Gazebo world files and launch scripts to spawn your robot in those environments.

## 🧩 Package Contents

- `worlds/` – Custom `.sdf` or `.world` Gazebo files where your robot can be tested.
- `launch/` – Launch files to load a specific world and spawn the robot inside it.

## 🚀 How to Use

### 1. Build the package

```bash
cd ~/nanibabu_ws
colcon build --packages-select bot_world
source install/setup.bash
```
### 2. Spawn bot in our world in Gazebo
```bash
ros2 launch bot_world gz_world.launch.xml




