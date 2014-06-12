#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>

#include <ros_test/TestConfig.h>

#include <string>

class DynamicReconfigureTest
{
public:
    DynamicReconfigureTest()
        : nh_()
        , server_(nh_)
    {
        const ros_test::TestConfig& defaults = ros_test::TestConfig::__getDefault__();
        ROS_INFO_STREAM("config defaults: " <<
            "foo = " << defaults.foo << ", " <<
            "bar = " << defaults.bar << ", " <<
            "baz = " << defaults.baz << ", " <<
            "qux = " << defaults.qux << ", " <<
            "quux = " << defaults.quux
            );

        server_.setCallback(boost::bind(&DynamicReconfigureTest::callback, this, _1, _2));
    }

    void callback(ros_test::TestConfig &config, uint32_t level)
    {
        ROS_INFO_STREAM("config callback: " <<
            "foo = " << config.foo << ", " <<
            "bar = " << config.bar << ", " <<
            "baz = " << config.baz << ", " <<
            "qux = " << config.qux << ", " <<
            "quux = " << config.quux
            );
    }

private:
    ros::NodeHandle nh_;
    dynamic_reconfigure::Server<ros_test::TestConfig> server_;
};

int
main(int argc, char** argv)
{
    ros::init(argc, argv, "dynamic_reconfigure_test");

    DynamicReconfigureTest drt;

    ros::spin();

    return 0;
}

