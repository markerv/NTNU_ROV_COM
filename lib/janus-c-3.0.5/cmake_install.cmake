# Install script for directory: /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_000_01.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_000_01.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_01.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_000_02.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_000_02.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_02.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_000_03.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_000_03.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_000_03.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_002_08.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_002_08.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_002_08.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_016_00.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_016_00.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_00.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/janus/plugins/libplugin_016_01.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/janus/plugins" TYPE MODULE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libplugin_016_01.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/janus/plugins/libplugin_016_01.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/libjanus.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx"
         RPATH "/usr/local/share/janus/plugins")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/janus-tx")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx"
         OLD_RPATH "::::::::::::::::::::::::::::::"
         NEW_RPATH "/usr/local/share/janus/plugins")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-tx")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx"
         RPATH "/usr/local/share/janus/plugins")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/janus-rx")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx"
         OLD_RPATH "::::::::::::::::::::::::::::::"
         NEW_RPATH "/usr/local/share/janus/plugins")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/janus-rx")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/carrier_sensing.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/chips_alignment.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/codec" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/codec/codec.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/codec" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/codec/codecs.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/codec" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/codec/fields.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/codec" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/codec/plugin.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/complex.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/constants.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/convolve.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/crc.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/ddc.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/defaults.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/deinterleave.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/demodulator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/doppler.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/duc.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/dump.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/error.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/export.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/goertzel.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/hop_index.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/interleave.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/janus.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/modulator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/msb.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/packet.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/parameters.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/primitive.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/pset.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/pset_parser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/rx.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/rx_state.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/simple_rx.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/simple_tx.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/stream" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/stream/format.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/stream" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/stream/istream.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/stream" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/stream/ostream.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/trellis.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/tx.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/tx_state.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/types.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/bin2dec.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/cfar.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/dec2bin.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/fifo.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/fir.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/gcd.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/go_cfar.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/hamming_window.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/imath.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/memory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/primes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/quad_fitn.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus/utils" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/utils/tukey_window.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/viterbi.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/janus/wake_up_tones.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/janus" TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/cmake_generated/janus/config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/COPYING")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/janus" TYPE DIRECTORY FILES "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/etc" REGEX "/\\.svn$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
