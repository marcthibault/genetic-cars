SOURCES += \
    main.cpp

INCLUDEPATH += libs/Box2D

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../Box2D/Build/Box2D/release/ -lBox2D
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../Box2D/Build/Box2D/debug/ -lBox2D
else:unix: LIBS += -L$$PWD/../../../../../../../Box2D/Build/Box2D/ -lBox2D

INCLUDEPATH += $$PWD/../../../../../../../Box2D/Build/Box2D
DEPENDPATH += $$PWD/../../../../../../../Box2D/Build/Box2D

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../Box2D/Build/Box2D/release/libBox2D.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../Box2D/Build/Box2D/debug/libBox2D.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../Box2D/Build/Box2D/release/Box2D.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../Box2D/Build/Box2D/debug/Box2D.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../../Box2D/Build/Box2D/libBox2D.a
