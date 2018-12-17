ADD_EXECUTABLE(mainpipe mainpipe.c server.c client.c)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/headers)
SET(LIBS error wrapper_func)
TARGET_LINK_LIBRARIES(mainpipe ${LIBS})
