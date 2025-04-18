cmake_minimum_required(VERSION 3.8)
project(bot_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(laser_filter_node scripts/laser_filter_node.cpp)
ament_target_dependencies(laser_filter_node rclcpp sensor_msgs std_msgs geometry_msgs)

install(TARGETS
laser_filter_node
DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  
  set(ament_cmake_copyright_FOUND TRUE)
 
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
