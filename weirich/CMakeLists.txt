cmake_minimum_required(VERSION 2.6)
project(ShapeOOC)

SET(CMAKE_BUILD_TYPE Debug)

enable_testing()

SET(CMAKE_C_COMPILER gcc)

SET(CMAKE_CXX_COMPILER g++)

SET(CSTANDARD "-std=gnu99")
SET(CWARN "-g -Wall -Wstrict-prototypes")
#SET(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
SET(COPT "-Os")

SET(CFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
SET(CXXFLAGS "${CMCU} ${CDEFS} ${CINCS} ${COPT}")

SET(CMAKE_C_FLAGS  ${CFLAGS})
SET(CMAKE_CXX_FLAGS ${CXXFLAGS})



set(CFILES
        main.c
        )


set(HFILES
        )

ADD_DEFINITIONS( -Wall )

ADD_EXECUTABLE( ShapeOOC WIN32 ${CFILES} ${HFILES} )
ADD_TEST(ShapeOOC ShapeOOC)
