# Auto-generated by Transcend/configure for the GNU/Linux X86 platform.  Do not edit manually.
#
# Modification History
#
# 2002-September-9    Jason Rohrer
# Created.
#
# 2003-November-2   Jason Rohrer
# Moved minorGems platform prefixes into platform-specific Makefile templates.
#
# 2004-September-26   Jason Rohrer
# Added missing link flags.
#


##
# The common GnuLinuxX86 portion of Makefiles.
# Should not be made manually---used by configure to build Makefiles.
##


PLATFORM_COMPILE_FLAGS = -DLINUX

# pthread library needed for linux
# also need portaudio library (which in turn needs pthreads)
PLATFORM_LINK_FLAGS = -L/usr/X11R6/lib -lGL -lglut -lGLU -lX11 -lXi -lXext -lXmu ${ROOT_PATH}/Transcend/portaudio/lib/libportaudio.a -lpthread -lrt -lm -lasound -ljack


# All platforms but OSX support g++ and need no linker hacks
GXX=g++ 
LINK_FLAGS = 


##
# Platform-specific minorGems file path prefixes
##

PLATFORM = Linux
PLATFORM_PATH = linux

TIME_PLATFORM = Unix
TIME_PLATFORM_PATH = unix

DIRECTORY_PLATFORM = Unix
DIRECTORY_PLATFORM_PATH = unix
#
# Modification History
#
# 2004-April-30    Jason Rohrer
# Created.  Modified from MUTE source.
#
# 2005-August-29    Jason Rohrer
# Added optimization options.
#


##
# The common portion of all Makefiles.
# Should not be made manually---used by configure to build Makefiles.
##


EXE_LINKER = ${GXX}

RANLIB = ranlib
LIBRARY_LINKER = ar


DEBUG_ON_FLAG = -g #-DDEBUG_MEMORY
DEBUG_OFF_FLAG = 

DEBUG_FLAG = ${DEBUG_OFF_FLAG}


PROFILE_ON_FLAG = -pg -a -DUSE_GPROF_THREADS
PROFILE_OFF_FLAG = 

PROFILE_FLAG = ${PROFILE_OFF_FLAG}


OPTIMIZE_ON_FLAG = -O9
OPTIMIZE_OFF_FLAG = 

OPTIMIZE_FLAG = ${OPTIMIZE_ON_FLAG}


COMPILE_FLAGS = -Wall ${DEBUG_FLAG} ${PLATFORM_COMPILE_FLAGS} ${PROFILE_FLAG} ${OPTIMIZE_FLAG} -I${ROOT_PATH} -I${ROOT_PATH}/Transcend/portaudio/pa_common


COMPILE = ${GXX} ${COMPILE_FLAGS} -c
EXE_LINK = ${EXE_LINKER} ${COMPILE_FLAGS} ${LINK_FLAGS}
LIBRARY_LINK = ${LIBRARY_LINKER} cru


# 
# Generic:
#
# Map all .cpp C++ and C files into .o object files
#
# $@   represents the name.o file
# $<   represents the name.cpp file
#
.cpp.o:
	${COMPILE} -o $@ $<
.c.o:
	${COMPILE} -o $@ $<






#
# Modification History
#
# 2002-September-9    Jason Rohrer
# Created.
#
# 2002-September-10    Jason Rohrer
# Moved targets to Makefile.minorGems_targets.
#
# 2002-September-12    Jason Rohrer
# Added support for XMLUtils.
# Added support for HTMLUtils.
#
# 2002-September-17    Jason Rohrer
# Added support for SettingsManager.
#
# 2002-October-17    Jason Rohrer
# Added support for debugMemory.
#
# 2002-October-18    Jason Rohrer
# Fixed support for debugMemory.
#
# 2003-January-23    Jason Rohrer
# Added support for Directory.
#
# 2003-May-25    Jason Rohrer
# Added sha1.
#
# 2003-July-27    Jason Rohrer
# Added p2p parts.
#
# 2003-August-7    Jason Rohrer
# Added DuplicateMessageDetector.
#
# 2003-August-12    Jason Rohrer
# Added protocolUtils.
#
# 2003-August-22    Jason Rohrer
# Added encoding utils.
#
# 2003-September-4    Jason Rohrer
# Added mime typer.
#
# 2003-September-5    Jason Rohrer
# Added web server.
#
# 2003-September-7    Jason Rohrer
# Fixed path bugs.
#
# 2003-October-9    Jason Rohrer
# Added message limiter.
#
# 2003-November-2   Jason Rohrer
# Moved minorGems platform prefixes into platform-specific Makefile templates.
#
# 2004-January-4   Jason Rohrer
# Added network function locks.
#
# 2004-April-1   Jason Rohrer
# Added FinishedSignalThreads.
#
# 2004-May-10   Jason Rohrer
# Added AIFF format.
#
# 2004-June-10   Jason Rohrer
# Added ScreenGL.
#


##
# The common portion of Makefiles for all targets that use minorGems,
# supplying variable definitions for minorGems.
#
# Should not be made manually---used by configure to build Makefiles.
##







PLATFORM_DIRECTORY = ${ROOT_PATH}/minorGems/io/file/${DIRECTORY_PLATFORM_PATH}/Directory${DIRECTORY_PLATFORM}

PLATFORM_TIME = ${ROOT_PATH}/minorGems/system/${TIME_PLATFORM_PATH}/Time${TIME_PLATFORM}

PLATFORM_HOST_ADDRESS = ${ROOT_PATH}/minorGems/network/${PLATFORM_PATH}/HostAddress${PLATFORM}

PLATFORM_SOCKET = ${ROOT_PATH}/minorGems/network/${PLATFORM_PATH}/Socket${PLATFORM}

PLATFORM_SOCKET_CLIENT = ${ROOT_PATH}/minorGems/network/${PLATFORM_PATH}/SocketClient${PLATFORM}

PLATFORM_SOCKET_SERVER = ${ROOT_PATH}/minorGems/network/${PLATFORM_PATH}/SocketServer${PLATFORM}


PLATFORM_TYPE_IO = ${ROOT_PATH}/minorGems/io/${PLATFORM_PATH}/TypeIO${PLATFORM}

PLATFORM_THREAD = ${ROOT_PATH}/minorGems/system/${PLATFORM_PATH}/Thread${PLATFORM}

PLATFORM_MUTEX_LOCK = ${ROOT_PATH}/minorGems/system/${PLATFORM_PATH}/MutexLock${PLATFORM}

PLATFORM_BINARY_SEMAPHORE = ${ROOT_PATH}/minorGems/system/${PLATFORM_PATH}/BinarySemaphore${PLATFORM}



##
# Header, source, and object files.
##

SIMPLE_VECTOR_H = ${ROOT_PATH}/minorGems/util/SimpleVector.h

OUTPUT_STREAM_H = ${ROOT_PATH}/minorGems/io/OutputStream.h
INPUT_STREAM_H = ${ROOT_PATH}/minorGems/io/InputStream.h


HOST_ADDRESS_H = ${ROOT_PATH}/minorGems/network/HostAddress.h
HOST_ADDRESS_CPP = ${PLATFORM_HOST_ADDRESS}.cpp
HOST_ADDRESS_O = ${PLATFORM_HOST_ADDRESS}.o

SOCKET_H = ${ROOT_PATH}/minorGems/network/Socket.h
SOCKET_CPP = ${PLATFORM_SOCKET}.cpp
SOCKET_O = ${PLATFORM_SOCKET}.o

SOCKET_CLIENT_H = ${ROOT_PATH}/minorGems/network/SocketClient.h
SOCKET_CLIENT_CPP = ${PLATFORM_SOCKET_CLIENT}.cpp
SOCKET_CLIENT_O = ${PLATFORM_SOCKET_CLIENT}.o

SOCKET_SERVER_H = ${ROOT_PATH}/minorGems/network/SocketServer.h
SOCKET_SERVER_CPP = ${PLATFORM_SOCKET_SERVER}.cpp
SOCKET_SERVER_O = ${PLATFORM_SOCKET_SERVER}.o

SOCKET_STREAM_H = ${ROOT_PATH}/minorGems/network/SocketStream.h

NETWORK_FUNCTION_LOCKS = ${ROOT_PATH}/minorGems/network/NetworkFunctionLocks
NETWORK_FUNCTION_LOCKS_H = ${NETWORK_FUNCTION_LOCKS}.h
NETWORK_FUNCTION_LOCKS_CPP = ${NETWORK_FUNCTION_LOCKS}.cpp
NETWORK_FUNCTION_LOCKS_O = ${NETWORK_FUNCTION_LOCKS}.o

PATH_H = ${ROOT_PATH}/minorGems/io/file/Path.h
PATH_CPP = ${ROOT_PATH}/minorGems/io/file/${PLATFORM_PATH}/Path${PLATFORM}.cpp
PATH_O = ${ROOT_PATH}/minorGems/io/file/${PLATFORM_PATH}/Path${PLATFORM}.o


FILE_H = ${ROOT_PATH}/minorGems/io/file/File.h
FILE_OUTPUT_STREAM_H = ${ROOT_PATH}/minorGems/io/file/FileOutputStream.h
FILE_INPUT_STREAM_H = ${ROOT_PATH}/minorGems/io/file/FileInputStream.h

DIRECTORY_H = ${ROOT_PATH}/minorGems/io/file/Directory.h
DIRECTORY_CPP = ${PLATFORM_DIRECTORY}.cpp
DIRECTORY_O = ${PLATFORM_DIRECTORY}.o


TYPE_IO_H = ${ROOT_PATH}/minorGems/io/TypeIO.h
TYPE_IO_CPP = ${PLATFORM_TYPE_IO}.cpp
TYPE_IO_O = ${PLATFORM_TYPE_IO}.o


TIME_H = ${ROOT_PATH}/minorGems/system/Time.h
TIME_CPP = ${PLATFORM_TIME}.cpp
TIME_O = ${PLATFORM_TIME}.o

THREAD_H = ${ROOT_PATH}/minorGems/system/Thread.h
THREAD_CPP = ${PLATFORM_THREAD}.cpp
THREAD_O = ${PLATFORM_THREAD}.o

MUTEX_LOCK_H = ${ROOT_PATH}/minorGems/system/MutexLock.h
MUTEX_LOCK_CPP = ${PLATFORM_MUTEX_LOCK}.cpp
MUTEX_LOCK_O = ${PLATFORM_MUTEX_LOCK}.o


BINARY_SEMAPHORE_H = ${ROOT_PATH}/minorGems/system/BinarySemaphore.h
BINARY_SEMAPHORE_CPP = ${PLATFORM_BINARY_SEMAPHORE}.cpp
BINARY_SEMAPHORE_O = ${PLATFORM_BINARY_SEMAPHORE}.o


SEMAPHORE_H = ${ROOT_PATH}/minorGems/system/Semaphore.h

APP_LOG_H = ${ROOT_PATH}/minorGems/util/log/AppLog.h
APP_LOG_CPP = ${ROOT_PATH}/minorGems/util/log/AppLog.cpp
APP_LOG_O = ${ROOT_PATH}/minorGems/util/log/AppLog.o

PRINT_LOG_H = ${ROOT_PATH}/minorGems/util/log/PrintLog.h
PRINT_LOG_CPP = ${ROOT_PATH}/minorGems/util/log/PrintLog.cpp
PRINT_LOG_O = ${ROOT_PATH}/minorGems/util/log/PrintLog.o


FILE_LOG_H = ${ROOT_PATH}/minorGems/util/log/FileLog.h
FILE_LOG_CPP = ${ROOT_PATH}/minorGems/util/log/FileLog.cpp
FILE_LOG_O = ${ROOT_PATH}/minorGems/util/log/FileLog.o


LOG_H = ${ROOT_PATH}/minorGems/util/log/Log.h
LOG_CPP = ${ROOT_PATH}/minorGems/util/log/Log.cpp
LOG_O = ${ROOT_PATH}/minorGems/util/log/Log.o


PRINT_UTILS_H = ${ROOT_PATH}/minorGems/util/printUtils.h
PRINT_UTILS_CPP = ${ROOT_PATH}/minorGems/util/printUtils.cpp
PRINT_UTILS_O = ${ROOT_PATH}/minorGems/util/printUtils.o


WEB_CLIENT_H = ${ROOT_PATH}/minorGems/network/web/WebClient.h
WEB_CLIENT_CPP = ${ROOT_PATH}/minorGems/network/web/WebClient.cpp
WEB_CLIENT_O = ${ROOT_PATH}/minorGems/network/web/WebClient.o

URL_UTILS_H = ${ROOT_PATH}/minorGems/network/web/URLUtils.h
URL_UTILS_CPP = ${ROOT_PATH}/minorGems/network/web/URLUtils.cpp
URL_UTILS_O = ${ROOT_PATH}/minorGems/network/web/URLUtils.o

MIME_TYPER = ${ROOT_PATH}/minorGems/network/web/MimeTyper
MIME_TYPER_H = ${MIME_TYPER}.h
MIME_TYPER_CPP = ${MIME_TYPER}.cpp
MIME_TYPER_O = ${MIME_TYPER}.o


WEB_SERVER_PATH = ${ROOT_PATH}/minorGems/network/web/server

WEB_SERVER = ${WEB_SERVER_PATH}/WebServer
WEB_SERVER_H = ${WEB_SERVER}.h
WEB_SERVER_CPP = ${WEB_SERVER}.cpp
WEB_SERVER_O = ${WEB_SERVER}.o

REQUEST_HANDLING_THREAD = ${WEB_SERVER_PATH}/RequestHandlingThread
REQUEST_HANDLING_THREAD_H = ${REQUEST_HANDLING_THREAD}.h
REQUEST_HANDLING_THREAD_CPP = ${REQUEST_HANDLING_THREAD}.cpp
REQUEST_HANDLING_THREAD_O = ${REQUEST_HANDLING_THREAD}.o

THREAD_HANDLING_THREAD = ${WEB_SERVER_PATH}/ThreadHandlingThread
THREAD_HANDLING_THREAD_H = ${THREAD_HANDLING_THREAD}.h
THREAD_HANDLING_THREAD_CPP = ${THREAD_HANDLING_THREAD}.cpp
THREAD_HANDLING_THREAD_O = ${THREAD_HANDLING_THREAD}.o

CONNECTION_PERMISSION_HANDLER = ${WEB_SERVER_PATH}/ConnectionPermissionHandler
CONNECTION_PERMISSION_HANDLER_H = ${CONNECTION_PERMISSION_HANDLER}.h
CONNECTION_PERMISSION_HANDLER_CPP = ${CONNECTION_PERMISSION_HANDLER}.cpp
CONNECTION_PERMISSION_HANDLER_O = ${CONNECTION_PERMISSION_HANDLER}.o

STOP_SIGNAL_THREAD = ${ROOT_PATH}/minorGems/system/StopSignalThread
STOP_SIGNAL_THREAD_H = ${STOP_SIGNAL_THREAD}.h
STOP_SIGNAL_THREAD_CPP = ${STOP_SIGNAL_THREAD}.cpp
STOP_SIGNAL_THREAD_O = ${STOP_SIGNAL_THREAD}.o

FINISHED_SIGNAL_THREAD = ${ROOT_PATH}/minorGems/system/FinishedSignalThread
FINISHED_SIGNAL_THREAD_H = ${FINISHED_SIGNAL_THREAD}.h
FINISHED_SIGNAL_THREAD_CPP = ${FINISHED_SIGNAL_THREAD}.cpp
FINISHED_SIGNAL_THREAD_O = ${FINISHED_SIGNAL_THREAD}.o





STRING_BUFFER_OUTPUT_STREAM_H = ${ROOT_PATH}/minorGems/util/StringBufferOutputStream.h
STRING_BUFFER_OUTPUT_STREAM_CPP = ${ROOT_PATH}/minorGems/util/StringBufferOutputStream.cpp
STRING_BUFFER_OUTPUT_STREAM_O = ${ROOT_PATH}/minorGems/util/StringBufferOutputStream.o


XML_UTILS_H = ${ROOT_PATH}/minorGems/formats/xml/XMLUtils.h
XML_UTILS_CPP = ${ROOT_PATH}/minorGems/formats/xml/XMLUtils.cpp
XML_UTILS_O = ${ROOT_PATH}/minorGems/formats/xml/XMLUtils.o


HTML_UTILS_H = ${ROOT_PATH}/minorGems/formats/html/HTMLUtils.h
HTML_UTILS_CPP = ${ROOT_PATH}/minorGems/formats/html/HTMLUtils.cpp
HTML_UTILS_O = ${ROOT_PATH}/minorGems/formats/html/HTMLUtils.o


SETTINGS_MANAGER_H = ${ROOT_PATH}/minorGems/util/SettingsManager.h
SETTINGS_MANAGER_CPP = ${ROOT_PATH}/minorGems/util/SettingsManager.cpp
SETTINGS_MANAGER_O = ${ROOT_PATH}/minorGems/util/SettingsManager.o


STRING_UTILS = ${ROOT_PATH}/minorGems/util/stringUtils
STRING_UTILS_H = ${STRING_UTILS}.h
STRING_UTILS_CPP = ${STRING_UTILS}.cpp
STRING_UTILS_O = ${STRING_UTILS}.o


SHA1 = ${ROOT_PATH}/minorGems/crypto/hashes/sha1
SHA1_H = ${SHA1}.h
SHA1_CPP = ${SHA1}.cpp
SHA1_O = ${SHA1}.o


AIFF = ${ROOT_PATH}/minorGems/sound/formats/aiff
AIFF_H = ${AIFF}.h
AIFF_CPP = ${AIFF}.cpp
AIFF_O = ${AIFF}.o



MEMORY_TRACK_H = ${ROOT_PATH}/minorGems/util/development/memory/MemoryTrack.h
MEMORY_TRACK_CPP = ${ROOT_PATH}/minorGems/util/development/memory/MemoryTrack.cpp
MEMORY_TRACK_O = ${ROOT_PATH}/minorGems/util/development/memory/MemoryTrack.o


DEBUG_MEMORY = ${ROOT_PATH}/minorGems/util/development/memory/debugMemory
DEBUG_MEMORY_H = ${DEBUG_MEMORY}.h
DEBUG_MEMORY_CPP = ${DEBUG_MEMORY}.cpp
DEBUG_MEMORY_O = ${DEBUG_MEMORY}.o


# variable pointing to both necessary .o files for memory tracking
MEMORY_TRACKER_O = ${MEMORY_TRACK_O} ${DEBUG_MEMORY_O}


# p2p parts

HOST_CATCHER = ${ROOT_PATH}/minorGems/network/p2pParts/HostCatcher
HOST_CATCHER_H = ${HOST_CATCHER}.h
HOST_CATCHER_CPP = ${HOST_CATCHER}.cpp
HOST_CATCHER_O = ${HOST_CATCHER}.o

OUTBOUND_CHANNEL = ${ROOT_PATH}/minorGems/network/p2pParts/OutboundChannel
OUTBOUND_CHANNEL_H = ${OUTBOUND_CHANNEL}.h
OUTBOUND_CHANNEL_CPP = ${OUTBOUND_CHANNEL}.cpp
OUTBOUND_CHANNEL_O = ${OUTBOUND_CHANNEL}.o

DUPLICATE_MESSAGE_DETECTOR = ${ROOT_PATH}/minorGems/network/p2pParts/DuplicateMessageDetector
DUPLICATE_MESSAGE_DETECTOR_H = ${DUPLICATE_MESSAGE_DETECTOR}.h
DUPLICATE_MESSAGE_DETECTOR_CPP = ${DUPLICATE_MESSAGE_DETECTOR}.cpp
DUPLICATE_MESSAGE_DETECTOR_O = ${DUPLICATE_MESSAGE_DETECTOR}.o

PROTOCOL_UTILS = ${ROOT_PATH}/minorGems/network/p2pParts/protocolUtils
PROTOCOL_UTILS_H = ${PROTOCOL_UTILS}.h
PROTOCOL_UTILS_CPP = ${PROTOCOL_UTILS}.cpp
PROTOCOL_UTILS_O = ${PROTOCOL_UTILS}.o

MESSAGE_PER_SECOND_LIMITER = ${ROOT_PATH}/minorGems/network/p2pParts/MessagePerSecondLimiter
MESSAGE_PER_SECOND_LIMITER_H = ${MESSAGE_PER_SECOND_LIMITER}.h
MESSAGE_PER_SECOND_LIMITER_CPP = ${MESSAGE_PER_SECOND_LIMITER}.cpp
MESSAGE_PER_SECOND_LIMITER_O = ${MESSAGE_PER_SECOND_LIMITER}.o






ENCODING_UTILS = ${ROOT_PATH}/minorGems/formats/encodingUtils
ENCODING_UTILS_H = ${ENCODING_UTILS}.h
ENCODING_UTILS_CPP = ${ENCODING_UTILS}.cpp
ENCODING_UTILS_O = ${ENCODING_UTILS}.o





# OpenGL parts

SCREEN_GL = ${ROOT_PATH}/minorGems/graphics/openGL/ScreenGL
SCREEN_GL_H = ${SCREEN_GL}.h
SCREEN_GL_CPP = ${SCREEN_GL}.cpp
SCREEN_GL_O = ${SCREEN_GL}.o

#
# Modification History
#
# 2004-August-25    Jason Rohrer
# Created.  Copied from game/Makefile.all.
#


##
# The portion of editor Makefiles common to all 
# platforms.
# Should not be made manually---used by game1/configure to build Makefiles.
##




ROOT_PATH = ../..

GAME_PATH = ${ROOT_PATH}/Transcend/game


LAYER_SOURCE = \
 ObjectControlPointEditor.cpp \
 ${GAME_PATH}/DrawableObject.cpp \
 ${GAME_PATH}/NamedColorFactory.cpp \
 ${GAME_PATH}/LevelDirectoryManager.cpp \
 ${GAME_PATH}/ParameterSpaceControlPoint.cpp \
 ${GAME_PATH}/ObjectParameterSpaceControlPoint.cpp
 
LAYER_OBJECTS = ${LAYER_SOURCE:.cpp=.o}

NEEDED_MINOR_GEMS_OBJECTS = \
 ${SCREEN_GL_O} \
 ${TYPE_IO_O} \
 ${STRING_UTILS_O} \
 ${STRING_BUFFER_OUTPUT_STREAM_O} \
 ${PATH_O} \
 ${TIME_O} \
 ${THREAD_O} \
 ${MUTEX_LOCK_O}
 


TEST_SOURCE = 
TEST_OBJECTS = ${TEST_SOURCE:.cpp=.o}



DEPENDENCY_FILE = Makefile.dependencies


# targets

all: objectControlPointEditor
clean:
	rm -f ${DEPENDENCY_FILE} ${LAYER_OBJECTS} ${TEST_OBJECTS} ${NEEDED_MINOR_GEMS_OBJECTS} objectControlPointEditor




objectControlPointEditor: ${LAYER_OBJECTS} ${NEEDED_MINOR_GEMS_OBJECTS}
	${EXE_LINK} -o objectControlPointEditor ${LAYER_OBJECTS} ${NEEDED_MINOR_GEMS_OBJECTS} ${PLATFORM_LINK_FLAGS}




# build the dependency file
${DEPENDENCY_FILE}: ${LAYER_SOURCE} ${TEST_SOURCE}
	rm -f ${DEPENDENCY_FILE}
	${COMPILE} -MM ${LAYER_SOURCE} ${TEST_SOURCE} >> ${DEPENDENCY_FILE}


include ${DEPENDENCY_FILE}


#
# Modification History
#
# 2003-July-27   Jason Rohrer
# Created.  Modified from konspire2b source.
# Added p2p parts.
#
# 2003-August-7    Jason Rohrer
# Added DuplicateMessageDetector.
#
# 2003-August-12    Jason Rohrer
# Added protocolUtils.
#
# 2003-August-22    Jason Rohrer
# Added encoding utils.
#
# 2003-September-4    Jason Rohrer
# Added mime typer.
#
# 2003-September-5    Jason Rohrer
# Added web server.
#
# 2003-September-8    Jason Rohrer
# Added use of sed to fix auto-generated dependency path.
#
# 2003-October-9    Jason Rohrer
# Added message limiter.
#
# 2004-January-4   Jason Rohrer
# Added network function locks.
#
# 2004-April-1   Jason Rohrer
# Added FinishedSignalThreads.
#
# 2004-May-10   Jason Rohrer
# Added AIFF format.
#
# 2004-June-10   Jason Rohrer
# Added ScreenGL.
#



##
# The common portion of Makefiles for all targets that use minorGems,
# supplying target dependencies for minorGems targets.
#
# Should not be made manually---used by configure to build Makefiles.
##



##
# Dependencies.
##

MINOR_GEMS_SOURCE = \
 ${HOST_ADDRESS_CPP} \
 ${SOCKET_CPP} \
 ${SOCKET_SERVER_CPP} \
 ${SOCKET_CLIENT_CPP} \
 ${NETWORK_FUNCTION_LOCKS_CPP} \
 ${PATH_CPP} \
 ${DIRECTORY_CPP} \
 ${TYPE_IO_CPP} \
 ${TIME_CPP} \
 ${THREAD_CPP} \
 ${MUTEX_LOCK_CPP} \
 ${BINARY_SEMAPHORE_CPP} \
 ${APP_LOG_CPP} \
 ${PRINT_LOG_CPP} \
 ${FILE_LOG_CPP} \
 ${LOG_CPP} \
 ${PRINT_UTILS_CPP} \
 ${WEB_CLIENT_CPP} \
 ${URL_UTILS_CPP} \
 ${MIME_TYPER_CPP} \
 ${STRING_BUFFER_OUTPUT_STREAM_CPP} \
 ${XML_UTILS_CPP} \
 ${HTML_UTILS_CPP} \
 ${SETTINGS_MANAGER_CPP} \
 ${STRING_UTILS_CPP} \
 ${SHA1_CPP} \
 ${AIFF_CPP} \
 ${MEMORY_TRACK_CPP} \
 ${DEBUG_MEMORY_CPP} \
 ${HOST_CATCHER_CPP} \
 ${OUTBOUND_CHANNEL_CPP} \
 ${DUPLICATE_MESSAGE_DETECTOR_CPP} \
 ${PROTOCOL_UTILS_CPP} \
 ${MESSAGE_PER_SECOND_LIMITER_CPP} \
 ${ENCODING_UTILS_CPP} \
 ${WEB_SERVER_CPP} \
 ${REQUEST_HANDLING_THREAD_CPP} \
 ${THREAD_HANDLING_THREAD_CPP} \
 ${CONNECTION_PERMISSION_HANDLER_CPP} \
 ${STOP_SIGNAL_THREAD_CPP} \
 ${FINISHED_SIGNAL_THREAD_CPP} \
 ${SCREEN_GL_CPP}


# sed command for fixing up the dependencies generated by g++
# g++ (pre-3.0) leaves the path off of the .o target
# look for a .o file at the beginning of a line (in other words, one
# without a path), and replace it with the full-path version.
# This should be compatible with g++ 3.0, since we only replace .o names
# that occur at the beginning of a line (using the "^" modifier)

MINOR_GEMS_SED_FIX_COMMAND = sed ' \
s/^HostAddress.*\.o/$${HOST_ADDRESS_O}/; \
s/^Socket.*\.o/$${SOCKET_O}/; \
s/^SocketServer.*\.o/$${SOCKET_SERVER_O}/; \
s/^SocketClient.*\.o/$${SOCKET_CLIENT_O}/; \
s/^NetworkFunctionLocks.*\.o/$${NETWORK_FUNCTION_LOCKS_O}/; \
s/^Path.*\.o/$${PATH_O}/; \
s/^Directory.*\.o/$${DIRECTORY_O}/; \
s/^TypeIO.*\.o/$${TYPE_IO_O}/; \
s/^Time.*\.o/$${TIME_O}/; \
s/^Thread.*\.o/$${THREAD_O}/; \
s/^MutexLock.*\.o/$${MUTEX_LOCK_O}/; \
s/^BinarySemaphore.*\.o/$${BINARY_SEMAPHORE_O}/; \
s/^AppLog.*\.o/$${APP_LOG_O}/; \
s/^PrintLog.*\.o/$${PRINT_LOG_O}/; \
s/^FileLog.*\.o/$${FILE_LOG_O}/; \
s/^Log.*\.o/$${LOG_O}/; \
s/^PrintUtils.*\.o/$${PRINT_UTILS_O}/; \
s/^WebClient.*\.o/$${WEB_CLIENT_O}/; \
s/^URLUtils.*\.o/$${URL_UTILS_O}/; \
s/^MimeTyper.*\.o/$${MIME_TYPER_O}/; \
s/^StringBufferOutputStream.*\.o/$${STRING_BUFFER_OUTPUT_STREAM_O}/; \
s/^XMLUtils.*\.o/$${XML_UTILS_O}/; \
s/^HTMLUtils.*\.o/$${HTML_UTILS_O}/; \
s/^SettingsManager.*\.o/$${SETTINGS_MANAGER_O}/; \
s/^stringUtils.*\.o/$${STRING_UTILS_O}/; \
s/^sha1.*\.o/$${SHA1_O}/; \
s/^aiff.*\.o/$${AIFF_O}/; \
s/^MemoryTrack.*\.o/$${MEMORY_TRACK_O}/; \
s/^DebugMemory.*\.o/$${DEBUG_MEMORY_O}/; \
s/^HostCatcher.*\.o/$${HOST_CATCHER_O}/; \
s/^OutboundChannel.*\.o/$${OUTBOUND_CHANNEL_O}/; \
s/^DuplicateMessageDetector.*\.o/$${DUPLICATE_MESSAGE_DETECTOR_O}/; \
s/^protocolUtils.*\.o/$${PROTOCOL_UTILS_O}/; \
s/^MessagePerSecondLimiter.*\.o/$${MESSAGE_PER_SECOND_LIMITER_O}/; \
s/^encodingUtils.*\.o/$${ENCODING_UTILS_O}/; \
s/^WebServer.*\.o/$${WEB_SERVER_O }/; \
s/^RequestHandlingThread.*\.o/$${REQUEST_HANDLING_THREAD_O}/; \
s/^ThreadHandlingThread.*\.o/$${THREAD_HANDLING_THREAD_O}/; \
s/^ConnectionPermissionHandler.*\.o/$${CONNECTION_PERMISSION_HANDLER_O}/; \
s/^StopSignalThread.*\.o/$${STOP_SIGNAL_THREAD_O}/; \
s/^FinishedSignalThread.*\.o/$${FINISHED_SIGNAL_THREAD_O}/; \
s/^ScreenGL.*\.o/$${SCREEN_GL_O}/; \
'



MINOR_GEMS_DEPENDENCY_FILE = Makefile.minorGems_dependencies


# build the dependency file 

${MINOR_GEMS_DEPENDENCY_FILE}: ${MINOR_GEMS_SOURCE}
	rm -f ${MINOR_GEMS_DEPENDENCY_FILE}
	${COMPILE} -I${ROOT_PATH} -MM ${MINOR_GEMS_SOURCE} >> ${MINOR_GEMS_DEPENDENCY_FILE}.temp
	cat ${MINOR_GEMS_DEPENDENCY_FILE}.temp | ${MINOR_GEMS_SED_FIX_COMMAND} >> ${MINOR_GEMS_DEPENDENCY_FILE}
	rm -f ${MINOR_GEMS_DEPENDENCY_FILE}.temp

include ${MINOR_GEMS_DEPENDENCY_FILE}






