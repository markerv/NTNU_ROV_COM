#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include <functional>
#include <memory>

#include "../../../../lib/janusxsdm/janusxsdm.cpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using namespace std;

string JANUSPATH = "../lib/janus-c-3.0.5/bin/";
string SDMPATH = "../lib/sdmsh/";

int JANUS_RX_PORT = 9977;
int JANUS_TX_PORT = 9962;

string received_data;

janusxsdm::connection modem("192.168.0.189",JANUSPATH,SDMPATH, JANUS_RX_PORT,JANUS_TX_PORT);


class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("masterTopic", 10);
      MinimalPublisher::timer_callback();
    }

  private:
    void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = received_data;
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int node_run(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin_some(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}

int janus_rx(int timeOut_interval){                          //Reception from JANUS and SDMSH
    std::cout << "Listening for signal.. " << "\n";
    std::chrono::duration<double> t;
    t = std::chrono::duration<double> {timeOut_interval};       //Setting the timeout interval to seconds in variable t
    string response;
    modem.listen(response, t);
    received_data = response;
    node_run(0,0);
    return 0;
}

int main(){
    modem.sdmconfDialogue();
    std::this_thread::sleep_for(500ms);        //Mainly for debugging
    modem.setPreamble();
    std::this_thread::sleep_for(500ms);
    while(true){
        janus_rx(15);
    }
    return 0;
}
