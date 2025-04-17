
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

class LaserFilter : public rclcpp::Node
{
public:
    LaserFilter()
        : Node("laser_filter_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10,
            std::bind(&LaserFilter::laser_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/filtered_scan", 10);
    }

private:
    void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        auto filtered = *msg;

        size_t total_ranges = filtered.ranges.size();
        double angle_increment = filtered.angle_increment;
        double start_angle = filtered.angle_min;

      
        double lower_limit = 0.0;
        double upper_limit = 2.0 * M_PI / 3.0;  

        for (size_t i = 0; i < total_ranges; ++i)
        {
            double current_angle = start_angle + i * angle_increment;
            if (current_angle < lower_limit || current_angle > upper_limit)
            {
                filtered.ranges[i] = std::numeric_limits<float>::infinity();
            }
        }

        publisher_->publish(filtered);
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaserFilter>());
    rclcpp::shutdown();
    return 0;
}
