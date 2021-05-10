dir "C:\Program Files\"
dir "C:\Program Files (x86)\"

mkdir deps -ErrorAction SilentlyContinue
cd deps
$DEPS_DIR=pwd
try {
    Get-Command cmake
} catch {
    if (! (Test-Path cmake.zip)) {
        Invoke-WebRequest https://github.com/Kitware/CMake/releases/download/v3.20.2/cmake-3.20.2-windows-x86_64.zip -OutFile cmake.zip
    }
    if (! (Test-Path cmake)) {
        Expand-Archive -Path cmake.zip
    }
}
$NEED_RECOMPILE=$false
if (Test-Path $DEPS_DIR\opencv) {
    cd opencv
    git remote update
    if((git rev-parse HEAD) -ne (git rev-parse "@{u}")) {
        $NEED_RECOMPILE=$true
    }
    git pull --rebase
    cd ..
} else {
    git clone https://github.com/opencv/opencv.git
}
if (Test-Path $DEPS_DIR\opencv_contrib ) {
    cd opencv_contrib
    git remote update
    if((git rev-parse HEAD) -ne (git rev-parse "@{u}")) {
        $NEED_RECOMPILE=$true
    }
    git pull --rebase
    cd ..
} else {
    $NEED_RECOMPILE=$true
    git clone https://github.com/opencv/opencv_contrib.git
}
if ($NEED_RECOMPILE -or (!(Test-Path build_opencv)) -or (!(Test-Path install))) {
    mkdir build_opencv -ErrorAction SilentlyContinue
    cd build_opencv
    ..\cmake\cmake-3.20.2-windows-x86_64\bin\cmake -DBUILD_PERF_TESTS:BOOL=OFF -DBUILD_TESTS:BOOL=OFF -DBUILD_DOCS:BOOL=OFF  -DWITH_CUDA:BOOL=OFF -DBUILD_EXAMPLES:BOOL=OFF -DINSTALL_CREATE_DISTRIB=ON -DOPENCV_EXTRA_MODULES_PATH="$DEPS_DIR\opencv_contrib\modules" -DCMAKE_INSTALL_PREFIX="$DEPS_DIR\install\opencv" "$DEPS_DIR\opencv"
    ..\cmake\cmake-3.20.2-windows-x86_64\bin\cmake --build .  --config debug
    ..\cmake\cmake-3.20.2-windows-x86_64\bin\cmake --build .  --config release
    ..\cmake\cmake-3.20.2-windows-x86_64\bin\cmake --build .  --target install --config release
    ..\cmake\cmake-3.20.2-windows-x86_64\bin\cmake --build .  --target install --config debug
    cd ..
}
cd ..
tree
.\deps\cmake\cmake-3.20.2-windows-x86_64\bin\cmake --help