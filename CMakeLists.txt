cmake_minimum_required(VERSION 2.8.3)
project(ros_test)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    dynamic_reconfigure)

generate_dynamic_reconfigure_options(cfg/Test.cfg)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(dynamic_reconfigure_test src/dynamic_reconfigure_test.cpp)
add_dependencies(dynamic_reconfigure_test ${PROJECT_NAME}_gencfg)
target_link_libraries(dynamic_reconfigure_test ${catkin_LIBRARIES})

install(TARGETS dynamic_reconfigure_test
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

foreach(dir launch config)
    install(DIRECTORY ${dir}/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
