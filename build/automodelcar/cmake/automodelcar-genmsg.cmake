# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "automodelcar: 3 messages, 0 services")

set(MSG_I_FLAGS "-Iautomodelcar:/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(automodelcar_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_custom_target(_automodelcar_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "automodelcar" "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_custom_target(_automodelcar_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "automodelcar" "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" "geometry_msgs/Point:std_msgs/Header"
)

get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_custom_target(_automodelcar_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "automodelcar" "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar
)
_generate_msg_cpp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar
)
_generate_msg_cpp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar
)

### Generating Services

### Generating Module File
_generate_module_cpp(automodelcar
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(automodelcar_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(automodelcar_generate_messages automodelcar_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_cpp _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_cpp _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_cpp _automodelcar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automodelcar_gencpp)
add_dependencies(automodelcar_gencpp automodelcar_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automodelcar_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar
)
_generate_msg_eus(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar
)
_generate_msg_eus(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar
)

### Generating Services

### Generating Module File
_generate_module_eus(automodelcar
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(automodelcar_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(automodelcar_generate_messages automodelcar_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_eus _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_eus _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_eus _automodelcar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automodelcar_geneus)
add_dependencies(automodelcar_geneus automodelcar_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automodelcar_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar
)
_generate_msg_lisp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar
)
_generate_msg_lisp(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar
)

### Generating Services

### Generating Module File
_generate_module_lisp(automodelcar
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(automodelcar_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(automodelcar_generate_messages automodelcar_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_lisp _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_lisp _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_lisp _automodelcar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automodelcar_genlisp)
add_dependencies(automodelcar_genlisp automodelcar_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automodelcar_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar
)
_generate_msg_nodejs(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar
)
_generate_msg_nodejs(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar
)

### Generating Services

### Generating Module File
_generate_module_nodejs(automodelcar
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(automodelcar_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(automodelcar_generate_messages automodelcar_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_nodejs _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_nodejs _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_nodejs _automodelcar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automodelcar_gennodejs)
add_dependencies(automodelcar_gennodejs automodelcar_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automodelcar_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar
)
_generate_msg_py(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar
)
_generate_msg_py(automodelcar
  "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar
)

### Generating Services

### Generating Module File
_generate_module_py(automodelcar
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(automodelcar_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(automodelcar_generate_messages automodelcar_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Lane.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_py _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Obstacles.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_py _automodelcar_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg/Intersection.msg" NAME_WE)
add_dependencies(automodelcar_generate_messages_py _automodelcar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(automodelcar_genpy)
add_dependencies(automodelcar_genpy automodelcar_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS automodelcar_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/automodelcar
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(automodelcar_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(automodelcar_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/automodelcar
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(automodelcar_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(automodelcar_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/automodelcar
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(automodelcar_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(automodelcar_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/automodelcar
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(automodelcar_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(automodelcar_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/automodelcar
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(automodelcar_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(automodelcar_generate_messages_py std_msgs_generate_messages_py)
endif()
