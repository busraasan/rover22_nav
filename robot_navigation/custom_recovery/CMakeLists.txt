cmake_minimum_required(VERSION 3.0.2)
project(custom_recovery)

find_package(catkin REQUIRED
  COMPONENTS
    angles
    base_local_planner
    cmake_modules
    costmap_2d
    geometry_msgs
    nav_core
    pluginlib
    roscpp
    tf2
    tf2_geometry_msgs
    tf2_ros
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES custom_recovery
  CATKIN_DEPENDS
    costmap_2d
    geometry_msgs
    nav_core
    pluginlib
    roscpp
    tf2
    tf2_ros
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(custom_recovery
  src/CustomRecovery.cpp
)
add_dependencies(custom_recovery ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(
  custom_recovery
  ${catkin_LIBRARIES}
)

# add_executable(custom_behaviour src/CustomRecovery.cpp)
# add_dependencies(custom_behaviour ${catkin_EXPORTED_TARGETS})
# target_link_libraries(custom_behaviour ${catkin_LIBRARIES})
# include_directories(
#   include ${catkin_INCLUDE_DIRS}
# )
install(TARGETS custom_recovery
       ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
       )

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

install(FILES custom_plugin.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
