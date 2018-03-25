rd /q /s .\build
mkdir build
cd build

cmake -G"Visual Studio 15 2017 Win64" -DINCLUDE_DIR=E:\SLAM_class\project\3rdparty\include -DLIBRARIES=E:\SLAM_class\project\3rdparty\lib\ceres.lib;E:\SLAM_class\project\3rdparty\lib\libglog_static.lib ..

cmd
 