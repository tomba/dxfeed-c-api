QT -= core gui

TEMPLATE = lib
CONFIG += c++20 staticlib
CONFIG += create_prl

INCLUDEPATH += include

unix:QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter -Wno-sign-compare -Wno-type-limits -Wno-implicit-fallthrough -Wno-old-style-declaration
unix:QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-sign-compare

SOURCES += \
	src/BinaryQTPComposer.cpp \
	src/BinaryQTPParser.cpp \
	src/BufferedInput.c \
	src/BufferedIOCommon.c \
	src/BufferedOutput.c \
	src/Candle.c \
	src/ClientMessageProcessor.c \
	src/Configuration.cpp \
	src/ConfigurationDeserializer.c \
	src/ConnectionContextData.c \
	src/Connection.cpp \
	src/DataStructures.c \
	src/Decimal.c \
	src/DXAddressParser.c \
	src/DXAlgorithms.c \
	src/DXErrorCodes.c \
	src/DXErrorHandling.c \
	src/DXFeed.c \
	src/DXMemory.c \
	src/DXNetwork.c \
	src/DXPMessageData.c \
	src/DXProperties.c \
	src/DXSockets.c \
	src/DXThreads.c \
	src/EventData.c \
	src/EventManager.c \
	src/EventSubscription.cpp \
	src/HeartbeatPayload.cpp \
	src/Linux.c \
	src/Logger.c \
	src/ObjectArray.c \
	src/PriceLevelBook.c \
        src/PriceLevelBookNG.cpp \
        src/RecordBuffers.c \
	src/RecordFieldSetters.c \
	src/RecordTranscoder.c \
	src/RegionalBook.c \
	src/ServerMessageProcessor.c \
	src/Snapshot.c \
	src/SymbolCodec.c \
	src/TaskQueue.c \
	src/Version.c \
	src/WideDecimal.cpp

HEADERS += \
	src/BinaryQTPComposer.hpp \
	src/BinaryQTPParser.hpp \
	src/BufferedInput.h \
	src/BufferedIOCommon.h \
	src/BufferedOutput.h \
	src/Candle.h \
	src/ClientMessageProcessor.h \
	src/ConfigurationDeserializer.h \
	src/Configuration.h \
	src/Configuration.hpp \
	src/ConnectionContextData.h \
	src/Connection.h \
	src/Connection.hpp \
	src/DataStructures.h \
	src/Decimal.h \
	src/DXAddressParser.h \
	src/DXAlgorithms.h \
	src/DXErrorHandling.h \
	src/DXMemory.h \
	src/DXNetwork.h \
	src/DXPMessageData.h \
	src/DXProperties.h \
	src/DXSockets.h \
	src/DXThreads.h \
	src/EventManager.h \
	src/EventSubscription.h \
	src/EventSubscription.hpp \
	src/HeartbeatPayload.hpp \
	src/Logger.h \
	src/ObjectArray.h \
	src/PriceLevelBook.h \
        src/PriceLevelBookNG.h \
        src/PrimitiveTypes.h \
	src/RecordBuffers.h \
	src/RecordFieldSetters.h \
	src/RecordTranscoder.h \
	src/RegionalBook.h \
	src/resource.h \
	src/ServerMessageProcessor.h \
	src/Snapshot.h \
	src/SymbolCodec.h \
	src/TaskQueue.h \
	src/TimeMarkUtil.hpp \
	src/Version.h \
	src/WideDecimal.h

HEADERS += \
	include/DXTypes.h \
	include/EventData.h \
	include/RecordData.h \
	include/DXErrorCodes.h \
	include/DXFeed.h

INCLUDEPATH += thirdparty/toml11
INCLUDEPATH += thirdparty/boost-1_75
