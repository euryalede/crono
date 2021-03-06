########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: crono.pri
#
# Author: $author$
#   Date: 4/19/2018
#
# QtCreator .pri file for crono executable crono
########################################################################

########################################################################
# crono

# crono_exe TARGET
#
crono_exe_TARGET = crono

# crono_exe INCLUDEPATH
#
crono_exe_INCLUDEPATH += \
$${crono_INCLUDEPATH} \

# crono_exe DEFINES
#
crono_exe_DEFINES += \
$${crono_DEFINES} \

########################################################################
# crono_exe OBJECTIVE_HEADERS
#
#crono_exe_OBJECTIVE_HEADERS += \
#$${CRONO_SRC}/crono/base/Base.hh \

# crono_exe OBJECTIVE_SOURCES
#
#crono_exe_OBJECTIVE_SOURCES += \
#$${CRONO_SRC}/crono/base/Base.mm \

########################################################################
# crono_exe HEADERS
#
crono_exe_HEADERS += \
$${NADIR_SRC}/xos/base/Locked.hpp \
$${NADIR_SRC}/xos/console/Io.hpp \
$${NADIR_SRC}/xos/console/Main.hpp \
$${CRONO_SRC}/xos/logger/Level.hpp \
$${CRONO_SRC}/xos/logger/Output.hpp \
$${CRONO_SRC}/xos/logger/Interface.hpp \
$${CRONO_SRC}/xos/console/Logger.hpp \
$${CRONO_SRC}/xos/console/Main_main.hpp \
$${CRONO_SRC}/xos/app/console/crono/Main.hpp \

# crono_exe SOURCES
#
crono_exe_SOURCES += \
$${NADIR_SRC}/xos/base/Locked.cpp \
$${NADIR_SRC}/xos/console/Io.cpp \
$${CRONO_SRC}/xos/logger/Level.cpp \
$${CRONO_SRC}/xos/logger/Output.hpp \
$${CRONO_SRC}/xos/logger/Interface.cpp \
$${CRONO_SRC}/xos/console/Logger.cpp \
$${CRONO_SRC}/xos/console/Main_main.cpp \
$${CRONO_SRC}/xos/app/console/crono/Main.cpp \

########################################################################
# crono_exe FRAMEWORKS
#
crono_exe_FRAMEWORKS += \
$${crono_FRAMEWORKS} \

# crono_exe LIBS
#
crono_exe_LIBS += \
$${crono_LIBS} \


