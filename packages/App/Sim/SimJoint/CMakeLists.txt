###############################################################################
#
# Golem App/Sim/SimJoint application
#
###############################################################################

if(GOLEM_BUILD_APP_SIM)
	SET(PACKAGE_DIR "${PACKAGE_APP_SIM}/SimJoint")

	FILE(GLOB_RECURSE PACKAGE_SOURCES "${PACKAGE_DIR}/src/*.cpp")
	FILE(GLOB_RECURSE PACKAGE_HEADERS "${PACKAGE_DIR}/include/*.h")
	FILE(GLOB_RECURSE PACKAGE_FILES "${PACKAGE_DIR}/resources/*.xml")

	ADD_EXECUTABLE(GolemAppSimJoint ${PACKAGE_SOURCES} ${PACKAGE_HEADERS} ${PACKAGE_FILES})
	TARGET_LINK_LIBRARIES(GolemAppSimJoint GolemAppCommon)
	TARGET_INCLUDE_DIRECTORIES(GolemAppSimJoint PUBLIC ${PACKAGE_DIR}/include)

	COPY_FILES(GolemAppSimJoint ${RUNTIME_OUTPUT_DIRECTORY} ${PACKAGE_FILES})
	SET_PROPERTY(TARGET GolemAppSimJoint PROPERTY RELEASE_POSTFIX ${CMAKE_RELEASE_POSTFIX})
	SET_PROPERTY(TARGET GolemAppSimJoint PROPERTY DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
	
	if (CPACK_BUILD_CORE)
		INSTALL(TARGETS GolemAppSimJoint RUNTIME DESTINATION bin COMPONENT app_execs)
		INSTALL(FILES ${PACKAGE_HEADERS} DESTINATION include/Golem/App/SimJoint/ COMPONENT app_headers)
		INSTALL(FILES ${PACKAGE_FILES} DESTINATION bin COMPONENT app_configs)
	endif (CPACK_BUILD_CORE)

	SET_PROPERTY(TARGET GolemAppSimJoint PROPERTY PROJECT_LABEL "SimJoint")
	SET_PROPERTY(TARGET GolemAppSimJoint PROPERTY FOLDER "App/Sim")
	SOURCE_GROUP("Include Files" FILES ${PACKAGE_HEADERS})
	SOURCE_GROUP("Resource Files" FILES ${PACKAGE_FILES})
endif(GOLEM_BUILD_APP_SIM)
