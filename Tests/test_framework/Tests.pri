SOURCE_PATH = ../../prod_epg
TEST_NAME=$${SUT_CLASS_NAME}Tests
TEST_FRAMEWORK_PATH = ../test_framework
BIN_PATH=../../../build-tests-bin
BUILD_PATH=../../../build-tests

QMAKE_CXXFLAGS += -std=c++11
QT       += testlib
QT       -= gui
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES+=$$TEST_FRAMEWORK_PATH/gmock-gtest-all.cc
SOURCES+=$${TEST_NAME}.cpp

INCLUDEPATH+=$$TEST_FRAMEWORK_PATH
INCLUDEPATH+=$$SOURCE_PATH/$$SUT_PATH
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/api_providers
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/data_model
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/data_model/data_types
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/data_model/interfaces
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/api_providers
INCLUDEPATH+=$$SOURCE_PATH/core_services/src/search_model

DESTDIR=$$BIN_PATH
OBJECTS_DIR=$${BUILD_PATH}
MOC_DIR=$${BUILD_PATH}
RCC_DIR=$${BUILD_PATH}

TARGET = $$TEST_NAME

SOURCES+=$$SOURCE_PATH/$$SUT_PATH/$${SUT_CLASS_NAME}.cpp
HEADERS+=$$SOURCE_PATH/$$SUT_PATH/$${SUT_CLASS_NAME}.h

message($$SOURCES)
message($$HEADERS)
