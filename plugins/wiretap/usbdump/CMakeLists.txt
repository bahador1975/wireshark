# CMakeLists.txt
#
# Wireshark - Network traffic analyzer
# By Gerald Combs <gerald@wireshark.org>
# Copyright 1998 Gerald Combs
#
# SPDX-License-Identifier: GPL-2.0+
#

include(WiresharkPlugin)

# Plugin name and version info (major minor micro extra)
set_module_info(usbdump 0 0 1 0)

set(WIRETAP_SRC
	usbdump.c
)

set(PLUGIN_FILES
	plugin.c
	${WIRETAP_SRC}
)

set(CLEAN_FILES
	${PLUGIN_FILES}
)

set_source_files_properties(
	${CLEAN_FILES}
	PROPERTIES
	COMPILE_FLAGS "${WERROR_COMMON_FLAGS}"
)

include_directories(
	${CMAKE_SOURCE_DIR}/wiretap
	${CMAKE_CURRENT_SOURCE_DIR}
)

register_plugin_files(plugin.c
	plugin_wtap
	${WIRETAP_SRC}
)

add_plugin_library(usbdump wiretap)

install_plugin(usbdump wiretap)

file(GLOB WIRETAP_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.h")
CHECKAPI(
	NAME
	  usbdump
	SWITCHES
	  -g abort -g termoutput -build
	SOURCES
	  ${WIRETAP_SRC}
	  ${WIRETAP_HEADERS}
)

#
# Editor modelines  -  http://www.wireshark.org/tools/modelines.html
#
# Local variables:
# c-basic-offset: 8
# tab-width: 8
# indent-tabs-mode: t
# End:
#
# vi: set shiftwidth=8 tabstop=8 noexpandtab:
# :indentSize=8:tabSize=8:noTabs=false:
#
