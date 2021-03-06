###############################################################################
#
# Golem Plugin/ActiveCtrl/JointCtrl library
#
###############################################################################

option(GOLEM_BUILD_PLUGIN_ACTIVECTRL_JOINTCTRL_SFML "Build Plugin/ActiveCtrl/JointCtrl SFML joystick support" NO)
mark_as_advanced(GOLEM_BUILD_PLUGIN_ACTIVECTRL_JOINTCTRL_SFML)

if(GOLEM_BUILD_PLUGIN_ACTIVECTRL)
	SET(PACKAGE_DIR "${PACKAGE_PLUGIN_ACTIVECTRL}/JointCtrl")

	FILE(GLOB_RECURSE PACKAGE_SOURCES "${PACKAGE_DIR}/src/*.cpp")
	FILE(GLOB_RECURSE PACKAGE_HEADERS "${PACKAGE_DIR}/include/*.h")
	FILE(GLOB_RECURSE PACKAGE_FILES "${PACKAGE_DIR}/resources/*.xml")

	ADD_LIBRARY(GolemJointCtrl SHARED ${PACKAGE_SOURCES} ${PACKAGE_HEADERS} ${PACKAGE_FILES})

	TARGET_COMPILE_OPTIONS(GolemJointCtrl PUBLIC ${CMAKE_DLL_EXPORT_FLAGS})
	if(WIN32)
		if(GOLEM_BUILD_PLUGIN_ACTIVECTRL_JOINTCTRL_SFML)
			TARGET_COMPILE_OPTIONS(GolemJointCtrl PUBLIC /D_GOLEM_BUILD_PLUGIN_ACTIVECTRL_JOINTCTRL_SFML)
		endif(GOLEM_BUILD_PLUGIN_ACTIVECTRL_JOINTCTRL_SFML)
	elseif(UNIX)
	endif()

	TARGET_LINK_LIBRARIES(GolemJointCtrl GolemActiveCtrl)
	
	TARGET_INCLUDE_DIRECTORIES(GolemJointCtrl PUBLIC ${PACKAGE_DIR}/include)

	COPY_FILES(GolemJointCtrl ${RUNTIME_OUTPUT_DIRECTORY} ${PACKAGE_FILES})

	if (CPACK_BUILD_CORE)
		if (WIN32)
			INSTALL(TARGETS GolemJointCtrl RUNTIME DESTINATION bin COMPONENT activectrl_execs)
		elseif (UNIX)
			INSTALL(TARGETS GolemJointCtrl LIBRARY DESTINATION bin COMPONENT activectrl_execs)
		endif()
		INSTALL(FILES ${PACKAGE_HEADERS} DESTINATION include/Golem/ActiveCtrl/JointCtrl/ COMPONENT activectrl_headers)
		INSTALL(FILES ${PACKAGE_FILES} DESTINATION bin COMPONENT activectrl_configs)
	endif (CPACK_BUILD_CORE)

	SET_PROPERTY(TARGET GolemJointCtrl PROPERTY PROJECT_LABEL "JointCtrl")
	SET_PROPERTY(TARGET GolemJointCtrl PROPERTY FOLDER "Plugin/ActiveCtrl")
	SOURCE_GROUP("Include Files" FILES ${PACKAGE_HEADERS})
	SOURCE_GROUP("Resource Files" FILES ${PACKAGE_FILES})
endif(GOLEM_BUILD_PLUGIN_ACTIVECTRL)
