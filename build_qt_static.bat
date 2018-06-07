set PATH=%PATH%;C:\devel\qt5.5.0-static\bin
qmake RELEASE=1 USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1 Thunderstake.pro
make -j8 -f Makefile.Release
pause
build_qt_static.bat