#######
# Dlt - Diagnostic Log and Trace
# @licence make begin@
#
# Copyright (C) 2011-2012, BMW AG - Alexander Wenzel <alexander.aw.wenzel@bmw.de>
# 
# Contributions are licensed to the GENIVI Alliance under one or more
# Contribution License Agreements.
# 
# This Source Code Form is subject to the terms of the
# Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
# this file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# @licence end@
########

if(WITH_SYSTEMD)

    set(SYSTEMD_CONFIGURATIONS_FILES_DIR "/lib/systemd/system" )
        
    if(WITH_SYSTEMD_WATCHDOG)
        set( DLT_WatchdogSec 2 )
        message( STATUS "The systemd watchdog is enabled - timeout is set to ${DLT_WatchdogSec} seconds")
    else(WITH_SYSTEMD_WATCHDOG) 
        set( DLT_WatchdogSec 0 )
        message( STATUS "The systemd watchdog is disabled")
    endif(WITH_SYSTEMD_WATCHDOG)
    
    configure_file(${CMAKE_SOURCE_DIR}/systemd/dlt.service.cmake ${PROJECT_BINARY_DIR}/systemd/dlt.service)
    message( STATUS "Configured systemd unit file:dlt.service" )
    
    configure_file(${CMAKE_SOURCE_DIR}/systemd/dlt-system.service.cmake ${PROJECT_BINARY_DIR}/systemd/dlt-system.service)
    message( STATUS "Configured systemd unit file:dlt-system.service" )
    
    configure_file(${CMAKE_SOURCE_DIR}/systemd/dlt-receive.service.cmake ${PROJECT_BINARY_DIR}/systemd/dlt-receive.service)
    message( STATUS "Configured systemd unit file:dlt-receive.service" )
    
    configure_file(${CMAKE_SOURCE_DIR}/systemd/dlt-example-user.service.cmake ${PROJECT_BINARY_DIR}/systemd/dlt-example-user.service)
    message( STATUS "Configured systemd unit file:dlt-example-user.service" )
    
    set( DLT_ADAPTOR_UDP_APPID "DUDP" )
    set( DLT_ADAPTOR_UDP_CTID "DCTI" )
    set( DLT_ADAPTOR_UDP_PORT 4712 )
    configure_file(${CMAKE_SOURCE_DIR}/systemd/dlt-adaptor-udp.service.cmake ${PROJECT_BINARY_DIR}/systemd/dlt-adaptor-udp.service)
    message( STATUS "Configured systemd unit file:dlt-adaptor-udp.service" )
    message(STATUS "DLT adaptor udp configuration: APPID=${DLT_ADAPTOR_UDP_APPID} CTID=${DLT_ADAPTOR_UDP_CTID} PORT=${DLT_ADAPTOR_UDP_PORT}" )
    
    
    if(EXISTS ${SYSTEMD_CONFIGURATIONS_FILES_DIR})
        install(FILES ${PROJECT_BINARY_DIR}/systemd/dlt.service DESTINATION ${SYSTEMD_CONFIGURATIONS_FILES_DIR} )
        install(FILES ${PROJECT_BINARY_DIR}/systemd/dlt-system.service DESTINATION ${SYSTEMD_CONFIGURATIONS_FILES_DIR} )
        install(FILES ${PROJECT_BINARY_DIR}/systemd/dlt-receive.service DESTINATION ${SYSTEMD_CONFIGURATIONS_FILES_DIR} )
        install(FILES ${PROJECT_BINARY_DIR}/systemd/dlt-example-user.service DESTINATION ${SYSTEMD_CONFIGURATIONS_FILES_DIR} )
        install(FILES ${PROJECT_BINARY_DIR}/systemd/dlt-adaptor-udp.service DESTINATION ${SYSTEMD_CONFIGURATIONS_FILES_DIR} )
        message(STATUS "Unit files will be installed to ${SYSTEMD_CONFIGURATIONS_FILES_DIR} after make install" )
    else(EXISTS ${SYSTEMD_CONFIGURATIONS_FILES_DIR})
        message(STATUS "Unit files will not be installed to ${SYSTEMD_CONFIGURATIONS_FILES_DIR} after make install")
    endif(EXISTS ${SYSTEMD_CONFIGURATIONS_FILES_DIR})
     
endif(WITH_SYSTEMD)