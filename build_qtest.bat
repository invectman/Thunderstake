set PATH=%PATH%;C:\devel\qt5.9.2-static\bin
cd "%cd%"
qmake USE_UPNP=1 USE_IPV6=0 BITCOIN_QT_TEST=1 -o Makefile.test Thunderstake.pro
make -f Makefile.test -j3
release\Thunderstake-qt_test.exe
.\
pause
build_qtest.bat