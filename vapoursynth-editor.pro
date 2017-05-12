CONFIG += qt
QT += widgets
QT += network
CONFIG(debug, debug|release) {
    contains(QMAKE_HOST.arch, x86_64) {
        contains(QMAKE_COMPILER, gcc) {
            DESTDIR = build/debug-64bit-gcc
            TARGET = vsedit-debug-64bit-gcc
            OBJECTS_DIR = generated/obj-debug-64bit-gcc
        }
        contains(QMAKE_COMPILER, msvc) {
            DESTDIR = build/debug-64bit-msvc
            TARGET = vsedit-debug-64bit-msvc
            OBJECTS_DIR = generated/obj-debug-64bit-msvc
        }
    }
    else {
        contains(QMAKE_COMPILER, gcc) {
            DESTDIR = build/debug-32bit-gcc
            TARGET = vsedit-debug-32bit-gcc
            OBJECTS_DIR = generated/obj-debug-32bit-gcc
        }
        contains(QMAKE_COMPILER, msvc) {
            DESTDIR = build/debug-32bit-msvc
            TARGET = vsedit-debug-32bit-msvc
            OBJECTS_DIR = generated/obj-debug-32bit-msvc
        }
    }
    contains(QMAKE_COMPILER, gcc) {
        QMAKE_CXXFLAGS += -O0
        QMAKE_CXXFLAGS += -g
        QMAKE_CXXFLAGS += -ggdb3
        QMAKE_CXXFLAGS += -Wall
        QMAKE_CXXFLAGS += -Wextra
        QMAKE_CXXFLAGS += -Wredundant-decls
        QMAKE_CXXFLAGS += -Wshadow

        # QMAKE_CXXFLAGS += -Weffc++
        QMAKE_CXXFLAGS += -pedantic
    }
}
else {
    CONFIG += warn_off
    contains(QMAKE_HOST.arch, x86_64) {
        contains(QMAKE_COMPILER, gcc) {
            DESTDIR = build/release-64bit-gcc
            TARGET = vsedit
            OBJECTS_DIR = generated/obj-release-64bit-gcc
        }
        contains(QMAKE_COMPILER, msvc) {
            DESTDIR = build/release-64bit-msvc
            TARGET = vsedit
            OBJECTS_DIR = generated/obj-release-64bit-msvc
        }
    }
    else {
        contains(QMAKE_COMPILER, gcc) {
            DESTDIR = build/release-32bit-gcc
            TARGET = vsedit-32bit
            OBJECTS_DIR = generated/obj-release-32bit-gcc
        }
        contains(QMAKE_COMPILER, msvc) {
            DESTDIR = build/release-32bit-msvc
            TARGET = vsedit-32bit
            OBJECTS_DIR = generated/obj-release-32bit-msvc
        }
    }
    DEFINES += NDEBUG
    contains(QMAKE_COMPILER, gcc) {
        QMAKE_CXXFLAGS += -O2
        QMAKE_CXXFLAGS += -fexpensive-optimizations
        QMAKE_CXXFLAGS += -funit-at-a-time
    }
}
macx {
    INCLUDEPATH += /usr/local/include
    ICON = resources/vsedit.icns
}
win32 {
    INCLUDEPATH += 'C:/Program Files (x86)/VapourSynth/sdk/include/'
    contains(QMAKE_HOST.arch, x86_64):message("x86_64 build")
    else {
        message("x86 build")
        contains(QMAKE_COMPILER, gcc):QMAKE_LFLAGS += -Wl,--large-address-aware
        contains(QMAKE_COMPILER, msvc):QMAKE_LFLAGS += /LARGEADDRESSAWARE
    }
}
contains(QMAKE_COMPILER, clang):QMAKE_CXXFLAGS += -stdlib=libc++
contains(QMAKE_COMPILER, gcc) {
    QMAKE_CXXFLAGS += -std=c++11
    LIBS += -L$$[QT_INSTALL_LIBS]
}
else:CONFIG += c++11
S = $${DIR_SEPARATOR}
D = $$DESTDIR
D = $$replace(D, $$escape_expand(\\), $$S)
D = $$replace(D, /, $$S)
E = $$escape_expand(\n\t)
QMAKE_POST_LINK += $${QMAKE_COPY} \
    resources$${S}vsedit.ico \
    $${D}$${S}vsedit.ico \
    $${E}
QMAKE_POST_LINK += $${QMAKE_COPY} \
    resources$${S}vsedit.svg \
    $${D}$${S}vsedit.svg \
    $${E}
QMAKE_POST_LINK += $${QMAKE_COPY} \
    README.md \
    $${D}$${S}README.md \
    $${E}
QMAKE_POST_LINK += $${QMAKE_COPY} \
    LICENSE \
    $${D}$${S}LICENSE \
    $${E}
#QMAKE_POST_LINK += $${QMAKE_COPY} \
#    CHANGELOG \
#    $${D}$${S}CHANGELOG \
#    $${E}
TEMPLATE = app
RC_FILE = resources/windowsresources.rc

# SUBDIRS
MOC_DIR = generated/moc
UI_DIR = generated/ui
RCC_DIR = generated/rcc

# DEFINES
# TRANSLATIONS
RESOURCES = resources/resources.qrc
FORMS += mainwindow.ui \
    preview/preview_advanced_settings_dialog.ui \
    preview/previewdialog.ui \
    settings/settingsdialog.ui
HEADERS += mainwindow.h \
    common/aligned_vector.h \
    common/helpers.h \
    ipc/LocalSocketIpcClient.h \
    ipc/LocalSocketIpcServer.h \
    preview/preview_advanced_settings_dialog.h \
    preview/previewarea.h \
    preview/previewdialog.h \
    preview/scrollnavigator.h \
    preview/timelineslider.h \
    scripteditor/numbermatcher.h \
    scripteditor/scriptcompleter.h \
    scripteditor/scriptcompletermodel.h \
    scripteditor/scripteditor.h \
    scripteditor/syntaxhighlighter.h \
    settings/actionshotkeyeditmodel.h \
    settings/itemdelegateforhotkey.h \
    settings/settingsdialog.h \
    settings/settingsmanager.h \
    settings/theme_elements_model.h \
    vapoursynth/vapoursynthpluginsmanager.h \
    vapoursynth/vapoursynthscriptprocessor.h \
    vapoursynth/vsplugindata.h \
    common/helpers.h
SOURCES += main.cpp \
    mainwindow.cpp \
    common/helpers.cpp \
    ipc/LocalSocketIpcClient.cpp \
    ipc/LocalSocketIpcServer.cpp \
    preview/preview_advanced_settings_dialog.cpp \
    preview/previewarea.cpp \
    preview/previewdialog.cpp \
    preview/scrollnavigator.cpp \
    preview/timelineslider.cpp \
    scripteditor/numbermatcher.cpp \
    scripteditor/scriptcompleter.cpp \
    scripteditor/scriptcompletermodel.cpp \
    scripteditor/scripteditor.cpp \
    scripteditor/syntaxhighlighter.cpp \
    settings/actionshotkeyeditmodel.cpp \
    settings/itemdelegateforhotkey.cpp \
    settings/settingsdialog.cpp \
    settings/settingsmanager.cpp \
    settings/theme_elements_model.cpp \
    vapoursynth/vapoursynthpluginsmanager.cpp \
    vapoursynth/vapoursynthscriptprocessor.cpp \
    vapoursynth/vsplugindata.cpp
