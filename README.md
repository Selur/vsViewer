# vsViewer r19.4.0

A preview and viewer for [VapourSynth](https://www.vapoursynth.com/) scripts, based on
VapourSynth Editor. It is the script preview used by [Hybrid](https://www.selur.de/),
and it also runs as a stand-alone editor and viewer.

## Features

- Script editor with syntax highlighting, completion and templates
- Frame preview with zoom (no zoom, fixed ratio, fit to window), crop panel and scroll navigator
- Playback with audio: the first audio output plays along with the video output
- Color picker: source values (Y/U/V, R/G/B or gray) and displayed R/G/B under the cursor
- Frame properties, snapshots and frame to clipboard
- Windows: frames are drawn and scaled through Direct3D 11; 10 bit output on HDR displays
  (Advanced settings: Auto / On / Off)
- Benchmark and encode dialogs (pipe y4m or raw frames to an encoder)

## Requirements

- VapourSynth R73 or newer (API 4); the library is loaded at runtime
- The Windows and macOS packages include Qt. The Linux package uses the system Qt 6
  with Qt Multimedia.

vsViewer looks for the VSScript library in this order (the library paths from the
settings move to the front when "prefer the library paths from the list" is on):

1. `python -c "import vapoursynth; print(vapoursynth.get_vsscript())"` (Linux/macOS: `python3`)
2. the `VSSCRIPT_PATH` environment variable (full path of the library)
3. the library paths in the settings
4. Windows: the registry entry `HKLM\SOFTWARE\VapourSynth\VSScriptDLL`
5. the system library path

## Command line

```
vsViewer [script.vpy]
vsViewer --version
```

Options for a calling application; every option takes a value:

| Option | Meaning |
| --- | --- |
| `--preview-only <script.vpy>` | open the script in the preview only, main window hidden; cropping starts off |
| `--input <script.vpy>` | open the script in the preview only, main window hidden |
| `--listen <id>` | receive commands on the local socket `<id>VSE` |
| `--listen-to <name>` | send messages to the local socket `<id><name>` (needs `--listen`) |
| `--crop <on\|off>#<left>#<right>#<top>#<bottom>` | crop panel state and values |

## Downloads

GitHub Actions builds Windows x64, Linux x86_64 and macOS arm64 packages on every push
(workflow artifacts). Tagged versions (`r*`) are published on the
[releases page](https://github.com/Selur/vsViewer/releases).

## Building

Needs Qt 6 (Widgets, Network, Multimedia; on Windows also the GUI private headers) with
qmake, a C++17 compiler and the VapourSynth headers (the `include` folder of the
VapourSynth sources).

```
qmake CONFIG+=release VAPOURSYNTH_INCLUDE=/path/to/vapoursynth/include vsViewer.pro
make
```

On Windows with MSVC use `nmake -f Makefile.Release` or jom instead of `make`. The binary
ends up in `build/release-64bit-<compiler>/`. Without `VAPOURSYNTH_INCLUDE` the project
file uses a fixed path per system (see `vsViewer.pro`). `.github/workflows/build.yml`
shows the complete build and packaging on all three systems.

## Credits and license

VapourSynth Editor by Aleksey [Mystery Keeper] Lyashin (mystkeeper@gmail.com,
<http://mysterykeeper.ru>), modified by YomikoR and Selur.

This software is free and distributed under the MIT license, see [LICENSE](LICENSE).

- Qt 6 framework by The Qt Company, distributed under the LGPL license, <https://qt.io/>
- Silk icons v1.3 by Mark James, distributed under the Creative Commons Attribution 2.5
  License, <http://www.famfamfam.com/lab/icons/silk/>
- FatCow free icons, distributed under the Creative Commons Attribution 3.0 License,
  <http://www.fatcow.com/free-icons>
