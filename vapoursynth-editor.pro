CONFIG += qt
CONFIG += console
QT += widgets
QT += network
TARGET = vsViewer
CONFIG(debug, debug|release) {
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
    contains(QMAKE_COMPILER, gcc) {
        DESTDIR = build/release-gcc
        OBJECTS_DIR = generated/obj-debug-gcc
    }
    contains(QMAKE_COMPILER, msvc) {
        DESTDIR = build/obj-release-msvc
        OBJECTS_DIR = generated/obj-debug-msvc
    }
    CONFIG += warn_off
    DEFINES += NDEBUG
    contains(QMAKE_COMPILER, gcc) {
        QMAKE_CXXFLAGS += -O2
        QMAKE_CXXFLAGS += -fexpensive-optimizations
        QMAKE_CXXFLAGS += -funit-at-a-time
    }
}
linux {
  INCLUDEPATH += /usr/local/include/vapoursynth
}
macx {
    INCLUDEPATH += /usr/local/include
    ICON = resources/vsViewer.icns
}
win32 {
    #INCLUDEPATH += 'C:/Program Files/VapourSynth/sdk/include/'
    INCLUDEPATH += 'I:/Hybrid/64bit/VapourSynth/sdk/include/'
    contains(QMAKE_HOST.arch, x86_64):message("x86_64 build")
    else {
        message("x86 build")
        contains(QMAKE_COMPILER, gcc):QMAKE_LFLAGS += -Wl,--large-addreress-aware
        contains(QMAKE_COMPILER, msvc):QMAKE_LFLAGS += /LARGEADDRESSAWAWARE
    }
}
contains(QMAKE_COMPILER, clang):QMAKE_CXXFLAGS += -stdlib=libc++
contains(QMAKE_COMPILER, gcc) {
    lessThan(QT_MAJOR_VERSION, 6) {
        QMAKE_CXXFLAGS += -std=c++11
    } else  {
      QMAKE_CXXFLAGS += -std=c++17
    }
    LIBS += -L$$[QT_INSTALL_LIBS]
} else{
  lessThan(QT_MAJOR_VERSION, 6) {
    CONFIG += c++11 # C++11 support
  } else {
    CONFIG += c++17 # C++17 support
    QMAKE_CXXFLAGS += /std:c++17
  }
}
S = $${DIR_SEPARATOR}
D = $$DESTDIR
D = $$replace(D, $$escape_expand(\\\\), $$S)
D = $$replace(D, /, $$S)
E = $$escape_expand(\n\t)
QMAKE_POST_LINK += $${QMAKE_COPY} \
    resources$${S}vsViewer.ico \
    $${D}$${S}vsViewer.ico \
    $${E}
QMAKE_POST_LINK += $${QMAKE_COPY} \
    resources$${S}vsViewer.svg \
    $${D}$${S}vsViewer.svg \
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
