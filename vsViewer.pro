CONFIG += qt

QT += widgets
QT += network


QT_VERSION_WARNING = "WARNING: Linking against Qt version lower than 5.6.1 is likely to cause CLI tools video encoding to crash due to I/O but in Qt."

win32 {
 equals(QT_MAJOR_VERSION, 5) {
  equals(QT_MINOR_VERSION, 6):lessThan(QT_PATCH_VERSION, 1)) {
   message($$QT_VERSION_WARNING)
  }
  lessThan(QT_MINOR_VERSION, 6) {
   message($$QT_VERSION_WARNING)
  }
 }
}

HOST_64_BIT = contains(QMAKE_HOST.arch, "x86_64")
TARGET_64_BIT = contains(QMAKE_TARGET.arch, "x86_64")
ARCHITECTURE_64_BIT = $$HOST_64_BIT | $$TARGET_64_BIT
TARGET = vsViewer

CONFIG(debug, debug|release) {

 contains(QMAKE_COMPILER, gcc) {
  if($$ARCHITECTURE_64_BIT) {
   DESTDIR = build/debug-64bit-gcc
   OBJECTS_DIR = generated/obj-debug-64bit-gcc
  } else {
   DESTDIR = build/debug-32bit-gcc
   TARGET = vsViewer-debug-32bit-gcc
   OBJECTS_DIR = generated/obj-debug-32bit-gcc
  }

  QMAKE_CXXFLAGS += -O0
  QMAKE_CXXFLAGS += -g
  QMAKE_CXXFLAGS += -ggdb3
 }

 contains(QMAKE_COMPILER, msvc) {
  if($$ARCHITECTURE_64_BIT) {
   DESTDIR = build/debug-64bit-msvc
   OBJECTS_DIR = generated/obj-debug-64bit-msvc
  } else {
   DESTDIR = build/debug-32bit-msvc
   OBJECTS_DIR = generated/obj-debug-32bit-msvc
  }
 }

} else {

 contains(QMAKE_COMPILER, gcc) {
  if($$ARCHITECTURE_64_BIT) {
   DESTDIR = build/release-64bit-gcc
   OBJECTS_DIR = generated/obj-release-64bit-gcc
  } else {
   DESTDIR = build/release-32bit-gcc
   OBJECTS_DIR = generated/obj-release-32bit-gcc
  }

  QMAKE_CXXFLAGS += -O2
  QMAKE_CXXFLAGS += -fexpensive-optimizations
  QMAKE_CXXFLAGS += -funit-at-a-time
 }

 macx {
  QMAKE_CXXFLAGS -= -fexpensive-optimizations
 }

 contains(QMAKE_COMPILER, msvc) {
  if($$ARCHITECTURE_64_BIT) {
   DESTDIR = build/release-64bit-msvc
  } else {
   DESTDIR = build/release-32bit-msvc
  }
 }

 DEFINES += NDEBUG

}

S = $${DIR_SEPARATOR}

D = $$DESTDIR
#D = $$replace(D, $$escape_expand(\\), $$S)
D = $$replace(D, /, $$S)

SC =
#SC = $$replace(SC, $$escape_expand(\\), $$S)
SC = $$replace(SC, /, $$S)

E = $$escape_expand(\n\t)

#QMAKE_POST_LINK += $${QMAKE_COPY} $${SC}$${S}resources$${S}vsViewer.ico $${D}$${S}vsViewer.ico $${E}
#QMAKE_POST_LINK += $${QMAKE_COPY} $${SC}$${S}resources$${S}vsViewer.svg $${D}$${S}vsViewer.svg $${E}
#QMAKE_POST_LINK += $${QMAKE_COPY} $${SC}$${S}README $${D}$${S}README $${E}
#QMAKE_POST_LINK += $${QMAKE_COPY} $${SC}$${S}LICENSE $${D}$${S}LICENSE $${E}

macx {
 INCLUDEPATH += /usr/local/include
 ICON = resources/vsViewer.icns
}

win32 {

lessThan(QT_MAJOR_VERSION, 6) {
  QT += winextras
} else {
  QMAKE_LFLAGS += -ENTRY:mainCRTStartup
}
 #INCLUDEPATH += 'C:/Program Files/VapourSynth/sdk/include/'
 INCLUDEPATH += 'F:/Hybrid/64bit/VapourSynth/sdk/include/'

 #DEPLOY_COMMAND = windeployqt
 #DEPLOY_TARGET = $$shell_quote($$shell_path($${D}/$${TARGET}.exe))
 #QMAKE_POST_LINK += $${DEPLOY_COMMAND} --no-translations $${DEPLOY_TARGET} $${E}

 if($$ARCHITECTURE_64_BIT) {
  message("x86_64 build")
 } else {
  message("x86 build")
  contains(QMAKE_COMPILER, gcc) {
   QMAKE_LFLAGS += -Wl,--large-address-aware
  }
  contains(QMAKE_COMPILER, msvc) {
   QMAKE_LFLAGS += /LARGEADDRESSAWARE
  }
 }
}

contains(QMAKE_COMPILER, clang) {
 QMAKE_CXXFLAGS += -stdlib=libc++
}

contains(QMAKE_COMPILER, gcc) {
 INCLUDEPATH += /usr/local/include/vapoursynth
 QMAKE_CXXFLAGS += -std=c++17
 QMAKE_CXXFLAGS += -Wall
 QMAKE_CXXFLAGS += -Wextra
 QMAKE_CXXFLAGS += -Wredundant-decls
 QMAKE_CXXFLAGS += -Wshadow
 #QMAKE_CXXFLAGS += -Weffc++
 QMAKE_CXXFLAGS += -pedantic

 LIBS += -L$$[QT_INSTALL_LIBS]
} else {
 CONFIG += c++17
}

TEMPLATE = app

RC_ICONS = resources/vsViewer.ico
QMAKE_TARGET_PRODUCT = 'VapourSynth Viewer'
QMAKE_TARGET_DESCRIPTION = 'VapourSynth Viewer based on Vapoursynth script editor'

#SUBDIRS

#MOC_DIR = generated/moc
#UI_DIR = generated/ui
#RCC_DIR = generated/rcc

#DEFINES

#TRANSLATIONS

RESOURCES = resources/vsViewer.qrc
FORMS += common-src/log/styled_log_view_settings_dialog.ui

FORMS += settings/settings_dialog.ui
FORMS += script_status_bar_widget/script_status_bar_widget.ui
FORMS += preview/preview_advanced_settings_dialog.ui
FORMS += preview/preview_dialog.ui
FORMS += frame_consumers/benchmark_dialog.ui
FORMS += frame_consumers/encode_dialog.ui
FORMS += script_templates/templates_dialog.ui
FORMS += main_window.ui

HEADERS +=  \
  ipc/LocalSocketIpcClient.h \
  ipc/LocalSocketIpcServer.h \
  common-src/helpers.h \
  common-src/ipc_defines.h \
  common-src/aligned_vector.h \
  common-src/chrono.h \
  common-src/settings/settings_definitions_core.h \
  common-src/settings/settings_definitions.h \
  common-src/settings/settings_manager_core.h \
  common-src/settings/settings_manager.h \
  common-src/log/styled_log_view_core.h \
  common-src/log/styled_log_view_structures.h \
  common-src/log/log_styles_model.h \
  common-src/log/styled_log_view_settings_dialog.h \
  common-src/log/styled_log_view.h \
  common-src/log/vs_editor_log_definitions.h \
  common-src/log/vs_editor_log.h \
  common-src/vapoursynth/vs_script_library.h \
  common-src/vapoursynth/vs_script_processor_structures.h \
  common-src/vapoursynth/vapoursynth_script_processor.h \
  common-src/frame_header_writers/frame_header_writer.h \
  common-src/frame_header_writers/frame_header_writer_null.h \
  common-src/frame_header_writers/frame_header_writer_y4m.h \
  common-src/jobs/job.h \
  common-src/jobs/job_variables.h \
  common-src/timeline_slider/timeline_slider.h \
  common-src/libp2p/p2p.h \
  common-src/libp2p/p2p_api.h \
  common-src/libp2p/simd/cpuinfo_x86.h \
  common-src/libp2p/simd/p2p_simd.h \
  settings/actions_hotkey_edit_model.h \
  settings/clearable_key_sequence_editor.h \
  settings/item_delegate_for_hotkey.h \
  settings/theme_elements_model.h \
  settings/settings_dialog.h \
  script_status_bar_widget/script_status_bar_widget.h \
  preview/scroll_navigator.h \
  preview/preview_area.h \
  preview/preview_advanced_settings_dialog.h \
  preview/preview_dialog.h \
  script_editor/number_matcher.h \
  script_editor/syntax_highlighter.h \
  script_editor/script_completer_model.h \
  script_editor/script_completer.h \
  script_editor/script_editor.h \
  vapoursynth/vs_plugin_data.h \
  vapoursynth/vapoursynth_plugins_manager.h \
  vapoursynth/vs_script_processor_dialog.h \
  job_server_watcher_socket.h \
  frame_consumers/benchmark_dialog.h \
  frame_consumers/encode_dialog.h \
  script_templates/drop_file_category_model.h \
  script_templates/templates_dialog.h \
  main_window.h \
  common-src/aligned_vector.h \
  common-src/chrono.h \
  common-src/frame_header_writers/frame_header_writer.h \
  common-src/frame_header_writers/frame_header_writer_null.h \
  common-src/frame_header_writers/frame_header_writer_y4m.h \
  common-src/helpers.h \
  common-src/jobs/job.h \
  common-src/jobs/job_variables.h \
  common-src/libp2p/p2p.h \
  common-src/libp2p/p2p_api.h \
  common-src/libp2p/simd/cpuinfo_x86.h \
  common-src/libp2p/simd/p2p_simd.h \
  common-src/log/log_styles_model.h \
  common-src/log/styled_log_view.h \
  common-src/log/styled_log_view_core.h \
  common-src/log/styled_log_view_settings_dialog.h \
  common-src/log/styled_log_view_structures.h \
  common-src/log/vs_editor_log.h \
  common-src/log/vs_editor_log_definitions.h \
  common-src/settings/settings_definitions.h \
  common-src/settings/settings_definitions_core.h \
  common-src/settings/settings_manager.h \
  common-src/settings/settings_manager_core.h \
  common-src/timeline_slider/timeline_slider.h \
  common-src/vapoursynth/vapoursynth_script_processor.h \
  common-src/vapoursynth/vs_pack_rgb.h \
  common-src/vapoursynth/vs_script_library.h \
  common-src/vapoursynth/vs_script_processor_structures.h \
  frame_consumers/benchmark_dialog.h \
  frame_consumers/encode_dialog.h \
  ipc/LocalSocketIpcClient.h \
  ipc/LocalSocketIpcServer.h \
  job_server_watcher_socket.h \
  main_window.h \
  preview/preview_advanced_settings_dialog.h \
  preview/preview_area.h \
  preview/preview_dialog.h \
  preview/scroll_navigator.h \
  script_editor/number_matcher.h \
  script_editor/script_completer.h \
  script_editor/script_completer_model.h \
  script_editor/script_editor.h \
  script_editor/syntax_highlighter.h \
  script_status_bar_widget/script_status_bar_widget.h \
  script_templates/drop_file_category_model.h \
  script_templates/templates_dialog.h \
  settings/actions_hotkey_edit_model.h \
  settings/clearable_key_sequence_editor.h \
  settings/item_delegate_for_hotkey.h \
  settings/settings_dialog.h \
  settings/theme_elements_model.h \
  vapoursynth/vapoursynth_plugins_manager.h \
  vapoursynth/vs_plugin_data.h \
  vapoursynth/vs_script_processor_dialog.h

SOURCES +=  \
  common-src/frame_header_writers/frame_header_writer.cpp \
  common-src/frame_header_writers/frame_header_writer_null.cpp \
  common-src/frame_header_writers/frame_header_writer_y4m.cpp \
  common-src/helpers.cpp \
  common-src/jobs/job.cpp \
  common-src/jobs/job_variables.cpp \
  common-src/log/log_styles_model.cpp \
  common-src/log/styled_log_view.cpp \
  common-src/log/styled_log_view_core.cpp \
  common-src/log/styled_log_view_settings_dialog.cpp \
  common-src/log/styled_log_view_structures.cpp \
  common-src/log/vs_editor_log.cpp \
  common-src/log/vs_editor_log_definitions.cpp \
  common-src/settings/settings_definitions.cpp \
  common-src/settings/settings_definitions_core.cpp \
  common-src/settings/settings_manager.cpp \
  common-src/settings/settings_manager_core.cpp \
  common-src/timeline_slider/timeline_slider.cpp \
  common-src/vapoursynth/vs_pack_rgb.cpp \
  common-src/vapoursynth/vs_gray_frame_prop.cpp \
  common-src/vapoursynth/vapoursynth_script_processor.cpp \
  common-src/vapoursynth/vs_script_library.cpp \
  common-src/vapoursynth/vs_script_processor_structures.cpp \
  frame_consumers/benchmark_dialog.cpp \
  frame_consumers/encode_dialog.cpp \
  ipc/LocalSocketIpcClient.cpp \
  ipc/LocalSocketIpcServer.cpp \
  job_server_watcher_socket.cpp \
  main.cpp \
  main_window.cpp \
  preview/preview_advanced_settings_dialog.cpp \
  preview/preview_area.cpp \
  preview/preview_dialog.cpp \
  preview/scroll_navigator.cpp \
  script_editor/number_matcher.cpp \
  script_editor/script_completer.cpp \
  script_editor/script_completer_model.cpp \
  script_editor/script_editor.cpp \
  script_editor/syntax_highlighter.cpp \
  script_status_bar_widget/script_status_bar_widget.cpp \
  script_templates/drop_file_category_model.cpp \
  script_templates/templates_dialog.cpp \
  settings/actions_hotkey_edit_model.cpp \
  settings/clearable_key_sequence_editor.cpp \
  settings/item_delegate_for_hotkey.cpp \
  settings/settings_dialog.cpp \
  settings/theme_elements_model.cpp \
  vapoursynth/vapoursynth_plugins_manager.cpp \
  vapoursynth/vs_plugin_data.cpp \
  vapoursynth/vs_script_processor_dialog.cpp \
  common-src/vapoursynth/vs_gray_frame_prop.h

# libp2p
# libp2p
SOURCES_P2P += common-src/libp2p/p2p_api.cpp
SOURCES_P2P += common-src/libp2p/v210.cpp
SOURCES_P2P += common-src/libp2p/simd/cpuinfo_x86.cpp
SOURCES_P2P += common-src/libp2p/simd/p2p_simd.cpp
SOURCES_P2P_SSE41 += common-src/libp2p/simd/p2p_sse41.cpp

p2p.name = p2p
p2p.input = SOURCES_P2P
p2p.dependency_type = TYPE_C
p2p.variable_out = OBJECTS
p2p.output = ${QMAKE_VAR_OBJECTS_DIR}${QMAKE_FILE_IN_BASE}$${first(QMAKE_EXT_OBJ)}
p2p.commands = $${QMAKE_CXX} $(CXXFLAGS) -DP2P_SIMD $(INCPATH) -c ${QMAKE_FILE_IN}
contains(QMAKE_COMPILER, msvc) {
 p2p.commands += -Fo${QMAKE_FILE_OUT}
} else {
 p2p.commands += -o ${QMAKE_FILE_OUT}
 p2p.commands += -std=c++14
 p2p.commands += -Wno-missing-field-initializers
}
macx {
 p2p.commands += -Wno-gnu
}
QMAKE_EXTRA_COMPILERS += p2p

p2p_sse41.name = p2p_sse41
p2p_sse41.input = SOURCES_P2P_SSE41
p2p_sse41.dependency_type = TYPE_C
p2p_sse41.variable_out = OBJECTS
p2p_sse41.output = ${QMAKE_VAR_OBJECTS_DIR}${QMAKE_FILE_IN_BASE}$${first(QMAKE_EXT_OBJ)}
p2p_sse41.commands = $${QMAKE_CXX} $(CXXFLAGS) -DP2P_SIMD $(INCPATH) -c ${QMAKE_FILE_IN}
contains(QMAKE_COMPILER, msvc) {
 p2p_sse41.commands += -Fo${QMAKE_FILE_OUT}
} else {
 p2p_sse41.commands += -msse4.1
 p2p_sse41.commands += -o ${QMAKE_FILE_OUT}
 p2p_sse41.commands += -std=c++14
 p2p_sse41.commands += -Wno-missing-field-initializers
}
macx {
 p2p_sse41.commands += -Wno-gnu
}
QMAKE_EXTRA_COMPILERS += p2p_sse41
#include(common.pri)
#include(local_quirks.pri)
