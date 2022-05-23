#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using namespace std;

string send_message;

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("slaveTopic", 10);
      MinimalPublisher::timer_callback();
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      getline(cin,send_message);
      message.data = send_message;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    while(true){
        cout << "Enter message to send:" << endl;
        rclcpp::init(argc, argv);
        rclcpp::spin_some(std::make_shared<MinimalPublisher>());
        rclcpp::shutdown();
    }
  return 0;
}
