ADD_EXECUTABLE(mainpipe mainpipe.c server.c client.c)
ADD_EXECUTABLE(mainpopen mainpopen.c)
SET(LIBS wrapper_func)
TARGET_LINK_LIBRARIES(mainpipe ${LIBS})
TARGET_LINK_LIBRARIES(mainpopen ${LIBS})

